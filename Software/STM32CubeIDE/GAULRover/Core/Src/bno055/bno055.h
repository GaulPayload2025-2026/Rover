/*
 * bno055.h
 *
 *  Created on: Feb 21, 2026
 *      Author: Etienne
 */

#ifndef SRC_BNO055_BNO055_H_
#define SRC_BNO055_BNO055_H_

//#include <string.h>
//#include <stdio.h>
//#include "stm32f4xx_hal.h"
//#include <inttypes.h>
//#include <math.h>
#include <stdint.h>

void bno055_Init(void);
void bno055_Task(void);
void bno055_GetGyro(float *x, float *y, float *z);
void bno055_SetFilter(uint32_t filt_id);

#endif /* SRC_BNO055_BNO055_H_ */
