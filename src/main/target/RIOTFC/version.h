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
#define FC_VERSION_THRUST_DEV_LEVEL_MINOR 5 //increment when a bug is fixed

/* Version Log
Version 0.5
TESTING OSD Performance
DMA disabled
 

Version 0.4
Smartport Implementation
- Set defaults for smartport configuration
-- Telemetry inversion disabled
-- BIDIR disabled

Version 0.3
Restructuring Codebase away from haseebnain

- Updated GYRO/ACCL allignments
-- Yaw ->270
-- Pitch -> 180
-- Removed board allignment from Target.h
- Include defines for custom LEDs
- Timer defines updated in Target.c
- Moved over presets from local version of Betaflight(V10)
- Motor preset for MULTISHOT
- Battery scaling adjusted
-- Voltage scale --> 53
-- Current scale --> 403
- PID has been set to 8kHz
- PID profile has been updated to include preset tune (Conrad Tune)
