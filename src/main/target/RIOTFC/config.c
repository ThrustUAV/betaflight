/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include <stdbool.h>

#include <platform.h>

//#include "config/config_master.h"
#include "config/config_profile.h"
#include "config/feature.h"

#include "blackbox/blackbox.h"

#include "cms/cms.h"

#include "drivers/adc.h"
#include "drivers/rx_pwm.h"
#include "drivers/sound_beeper.h"
#include "drivers/sonar_hcsr04.h"
#include "drivers/sdcard.h"
#include "drivers/vcd.h"
#include "drivers/light_led.h"
#include "drivers/flash.h"
#include "drivers/display.h"
#include "drivers/serial.h"

#include "fc/config.h"
#include "fc/controlrate_profile.h"
#include "fc/rc_adjustments.h"
#include "fc/rc_controls.h"
#include "fc/fc_core.h"

#include "flight/altitudehold.h"
#include "flight/failsafe.h"
#include "flight/mixer.h"
#include "flight/servos.h"
#include "flight/imu.h"
#include "flight/navigation.h"
#include "flight/pid.h"

#include "io/beeper.h"
#include "io/gimbal.h"
#include "io/gps.h"
#include "io/ledstrip.h"
#include "io/osd.h"
#include "io/serial.h"
#include "io/servos.h"
#include "io/transponder_ir.h"
#include "io/vtx.h"

#include "rx/rx.h"

#include "telemetry/telemetry.h"

#include "sensors/sensors.h"
#include "sensors/gyro.h"
#include "sensors/acceleration.h"
#include "sensors/boardalignment.h"
#include "sensors/barometer.h"
#include "sensors/battery.h"
#include "sensors/compass.h"

// Default Settings for the RiotFC rev 1.802c
void targetConfiguration(void)
{
	// Motor Configurations
	// 3 = PWM_TYPE_MULTISHOT
	motorConfigMutable()->dev.motorPwmProtocol = 3;
	motorConfigMutable()->minthrottle = 1040;
	
	//Smartport Configurations
	telemetryConfigMutable()->telemetry_inversion = 0;
	telemetryConfigMutable()->sportHalfDuplex = 0;
	
	// Barometer Configuration
	//config->barometerConfig.baro_hardware = 3;

	
	// Motor Board Allignment Configurations
    boardAlignmentMutable()->rollDegrees = 0;
	boardAlignmentMutable()->pitchDegrees = 180;
	boardAlignmentMutable()->yawDegrees = 270;
	
	// Battery Configurations
	batteryConfigMutable()->vbatscale = 53;
	batteryConfigMutable()->currentMeterScale = 250;
	
	// PID Configuration set to 8KHz
	pidConfigMutable()->pid_process_denom = 1;

	
	
	// PID Profiile Configurations
	
	pidProfilesMutable(0)->P8[ROLL] = 43;
	pidProfilesMutable(0)->I8[ROLL] = 50;
	pidProfilesMutable(0)->D8[ROLL] = 20;
	pidProfilesMutable(0)->P8[PITCH] = 60;
	pidProfilesMutable(0)->I8[PITCH] = 55;
	pidProfilesMutable(0)->D8[PITCH] = 19;
	pidProfilesMutable(0)->P8[YAW] = 80;
	pidProfilesMutable(0)->I8[YAW] = 55;
	pidProfilesMutable(0)->D8[YAW] = 20;
	pidProfilesMutable(0)->P8[PIDALT] = 50;
	pidProfilesMutable(0)->I8[PIDALT] = 0;
	pidProfilesMutable(0)->D8[PIDALT] = 0;
	pidProfilesMutable(0)->P8[PIDPOS] = 15;   
	pidProfilesMutable(0)->I8[PIDPOS] = 0;    
	pidProfilesMutable(0)->D8[PIDPOS] = 0;
	pidProfilesMutable(0)->P8[PIDPOSR] = 34;  
	pidProfilesMutable(0)->I8[PIDPOSR] = 14;  
	pidProfilesMutable(0)->D8[PIDPOSR] = 53;  
	pidProfilesMutable(0)->P8[PIDNAVR] = 25;  
	pidProfilesMutable(0)->I8[PIDNAVR] = 33;  
	pidProfilesMutable(0)->D8[PIDNAVR] = 83;  
	pidProfilesMutable(0)->P8[PIDLEVEL] = 50;
	pidProfilesMutable(0)->I8[PIDLEVEL] = 50;
	pidProfilesMutable(0)->D8[PIDLEVEL] = 100;
	pidProfilesMutable(0)->P8[PIDMAG] = 40;
	pidProfilesMutable(0)->P8[PIDVEL] = 55;
	pidProfilesMutable(0)->I8[PIDVEL] = 55;
	pidProfilesMutable(0)->D8[PIDVEL] = 75;

	
	// Preset Port assignments
	serialConfigMutable()->portConfigs[0].identifier = serialPortIdentifiers[0];
	serialConfigMutable()->portConfigs[0].msp_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[0].gps_baudrateIndex = BAUD_57600;
	serialConfigMutable()->portConfigs[0].telemetry_baudrateIndex = BAUD_AUTO;
	serialConfigMutable()->portConfigs[0].blackbox_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[0].functionMask = FUNCTION_MSP;
	
	serialConfigMutable()->portConfigs[1].identifier = serialPortIdentifiers[1];
	serialConfigMutable()->portConfigs[1].msp_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[1].gps_baudrateIndex = BAUD_57600;
	serialConfigMutable()->portConfigs[1].telemetry_baudrateIndex = BAUD_AUTO;
	serialConfigMutable()->portConfigs[1].blackbox_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[1].functionMask = FUNCTION_MSP;
	
	serialConfigMutable()->portConfigs[2].identifier = serialPortIdentifiers[2];
	serialConfigMutable()->portConfigs[2].msp_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[2].gps_baudrateIndex = BAUD_57600;
	serialConfigMutable()->portConfigs[2].telemetry_baudrateIndex = BAUD_57600;
	serialConfigMutable()->portConfigs[2].blackbox_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[2].functionMask = FUNCTION_TELEMETRY_SMARTPORT;
	
	serialConfigMutable()->portConfigs[3].identifier = serialPortIdentifiers[3];
	serialConfigMutable()->portConfigs[3].msp_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[3].gps_baudrateIndex = BAUD_57600;
	serialConfigMutable()->portConfigs[3].telemetry_baudrateIndex = BAUD_AUTO;
	serialConfigMutable()->portConfigs[3].blackbox_baudrateIndex = BAUD_115200;
	serialConfigMutable()->portConfigs[3].functionMask = FUNCTION_RX_SERIAL;
	

}

