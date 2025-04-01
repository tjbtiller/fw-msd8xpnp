BOARDINC += $(BOARD_DIR)/generated/controllers/generated

BOARDCPPSRC =  $(BOARD_DIR)/board_configuration.cpp \
    $(BOARD_DIR)/default_tune.cpp \



# defines SHORT_BOARD_NAME
include $(BOARD_DIR)/meta-info.env

ifeq ($(PROJECT_CPU),ARCH_STM32F4)
  IS_STM32F429 = yes
endif

# see also openblt/board.mk STATUS_LED
DDEFS += -DLED_CRITICAL_ERROR_BRAIN_PIN=Gpio::E3
DDEFS += -DFIRMWARE_ID=\"msd8xpnp\"
DDEFS += $(VAR_DEF_ENGINE_TYPE)


DDEFS += -DEFI_HD_ACR=TRUE
DDEFS += -DEFI_MAX_31855=TRUE
DDEFS += -DSTM32_SPI_USE_SPI5=TRUE

DDEFS += -DBOOT_COM_RS232_RX_MAX_DATA=120
DDEFS += -DOPEN_BLT_TEST_COMMAND=1

# let's start asap
DDEFS += -DBOOT_BACKDOOR_ENTRY_TIMEOUT_MS=0

# Any MSD8xPnP-based adapter boards with discrete-VR decoder are controlled via a 5v ignition output
DDEFS += -DVR_SUPPLY_VOLTAGE=5

# This stuff doesn't work on H7 yet
ifneq ($(PROJECT_CPU),ARCH_STM32H7)
	DDEFS += -DSTM32_ADC_USE_ADC3=TRUE
	DDEFS += -DEFI_SOFTWARE_KNOCK=TRUE
endif

# serial ports only on F4
ifeq ($(PROJECT_CPU),ARCH_STM32F4)
	# Hardware serial port on UART 2 -> PD5/PD6
	DDEFS += -DSTM32_UART_USE_USART2=TRUE
	DDEFS += -DTS_PRIMARY_UxART_PORT=UARTD2
	DDEFS += -DEFI_CONSOLE_TX_BRAIN_PIN=Gpio::D5 -DEFI_CONSOLE_RX_BRAIN_PIN=Gpio::D6
endif

# CAND1
DDEFS += -DBOOT_COM_CAN_CHANNEL_INDEX=0
DDEFS += -DOPENBLT_CAN_RX_PORT=GPIOD
DDEFS += -DOPENBLT_CAN_RX_PIN=0
DDEFS += -DOPENBLT_CAN_TX_PORT=GPIOD
DDEFS += -DOPENBLT_CAN_TX_PIN=1

# We are running on MSD8xPnP hardware!
DDEFS += -DHW_MSD8xPnP=1

ifeq ($(PROJECT_CPU),ARCH_STM32F7)
  # todo: KNOCK_SPECTROGRAM to use big_buffer
	DDEFS += -DKNOCK_SPECTROGRAM=TRUE
	DDEFS += -DLUA_RX_MAX_FILTER_COUNT=96
	DDEFS += -DSTATIC_BOARD_ID=STATIC_BOARD_ID_MSD8xPnP_F7

  DDEFS += -DLUA_USER_HEAP=150000

	ifeq ($(EFI_LUA_LOOKUP),)
    EFI_LUA_LOOKUP = TRUE
  endif
  DDEFS += -DEFI_LUA_LOOKUP=$(EFI_LUA_LOOKUP)

	# note #define EFI_EMBED_INI_MSD FALSE in F7 features
	ifeq ($(DEBUG_LEVEL_OPT),)
		DEBUG_LEVEL_OPT = -Os -ggdb -g
	endif
else ifeq ($(PROJECT_CPU),ARCH_STM32F4)
	DDEFS += -DSTATIC_BOARD_ID=STATIC_BOARD_ID_MSD8xPnP_F4
	DDEFS += -DRAM_UNUSED_SIZE=100
	# todo: https://github.com/rusefi/rusefi/pull/7505
	# you would think that removal of below like would reduce flash usage but somehow it increased it somehow?!
	DDEFS += -DKNOCK_SPECTROGRAM=TRUE
else ifeq ($(PROJECT_CPU),ARCH_STM32H7)
	DDEFS += -DSTATIC_BOARD_ID=STATIC_BOARD_ID_MSD8xPnP_H7
else
$(error Unsupported PROJECT_CPU [$(PROJECT_CPU)])
endif
