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
#define TARGET_BOARD_IDENTIFIER "RIOTFC"
#define TARGET_CONFIG

#define CONFIG_START_FLASH_ADDRESS 0x08080000 //0x08080000 to 0x080A0000 (FLASH_Sector_8)

#define USBD_PRODUCT_STRING "Riot FC"
/*
#ifdef OPBL
	#define USBD_SERIALNUMBER_STRING "0x8020000"
#endif
*/

/*	LED Pin Configuration	*/
#define LED0                    PB5
#define LED1                    PB4
#define LED2                    PB6


#define INVERTER_PIN_USART6 	PC6
#define INVERTER_USART          USART6

// MPU9250 interrupt
// Need to test and see if neccessary
#define USE_EXTI
#define MPU_INT_EXTI            PC5
#define EXTI_CALLBACK_HANDLER_COUNT 1 // MPU data ready
//#define DEBUG_MPU_DATA_READY_INTERRUPT
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW

/*	Legacy ACC/GYRO Configuration	*/
/*	MPU6500 ACC/GYRO				*/
/*

#define MPU6500_CS_PIN          PC4
#define MPU6500_SPI_INSTANCE    SPI1

#define ACC
#define USE_ACC_SPI_MPU6500
#define ACC_MPU6500_ALIGN       CW270_DEG

#define GYRO
#define defaultRoll		0
#define defaultPitch	180
#define defaultYaw		270
#define USE_GYRO_SPI_MPU6500
#define GYRO_MPU6500_ALIGN      CW270_DEG
 
*/ 


/*	MPU6000 Configuration	*/
#define MPU6000_CS_PIN          PC4
#define MPU6000_SPI_INSTANCE    SPI1

#define ACC
#define USE_ACC_SPI_MPU6000
#define ACC_MPU6000_ALIGN       CW270_DEG

#define GYRO
#define USE_GYRO_SPI_MPU6000
#define GYRO_MPU6000_ALIGN      CW270_DEG

/*	Preset Roll/Pitch/Yaw
#define defaultRoll		0
#define defaultPitch	180
#define defaultYaw		270
*/


/*	Barometer Configuration	*/
#define BARO
#define USE_BARO_MS5611
#define MS5611_I2C_INSTANCE I2CDEV_1


/*	SD CARD Configuration Information	*/
#define ENABLE_BLACKBOX_LOGGING_ON_SDCARD_BY_DEFAULT
#define USE_SDCARD

#define SDCARD_SPI_INSTANCE                 SPI3
#define SDCARD_SPI_CS_PIN                   SPI3_NSS_PIN

// SPI2 is on the APB1 bus whose clock runs at 84MHz. Divide to under 400kHz for init:
#define SDCARD_SPI_INITIALIZATION_CLOCK_DIVIDER 256 // 328kHz
// Divide to under 25MHz for normal operation:
#define SDCARD_SPI_FULL_SPEED_CLOCK_DIVIDER     4 // 21MHz

#define SDCARD_DMA_CHANNEL_TX               DMA1_Stream5
#define SDCARD_DMA_CHANNEL_TX_COMPLETE_FLAG DMA_FLAG_TCIF5
#define SDCARD_DMA_CLK                      RCC_AHB1Periph_DMA1
#define SDCARD_DMA_CHANNEL                  DMA_Channel_0

/*	UART Configuration	*/
#define USE_VCP
#define VBUS_SENSING_PIN        PA8

#define USE_UART1
#define UART1_RX_PIN            PA10
#define UART1_TX_PIN            PA9
#define UART1_AHB1_PERIPHERALS  RCC_AHB1Periph_DMA2

#define USE_UART3
#define UART3_RX_PIN            PB11
#define UART3_TX_PIN            PB10

#define USE_UART6
#define UART6_RX_PIN            PC7
#define UART6_TX_PIN            PC6 //inverter

#define SERIAL_PORT_COUNT 4


/*	SPI Devices	*/
#define USE_SPI

#define USE_SPI_DEVICE_1 
#define SPI1_NSS_PIN            PC4
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

#define USE_SPI_DEVICE_3 // SDCard SPI
#define SPI3_NSS_PIN            PB3
#define SPI3_SCK_PIN            PC10
#define SPI3_MISO_PIN           PC11
#define SPI3_MOSI_PIN           PC12

/*	I2C Devices	*/
#define USE_I2C
#define I2C_DEVICE              (I2CDEV_1)
//#define I2C_DEVICE_EXT          (I2CDEV_2)

///	MS5611 I2C Pins
#define I2C1_SCL                PB8
#define I2C1_SDA                PB9

/*	ADC Configuration	*/
#define USE_ADC
#define VBAT_SCALE_DEFAULT      53 
#define BOARD_HAS_VOLTAGE_DIVIDER

#define CURRENT_METER_ADC_PIN       PC2
#define CURRENT_METER_ADC_CHANNEL   ADC_Channel_12

#define VBAT_ADC_PIN           PC3
#define VBAT_ADC_CHANNEL       ADC_Channel_13


/*	LED Strip Driver Configuration	*/
#define LED_STRIP
#define LED_STRIP_LENGTH 35
#define RIOTLEDCONFIG

/*	Legacy WS2811 Configuration Information */
/*
#define WS2811_PIN                      PA0
#define WS2811_TIMER                    TIM5
#define WS2811_DMA_HANDLER_IDENTIFER    DMA1_ST2_HANDLER
#define WS2811_DMA_STREAM               DMA1_Stream2
#define WS2811_DMA_IT                   DMA_IT_TCIF2
#define WS2811_DMA_CHANNEL              DMA_Channel_6
#define WS2811_TIMER_CHANNEL            TIM_Channel_1
*/

/* Default Configuration Information	*/	
#define TELEMETRY
#define DEFAULT_FEATURES        (FEATURE_VBAT | FEATURE_LED_STRIP | FEATURE_AIRMODE | FEATURE_CURRENT_METER | FEATURE_TELEMETRY | FEATURE_BLACKBOX)
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART6
#define RX_CHANNELS_TAER
#define USE_SERIAL_4WAY_BLHELI_INTERFACE

/*	Timer Configuration	*/

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff


#define USABLE_TIMER_CHANNEL_COUNT 11
#define USED_TIMERS  ( TIM_N(2) | TIM_N(3) | TIM_N(5) | TIM_N(12) | TIM_N(8) | TIM_N(9))

