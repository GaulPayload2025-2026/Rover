/*
 * tfluna.c
 *
 *  Created on: Feb 21, 2026
 *      Author: Etienne
 */

/* Private includes */

#include "tfluna/tfluna.h"
#include "map/hardware_map.h"
#include "stm32f4xx_hal_uart.h"

/* Private defines */

#define TF_LUNA_HEADER        		  0x59
#define TF_LUNA_COMMAND_FRAME_LEN     0x08
#define TF_LUNA_COMMAND_SIZE 		  8U
#define TF_LUNA_FRAME_LEN     		  9U

/* Private typedefs */

/* Private variables */

uint8_t guRxBuffer[TF_LUNA_FRAME_LEN];
sTFLunaData_t gsTFLunaData = {0};

/* Private function prototype */

uint8_t computeChecksum(uint8_t *uDataFrame, uint8_t uSize);


void tfluna_Init(void)
{
	// Disable Continuous output mode so that we trigger it manually
	tfluna_SendCmd(TF_LUNA_CMD_SET_CONTINUOUS_OUTPUT, TF_LUNA_OUTPUT_DISABLE);
	// Set the output data format to standard 9 bytes
	tfluna_SendCmd(TF_LUNA_CMD_SET_OUTPUT_FORMAT, TF_LUNA_FORMAT_STANDARD);

	// Start interrupt
	HAL_UART_Receive_IT(TFLUNA_UART, guRxBuffer, TF_LUNA_FRAME_LEN);
}

void tfluna_Trigger_Single_Measurement()
{
	// Set the output data format to standard 9 bytes
	tfluna_SendCmd(TF_LUNA_CMD_TRIGGER_MEASUREMENT, TF_LUNA_NO_DATA);
}

void tfluna_GetData(sTFLunaData_t *sData)
{
	*sData = gsTFLunaData;
}

HAL_StatusTypeDef tfluna_SendCmd(eTFLunaCommands_t cmd, uint32_t data)
{
    uint8_t frame[8];

    frame[0] = TF_LUNA_HEADER;
    frame[1] = TF_LUNA_COMMAND_FRAME_LEN;
    frame[2] = cmd;
    frame[3] = (uint8_t)((data >> 0) & 0xFF);
    frame[4] = (uint8_t)((data >> 8) & 0xFF);
    frame[5] = (uint8_t)((data >> 16) & 0xFF);
    frame[6] = (uint8_t)((data >> 24) & 0xFF);
    frame[7] = computeChecksum(frame, TF_LUNA_COMMAND_FRAME_LEN);

    return HAL_UART_Transmit(TFLUNA_UART, frame, TF_LUNA_COMMAND_SIZE, HAL_MAX_DELAY);
}

void tfluna_UART_RxCallback()
{

    /* Validate header */
    if (guRxBuffer[0] == TF_LUNA_HEADER && guRxBuffer[1] == TF_LUNA_HEADER)
    {
        /* Validate checksum */
        uint8_t checksum = computeChecksum(guRxBuffer, TF_LUNA_FRAME_LEN);

        if (checksum == guRxBuffer[TF_LUNA_FRAME_LEN - 1])
        {
        	/* Parse data */
        	gsTFLunaData.uDistance  = guRxBuffer[2] | (guRxBuffer[3] << 8);

        	gsTFLunaData.uAmplitude = guRxBuffer[4] |(guRxBuffer[5] << 8);

        	gsTFLunaData.fTemperature = (guRxBuffer[6] | (guRxBuffer[7] << 8)) / 8.0f - 256.0f;

        	gsTFLunaData.uTimeStamp = HAL_GetTick();
        }
    }

    /* Restart interrupt */
    HAL_UART_Receive_IT(TFLUNA_UART, guRxBuffer, TF_LUNA_FRAME_LEN);
}

uint8_t computeChecksum(uint8_t *uDataFrame, uint8_t uSize)
{
    uint16_t sum = 0;
    for(int i = 0; i < uSize - 1; i++)
        sum += uDataFrame[i];

    return (uint8_t)(sum & 0xFF);
}
