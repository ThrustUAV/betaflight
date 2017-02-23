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

#define FC_VERSION_THRUST_DEV_LEVEL_MAJOR 0 //increment when a significant change is made
#define FC_VERSION_THRUST_DEV_LEVEL_MINOR 1 //increment when a bug is fixed

/* Version Log
Version 0.1
Initial Update

- LED count has been reduced from 32 to 24
 -- LED preconfiguration has been created to showcase:
  --- GPS STATUS
  --- ARM STATE
  --- COLOR w/ Larson scanner overlay

- Motors have been preconfigured to use the MULTISHOT protocol

- Board Orientation has been corrected
 - Pitch: 0.0 ==> 180.0

- Ports have been correctly predefined to allow for the use of the GPS
 -- UART 2: None ==> GPS
 
- Configurations have been updated
 - GPS enabled by default
 - LEDStrip enabled by default
 - Motor output enabled by default
 
- BLHeli Passthrough has been configured and enabled

- The following have been disabled to improve performance and stability
 -- Blackbox
 -- Telemetry
 -- OSD
 -- Servos
	

