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


/* -------------------------------------------------------------------------- */
/*                          PERIPHERAL HANDLE MAPPING                         */
/* -------------------------------------------------------------------------- */


/* ========================= I2C Devices =================================== */

#define BNO055_I2C (&hi2c1)

/* ========================= SPI Devices =================================== */

/* ========================= UART Devices ================================== */

#define TFLUNA_UART (&huart1)




#endif /* SRC_MAP_HARDWARE_MAP_H_ */
