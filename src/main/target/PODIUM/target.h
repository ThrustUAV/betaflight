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

#pragma once
#define TARGET_BOARD_IDENTIFIER "PODI"
#define TARGET_CONFIG

#define CONFIG_START_FLASH_ADDRESS 0x08080000 //0x08080000 to 0x080A0000 (FLASH_Sector_8)

#define USBD_PRODUCT_STRING "Podium"
#ifdef OPBL
  #define USBD_SERIALNUMBER_STRING "0x8020000"
#endif


// LED Pin Definitions
#define LED0                    PB5
#define LED1                    PB4
#define LED2                    PB6


// Inverter Pin Definition
#define INVERTER                PC0
#define INVERTER_USART          USART1

// ICM-20608G Definitions
#define MPU6500_CS_PIN          PA4
#define MPU6500_SPI_INSTANCE    SPI1

#define ACC
#define USE_ACC_SPI_MPU6500

#define GYRO
#define USE_GYRO_SPI_MPU6500

// Memory Pin definitions
#define M25P16_CS_PIN           PB3
#define M25P16_SPI_INSTANCE     SPI3


// VCP Pin Definition
#define USE_VCP
#define VBUS_SENSING_PIN        PA8

// UART Pin Definitions
#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9
#define UART1_AHB1_PERIPHERALS  RCC_AHB1Periph_DMA2

#define USE_UART3
#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PB10

#define USE_UART6
#define UART6_RX_PIN            PC7
#define UART6_TX_PIN            PC6 

#define SERIAL_PORT_COUNT 4

// SPI Definitions
#define USE_SPI


// SD CARD
#define USE_SDCARD

#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT
#define USE_SDCARD_SPI3

#define SDCARD_SPI_INSTANCE                 SPI3
#define SDCARD_SPI_CS_PIN                   PB3

// SPI3 is on the APB1 bus whose clock runs at 42MHz. Divide to under 400kHz for init:
#define SDCARD_SPI_INITIALIZATION_CLOCK_DIVIDER 128 // 328kHz
// Divide to under 25MHz for normal operation:
#define SDCARD_SPI_FULL_SPEED_CLOCK_DIVIDER     2 // 21MHz

#define SDCARD_DMA_CHANNEL_TX               DMA1_Stream5
#define SDCARD_DMA_CHANNEL_TX_COMPLETE_FLAG DMA_FLAG_TCIF5
#define SDCARD_DMA_CLK                      RCC_AHB1Periph_DMA1
#define SDCARD_DMA_CHANNEL                  DMA_Channel_0

// SPI GYRO Pin Definitions
#define USE_SPI_DEVICE_1 

#define SPI1_NSS_PIN            PA4
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7



// SPI FLASH Pin Definitions
#define USE_SPI_DEVICE_3 
#define SPI3_NSS_PIN            PB3
#define SPI3_SCK_PIN            PC10
#define SPI3_MISO_PIN           PC11
#define SPI3_MOSI_PIN           PC12


// Feature Definitions
#define LED_STRIP
//#define USE_DSHOT


#define USE_ADC
#define BOARD_HAS_VOLTAGE_DIVIDER

#define VBAT_ADC_PIN           PC3
#define VBAT_ADC_CHANNEL       ADC_Channel_13

#define TELEMETRY

#define DEFAULT_FEATURES        (FEATURE_VBAT)
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART6

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff


// Timer Definitions

// ver: 3.1.0.1.2
#define USABLE_TIMER_CHANNEL_COUNT 12
#define USED_TIMERS  ( TIM_N(2) | TIM_N(3) | TIM_N(5) | TIM_N(12) | TIM_N(8))

/*
// ver: 3.1.0.1.1
#define USABLE_TIMER_CHANNEL_COUNT 11
#define USED_TIMERS  ( TIM_N(2) | TIM_N(3) | TIM_N(5) | TIM_N(12) | TIM_N(8) | TIM_N(9))
*/

