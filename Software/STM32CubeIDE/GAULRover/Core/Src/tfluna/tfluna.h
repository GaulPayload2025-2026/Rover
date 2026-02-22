/*
 * tfluna.h
 *
 *  Created on: Feb 21, 2026
 *      Author: Etienne
 */

#ifndef SRC_TFLUNA_TFLUNA_H_
#define SRC_TFLUNA_TFLUNA_H_

#include "tfluna/tfluna_commands.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint16_t uDistance;
    uint16_t uAmplitude;
    float  fTemperature;
    uint32_t uTimeStamp;
} sTFLunaData_t;

HAL_StatusTypeDef tfluna_SendCmd(eTFLunaCommands_t cmd, uint32_t data);
void tfluna_GetData(sTFLunaData_t *sData);
void tfluna_Trigger_Single_Measurement(void);
void tfluna_UART_RxCallback(void);


#endif /* SRC_TFLUNA_TFLUNA_H_ */
