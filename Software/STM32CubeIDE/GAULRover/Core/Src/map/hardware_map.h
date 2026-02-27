/*
 * hardware_map.h
 *
 *  Created on: Feb 21, 2026
 *      Author: Etienne
 */

#ifndef SRC_MAP_HARDWARE_MAP_H_
#define SRC_MAP_HARDWARE_MAP_H_

#include "i2c.h"
#include "usart.h"
#include "spi.h"


/* -------------------------------------------------------------------------- */
/*                          PERIPHERAL HANDLE MAPPING                         */
/* -------------------------------------------------------------------------- */


/* ========================= I2C Devices =================================== */

#define BNO055_I2C (&hi2c1)

/* ========================= SPI Devices =================================== */

#define SD_SPI (hspi1)

/* ========================= UART Devices ================================== */

#define CONSOLE_UART (&huart1)
#define TFLUNA_UART (&huart2)

/* ========================= GPIO Devices ================================== */

#define SD_CS_PIN_GPIO GPIO_PIN_4
#define SD_CS_PORT_GPIO GPIOC

#endif /* SRC_MAP_HARDWARE_MAP_H_ */
