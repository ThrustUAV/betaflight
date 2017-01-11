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

#define FC_VERSION_THRUST_DEV_LEVEL_MAJOR 1 //increment when a significant change is made
#define FC_VERSION_THRUST_DEV_LEVEL_MINOR 4 //increment when a bug is fixed


/* Version Log
Version 1.4
Betaflight Update
 -Code update (1/09/2016)
 -DSHOT1200 Introduction

Version 1.3
Smartport Implementation
- Config.c has been updated to disable bidirectional communication
- Config.c has been updated to disable serial inversion
Hardware:
- Smartport inversion circuit to be updated, change 39k pull down drain pull down resistor to 10k

Version 1.2
DSHOT Inclusion
- Target.h has been updated to include define for DSHOT usage.
- Target.h has been updated to include updated timer counts and used
timers defines
-Target.c timer calls definitions have been reassigned to allow for
DSHOT capabilities, working with DSHOT600

*/