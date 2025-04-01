/**
 * @file boards/MSD8XPNP/board_configuration.cpp
 *
 * @brief Configuration defaults for the MSD8XPNP board
 *
 * @author Tyler Browning, (c) 2024
 */

#include "pch.h"
#include "defaults.h"

#define MSD8XPNP_DEFAULT_AT_PULLUP 2700

// PE3 is error LED, configured in board.mk
Gpio getCommsLedPin() {
	return Gpio::E4;
}

Gpio getRunningLedPin() {
	return Gpio::E5;
}

Gpio getWarningLedPin() {
	return Gpio::E6;
}

static void setupVbatt() {
	// 5.6k high side/10k low side = 1.56 ratio divider
	engineConfiguration->analogInputDividerCoefficient = 1.56f;

	// 82k high side/10k low side = 9.2
	engineConfiguration->vbattDividerCoeff = (92.0f / 10.0f);

	// Battery sense on PA7
	engineConfiguration->vbattAdcChannel = EFI_ADC_7;

	engineConfiguration->adcVcc = 3.3f;
}

static void setupSdCard() {
	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->sdCardCsPin = Gpio::D2;

	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->spi3sckPin = Gpio::C10;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3mosiPin = Gpio::C12;

	engineConfiguration->is_enabled_spi_5 = true;
	engineConfiguration->spi5sckPin = Gpio::F7;
	engineConfiguration->spi5misoPin = Gpio::F8;
	engineConfiguration->spi5mosiPin = Gpio::F9;
}

void setBoardConfigOverrides() {
	setupSdCard();
	setupVbatt();

	engineConfiguration->clt.config.bias_resistor = MSD8XPNP_DEFAULT_AT_PULLUP;
	engineConfiguration->iat.config.bias_resistor = MSD8XPNP_DEFAULT_AT_PULLUP;

	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;

#if defined(STM32F4) || defined(STM32F7)
	engineConfiguration->can2RxPin = Gpio::B12;
	engineConfiguration->can2TxPin = Gpio::B13;
#endif

	engineConfiguration->lps25BaroSensorScl = Gpio::B10;
	engineConfiguration->lps25BaroSensorSda = Gpio::B11;
}

/**
 * @brief   Board-specific configuration defaults.
 *
 * See also setDefaultEngineConfiguration
 *

 */

void boardPrepareForStop() {
	// Wake on the CAN RX pin
	palEnableLineEvent(PAL_LINE(GPIOD, 0), PAL_EVENT_MODE_RISING_EDGE);
}

//static Gpio MSD8XPNP_N54_OUTPUTS[] = {
//  Gpio::MSD8XPNP_LS_1, // inj 1
//  Gpio::MSD8XPNP_LS_2, // inj 2
//  Gpio::MSD8XPNP_LS_3, // inj 3
//  Gpio::MSD8XPNP_LS_4, // inj 4
//  Gpio::MSD8XPNP_LS_5, // inj 5
//  Gpio::MSD8XPNP_LS_6, // inj 6
//  Gpio::MSD8XPNP_LS_14, // starter control or aux output
//  Gpio::MSD8XPNP_LS_15, // radiator fan relay output white

//  Gpio::MSD8XPNP_IGN_1, // ign 1
//  Gpio::MSD8XPNP_IGN_2, // ign 2
//  Gpio::MSD8XPNP_IGN_3, // ign 3
//  Gpio::MSD8XPNP_IGN_4, // ign 4
//  Gpio::MSD8XPNP_IGN_5, // ign 5
//  Gpio::MSD8XPNP_IGN_6, // ign 6

//  Gpio::MSD8XPNP_LS_13, // main relay
//  Gpio::MSD8XPNP_LS_16, // main relay
//  };

// static Gpio MSD8XPNP_OUTPUTS[] = {
//     Gpio::MSD8XPNP_LS_1,
//     Gpio::MSD8XPNP_LS_2,
//     Gpio::MSD8XPNP_LS_3,
//     Gpio::MSD8XPNP_LS_4,
//     Gpio::MSD8XPNP_LS_5,
//     Gpio::MSD8XPNP_LS_6,
//     Gpio::MSD8XPNP_LS_7,
//     Gpio::MSD8XPNP_LS_8,
//     Gpio::MSD8XPNP_LS_9,
//     Gpio::MSD8XPNP_LS_10,
//     Gpio::MSD8XPNP_LS_11,
//     Gpio::MSD8XPNP_LS_12,
//     Gpio::MSD8XPNP_LS_13,
//     Gpio::MSD8XPNP_LS_14,
//     Gpio::MSD8XPNP_LS_15,
//     Gpio::MSD8XPNP_LS_16,
//     Gpio::MSD8XPNP_IGN_1,
//     Gpio::MSD8XPNP_IGN_2,
//     Gpio::MSD8XPNP_IGN_3,
//     Gpio::MSD8XPNP_IGN_4,
//     Gpio::MSD8XPNP_IGN_5,
//     Gpio::MSD8XPNP_IGN_6,
//     Gpio::MSD8XPNP_IGN_7,
//     Gpio::MSD8XPNP_IGN_8,
//     Gpio::MSD8XPNP_IGN_9,
//     Gpio::MSD8XPNP_IGN_10,
//     Gpio::MSD8XPNP_IGN_11,
//     Gpio::MSD8XPNP_IGN_12,
//     Gpio::MSD8XPNP_HS_1,
//     Gpio::MSD8XPNP_HS_2,
//     Gpio::MSD8XPNP_HS_3,
//     Gpio::MSD8XPNP_HS_4
// };