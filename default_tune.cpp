#include "pch.h"

void boardTuneDefaults() {
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

    engineConfiguration->injector.flow = 180; // cc/min, who knows if this number is real - no good source of info

    setCrankOperationMode();
	engineConfiguration->trigger.type = trigger_type_e::TT_TOOTHED_WHEEL_60_2;

	// this engine seems to crank at around only 150 RPM? And happily idle at 400RPM?
	engineConfiguration->cranking.rpm = 350;

	engineConfiguration->ignitionMode = IM_INDIVIDUAL_COILS;

	// set cranking_fuel x
	engineConfiguration->cranking.baseFuel = 27;

	engineConfiguration->crankingTimingAngle = 15;
	setTable(config->veTable, 45);

    //MAIN CONFIGURATION
	engineConfiguration->triggerInputPins[0] = Gpio::C6;

	engineConfiguration->camInputs[0] = Gpio::E11;
    engineConfiguration->camInputs[1] = Gpio::E12;

    engineConfiguration->map.sensor.type = MT_BOSCH_2_5;

    setPPSCalibration(0.73, 4.0, 0.34, 1.86);
}
