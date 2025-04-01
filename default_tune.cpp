#include "pch.h"
#include "defaults.h"

//Definitions

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

// Static

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

//CONFIGURATION

void setboardTuneDefaults() {
	engineConfiguration->isSdCardEnabled = true;

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

	setInjectorPins();
	setIgnitionPins();

	// Knock
	engineConfiguration->enableSoftwareKnock = true;

	// Ignition
	engineConfiguration->ignitionMode = IM_INDIVIDUAL_COILS;

	// Fuel
	engineConfiguration->injectionMode = IM_SEQUENTIAL;
	engineConfiguration->injector.flow = 180; // cc/min, who knows if this number is real - no good source of info

	// Main Relay
	engineConfiguration->mainRelayPin = Gpio::MSD8XPNP_LS_12;

	// Crank
	engineConfiguration->triggerInputPins[0] = MSD8XPNP_DIGITAL_1;

	// Cams
	engineConfiguration->camInputs[0] = MSD8XPNP_DIGITAL_2;
    engineConfiguration->camInputs[1] = MSD8XPNP_DIGITAL_3;

	// Cranking
    setCrankOperationMode();
	engineConfiguration->trigger.type = trigger_type_e::TT_TOOTHED_WHEEL_60_2;
	engineConfiguration->cranking.rpm = 350;
	engineConfiguration->cranking.baseFuel = 27;
	engineConfiguration->crankingTimingAngle = 15;

	//MAP
    engineConfiguration->map.sensor.type = MT_BOSCH_2_5;
	engineConfiguration->map.sensor.hwChannel = MSD8XPNP_IN_MAP;

	// Temps
	engineConfiguration->clt.adcChannel = MSD8XPNP_IN_CLT;
	engineConfiguration->iat.adcChannel = MSD8XPNP_IN_IAT;

	// TPS
	engineConfiguration->tps1_1AdcChannel = MSD8XPNP_IN_TPS;

	// PPS
	setPPSCalibration(0.73, 4.0, 0.34, 1.86);

	// Wideband
	engineConfiguration->afr.hwChannel = MSD8XPNP_IN_ANALOG_VOLT_10;

	// ETB
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
