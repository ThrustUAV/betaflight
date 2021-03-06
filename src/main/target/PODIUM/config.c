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
        

    // Board Allignment
		config->boardAlignment.rollDegrees = 180;
		config->boardAlignment.pitchDegrees = 0;
		config->boardAlignment.yawDegrees = 180;
		
		//Smartport Configurations
		config->telemetryConfig.telemetry_inversion = 0;
		config->telemetryConfig.sportHalfDuplex = 0;

		
    
}
