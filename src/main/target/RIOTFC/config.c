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

#include "config/config_master.h"

// alternative defaults settings for BlueJayF4 targets
void targetConfiguration(master_t *config)
{
	// Motor Configurations
	// 3 = PWM_TYPE_MULTISHOT
	config->motorConfig.motorPwmProtocol = 3;
	
	//Smartport Configurations
	config->telemetryConfig.telemetry_inversion = 0;
    config->telemetryConfig.sportHalfDuplex = 0;
	
	// Motor Board Allignment Configurations
    config->boardAlignment.rollDegrees = 0;
	config->boardAlignment.pitchDegrees = 180;
	config->boardAlignment.yawDegrees = 270;
	
	// Battery Configurations
	config->batteryConfig.vbatscale = 53;
	config->batteryConfig.currentMeterScale = 403;
	
	// PID Configuration set to 8KHz
	config->pidConfig.pid_process_denom = 1;
	
	
	// PID Profiile Configurations
	
	config->profile[0].pidProfile.P8[ROLL] = 43;
    config->profile[0].pidProfile.I8[ROLL] = 50;
    config->profile[0].pidProfile.D8[ROLL] = 20;
    config->profile[0].pidProfile.P8[PITCH] = 60;
    config->profile[0].pidProfile.I8[PITCH] = 55;
    config->profile[0].pidProfile.D8[PITCH] = 19;
    config->profile[0].pidProfile.P8[YAW] = 80;
    config->profile[0].pidProfile.I8[YAW] = 55;
    config->profile[0].pidProfile.D8[YAW] = 20;
    config->profile[0].pidProfile.P8[PIDALT] = 50;
    config->profile[0].pidProfile.I8[PIDALT] = 0;
    config->profile[0].pidProfile.D8[PIDALT] = 0;
    config->profile[0].pidProfile.P8[PIDPOS] = 15;   
    config->profile[0].pidProfile.I8[PIDPOS] = 0;    
    config->profile[0].pidProfile.D8[PIDPOS] = 0;
    config->profile[0].pidProfile.P8[PIDPOSR] = 34;  
    config->profile[0].pidProfile.I8[PIDPOSR] = 14;  
    config->profile[0].pidProfile.D8[PIDPOSR] = 53;  
    config->profile[0].pidProfile.P8[PIDNAVR] = 25;  
    config->profile[0].pidProfile.I8[PIDNAVR] = 33;  
    config->profile[0].pidProfile.D8[PIDNAVR] = 83;  
    config->profile[0].pidProfile.P8[PIDLEVEL] = 50;
    config->profile[0].pidProfile.I8[PIDLEVEL] = 50;
    config->profile[0].pidProfile.D8[PIDLEVEL] = 100;
    config->profile[0].pidProfile.P8[PIDMAG] = 40;
    config->profile[0].pidProfile.P8[PIDVEL] = 55;
    config->profile[0].pidProfile.I8[PIDVEL] = 55;
    config->profile[0].pidProfile.D8[PIDVEL] = 75;
    
}
