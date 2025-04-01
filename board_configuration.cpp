/**
 * @file boards/MSD8XPNP/board_configuration.cpp
 *
 * @brief Configuration defaults for the MSD8XPNP board
 *
 * @author Tyler Browning, (c) 2024
 */

#include "pch.h"
#include "defaults.h"

//DEFINITIONS

#define MSD8XPNP_DEFAULT_AT_PULLUP 2700

#define MSD8XPNP_LS_1 D7
// pin 15/black35
#define MSD8XPNP_LS_2 G9

// pin 4/black35
#define MSD8XPNP_LS_3 G10

// pin 16/black35
#define MSD8XPNP_LS_4 G11

// pin 5/black35
#define MSD8XPNP_LS_5 G12

// pin 6/black35
#define MSD8XPNP_LS_6 G13

// pin 7/black35
#define MSD8XPNP_LS_7 G14
#define MSD8XPNP_LS_8 B4
#define MSD8XPNP_LS_9 B5

// pin 20/black35
#define MSD8XPNP_LS_10 B6
#define MSD8XPNP_LS_11 B7
#define MSD8XPNP_LS_12 B8

// pin 10/black35
#define MSD8XPNP_LS_13 B9
// pin 11/black35
#define MSD8XPNP_LS_14 E0
// pin 12/black35
#define MSD8XPNP_LS_15 E1
// pin 23/black35
#define MSD8XPNP_LS_16 E2


// pin 2/black35
#define MSD8XPNP_HS_1 A9

// pin 1/black35
#define MSD8XPNP_HS_2 A8

#define MSD8XPNP_HS_3 D15

#define MSD8XPNP_HS_4 D14

// pin 35/black35
#define MSD8XPNP_IGN_1 D4

// pin 34/black35
#define MSD8XPNP_IGN_2 D3

// pin 22/black35
#define MSD8XPNP_IGN_3 C9
#define MSD8XPNP_IGN_4 C8
#define MSD8XPNP_IGN_5 C7
#define MSD8XPNP_IGN_6 G8
#define MSD8XPNP_IGN_7 G7
#define MSD8XPNP_IGN_8 G6
#define MSD8XPNP_IGN_9 G5
#define MSD8XPNP_IGN_10 G4
#define MSD8XPNP_IGN_11 G3
#define MSD8XPNP_IGN_12 G2

// Analog Temp 1 = PC4
#define MSD8XPNP_IN_ANALOG_TEMP_1 EFI_ADC_14

// IAT = Analog Temp 2 = PC5
#define MSD8XPNP_IN_ANALOG_TEMP_2 EFI_ADC_15
#define MSD8XPNP_IN_IAT MSD8XPNP_IN_ANALOG_TEMP_2

// CLT = Analog Temp 3 = PB0
#define MSD8XPNP_IN_ANALOG_TEMP_3 EFI_ADC_8
#define MSD8XPNP_IN_CLT MSD8XPNP_IN_ANALOG_TEMP_3

// Analog Temp 4 = PB1
#define MSD8XPNP_IN_ANALOG_TEMP_4 EFI_ADC_9

// MAP = Analog volt 1 = PC0
#define MSD8XPNP_IN_ANALOG_VOLT_1 EFI_ADC_10
#define MSD8XPNP_IN_MAP MSD8XPNP_IN_ANALOG_VOLT_1

// TPS = Analog volt 2 = PC1
#define MSD8XPNP_IN_ANALOG_VOLT_2 EFI_ADC_11
#define MSD8XPNP_IN_TPS MSD8XPNP_IN_ANALOG_VOLT_2

// PC2
#define MSD8XPNP_IN_ANALOG_VOLT_3 EFI_ADC_12
#define MSD8XPNP_IN_TPS1_2 MSD8XPNP_IN_ANALOG_VOLT_3

// PC3
#define MSD8XPNP_IN_ANALOG_VOLT_4 EFI_ADC_13
#define MSD8XPNP_IN_TPS2_1 MSD8XPNP_IN_ANALOG_VOLT_4

// PA0
#define MSD8XPNP_IN_ANALOG_VOLT_5 EFI_ADC_0

// PA1
#define MSD8XPNP_IN_ANALOG_VOLT_6 EFI_ADC_1
#define MSD8XPNP_IN_AV_6_DIGITAL Gpio::A1

// PA2
#define MSD8XPNP_IN_ANALOG_VOLT_7 EFI_ADC_2
#define MSD8XPNP_IN_PPS2 MSD8XPNP_IN_ANALOG_VOLT_7

// PA3
#define MSD8XPNP_IN_ANALOG_VOLT_8 EFI_ADC_3
#define MSD8XPNP_IN_AV_8_DIGITAL Gpio::A3

// PA4
#define MSD8XPNP_IN_ANALOG_VOLT_9 EFI_ADC_4
#define MSD8XPNP_IN_PPS MSD8XPNP_IN_ANALOG_VOLT_9

// PA5
#define MSD8XPNP_IN_ANALOG_VOLT_10 EFI_ADC_5
#define MSD8XPNP_IN_AV_10_DIGITAL Gpio::A5

// PA6
#define MSD8XPNP_IN_ANALOG_VOLT_11 EFI_ADC_6
#define MSD8XPNP_IN_AV_11_DIGITAL Gpio::A6

#define MSD8XPNP_VR_1 Gpio::E7
#define MSD8XPNP_VR_2 Gpio::E8

#define MSD8XPNP_DIGITAL_1 Gpio::C6
#define MSD8XPNP_DIGITAL_2 Gpio::E11
#define MSD8XPNP_DIGITAL_3 Gpio::E12
#define MSD8XPNP_DIGITAL_4 Gpio::E14
#define MSD8XPNP_DIGITAL_5 Gpio::E13
#define MSD8XPNP_DIGITAL_6 Gpio::E15

void setMSD8XPNPEtbIO();

//CONFIGURATION

static const brain_pin_e injPins[] = {
    Gpio::MSD8XPNP_LS_1,
	Gpio::MSD8XPNP_LS_2,
	Gpio::MSD8XPNP_LS_3,
	Gpio::MSD8XPNP_LS_4,
	Gpio::MSD8XPNP_LS_5,
	Gpio::MSD8XPNP_LS_6,
	Gpio::MSD8XPNP_LS_7,
	Gpio::MSD8XPNP_LS_8,
	Gpio::MSD8XPNP_LS_9,
	Gpio::MSD8XPNP_LS_10,
	Gpio::MSD8XPNP_LS_11,
	Gpio::MSD8XPNP_LS_12
};

static const brain_pin_e ignPins[] = {
	Gpio::MSD8XPNP_IGN_1,
	Gpio::MSD8XPNP_IGN_2,
	Gpio::MSD8XPNP_IGN_3,
	Gpio::MSD8XPNP_IGN_4,
	Gpio::MSD8XPNP_IGN_5,
	Gpio::MSD8XPNP_IGN_6,
	Gpio::MSD8XPNP_IGN_7,
	Gpio::MSD8XPNP_IGN_8,
	Gpio::MSD8XPNP_IGN_9,
	Gpio::MSD8XPNP_IGN_10,
	Gpio::MSD8XPNP_IGN_11,
	Gpio::MSD8XPNP_IGN_12,
};

static void setInjectorPins() {
	copyArray(engineConfiguration->injectionPins, injPins);
}

static void setIgnitionPins() {
	copyArray(engineConfiguration->ignitionPins, ignPins);
}

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

static void setupEtb() {
	// TLE9201 driver
	// This chip has three control pins:
	// DIR - sets direction of the motor
	// PWM - pwm control (enable high, coast low)
	// DIS - disables motor (enable low)

	// Throttle #1
	// PWM pin
	engineConfiguration->etbIo[0].controlPin = Gpio::D12;
	// DIR pin
	engineConfiguration->etbIo[0].directionPin1 = Gpio::D10;
	// Disable pin
	engineConfiguration->etbIo[0].disablePin = Gpio::D11;

	// Throttle #2
	// PWM pin
	engineConfiguration->etbIo[1].controlPin = Gpio::D13;
	// DIR pin
	engineConfiguration->etbIo[1].directionPin1 = Gpio::D9;
	// Disable pin
	engineConfiguration->etbIo[1].disablePin = Gpio::D8;

	// we only have pwm/dir, no dira/dirb
	engineConfiguration->etb_use_two_wires = false;
}

static void setupDefaultSensorInputs() {
	// trigger inputs
	// Digital channel 1 as default - others not set
	engineConfiguration->triggerInputPins[0] = MSD8XPNP_DIGITAL_1;
	engineConfiguration->camInputs[0] = MSD8XPNP_DIGITAL_2;
	engineConfiguration->camInputs[1] = MSD8XPNP_DIGITAL_3;

	engineConfiguration->map.sensor.type = MT_BOSCH_2_5;


	engineConfiguration->clt.adcChannel = MSD8XPNP_IN_CLT;
	engineConfiguration->iat.adcChannel = MSD8XPNP_IN_IAT;
	engineConfiguration->tps1_1AdcChannel = MSD8XPNP_IN_TPS;
	engineConfiguration->map.sensor.hwChannel = MSD8XPNP_IN_MAP;

	setPPSCalibration(0.73, 4.0, 0.34, 1.86);

    // see also enableAemXSeries
	// pin #28 WBO AFR "Analog Volt 10"
	engineConfiguration->afr.hwChannel = MSD8XPNP_IN_ANALOG_VOLT_10;
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

static void setupCranking() {
    setCrankOperationMode();
	engineConfiguration->trigger.type = trigger_type_e::TT_TOOTHED_WHEEL_60_2;

	// this engine seems to crank at around only 150 RPM? And happily idle at 400RPM?
	engineConfiguration->cranking.rpm = 350;

	// set cranking_fuel x
	engineConfiguration->cranking.baseFuel = 27;

	engineConfiguration->crankingTimingAngle = 15;
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
void setBoardDefaultConfiguration() {
	setInjectorPins();
	setIgnitionPins();
	setupEtb();
	setupCranking();

	engineConfiguration->injector.flow = 180; // cc/min, who knows if this number is real - no good source of info
    engineConfiguration->displacement = 2.97;
    engineConfiguration->cylinderBore = 84.0;
    engineConfiguration->cylindersCount = 6;
    strcpy(engineConfiguration->engineMake, ENGINE_MAKE_BMW);
    strcpy(engineConfiguration->engineCode, "N54");
    strcpy(engineConfiguration->vehicleName, "Using RR MSD8xPnP");
    engineConfiguration->firingOrder = FO_1_5_3_6_2_4;
    engineConfiguration->fuelAlgorithm = LM_SPEED_DENSITY;
    engineConfiguration->canNbcType = CAN_BUS_BMW_E90;

	engineConfiguration->vvtMode[0] = VVT_SINGLE_TOOTH;

	engineConfiguration->globalTriggerAngleOffset = 90;

	engineConfiguration->ignitionMode = IM_INDIVIDUAL_COILS;
    engineConfiguration->injectionMode = IM_SEQUENTIAL;

	engineConfiguration->isSdCardEnabled = true;

	// "required" hardware is done - set some reasonable defaults
	setupDefaultSensorInputs();

	engineConfiguration->enableSoftwareKnock = true;

//#if HW_MSD8XPNP & EFI_PROD_CODE
//	engineConfiguration->mainRelayPin = Gpio::MSD8XPNP_LS_12;
//	engineConfiguration->fanPin = Gpio::MSD8XPNP_LS_11;
//	engineConfiguration->fuelPumpPin = Gpio::MSD8XPNP_LS_10;
//#endif // HW_MSD8XPNP

	// If we're running as hardware CI, borrow a few extra pins for that
//#ifdef HARDWARE_CI
//	engineConfiguration->triggerSimulatorPins[0] = Gpio::G3;
//	engineConfiguration->triggerSimulatorPins[1] = Gpio::G2;
//#endif
}

void boardPrepareForStop() {
	// Wake on the CAN RX pin
	palEnableLineEvent(PAL_LINE(GPIOD, 0), PAL_EVENT_MODE_RISING_EDGE);
}

//static Gpio MSD8XPNP_N54_OUTPUTS[] = {
//  Gpio::MSD8XPNP_LS_1, // inj 1
// Gpio::MSD8XPNP_LS_2, // inj 2
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

  //Gpio::MSD8XPNP_LS_13, // main relay
  //Gpio::MSD8XPNP_LS_16, // main relay
//};

static Gpio MSD8XPNP_OUTPUTS[] = {
Gpio::MSD8XPNP_LS_1,
Gpio::MSD8XPNP_LS_2,
Gpio::MSD8XPNP_LS_3,
Gpio::MSD8XPNP_LS_4,
Gpio::MSD8XPNP_LS_5,
Gpio::MSD8XPNP_LS_6,
Gpio::MSD8XPNP_LS_7,
Gpio::MSD8XPNP_LS_8,
Gpio::MSD8XPNP_LS_9,
Gpio::MSD8XPNP_LS_10,
Gpio::MSD8XPNP_LS_11,
Gpio::MSD8XPNP_LS_12,
Gpio::MSD8XPNP_LS_13,
Gpio::MSD8XPNP_LS_14,
Gpio::MSD8XPNP_LS_15,
Gpio::MSD8XPNP_LS_16,
	Gpio::MSD8XPNP_IGN_1,
	Gpio::MSD8XPNP_IGN_2,
	Gpio::MSD8XPNP_IGN_3,
	Gpio::MSD8XPNP_IGN_4,
	Gpio::MSD8XPNP_IGN_5,
	Gpio::MSD8XPNP_IGN_6,
	Gpio::MSD8XPNP_IGN_7,
	Gpio::MSD8XPNP_IGN_8,
	Gpio::MSD8XPNP_IGN_9,
	Gpio::MSD8XPNP_IGN_10,
	Gpio::MSD8XPNP_IGN_11,
	Gpio::MSD8XPNP_IGN_12,
	Gpio::MSD8XPNP_HS_1,
	Gpio::MSD8XPNP_HS_2,
	Gpio::MSD8XPNP_HS_3,
	Gpio::MSD8XPNP_HS_4
};