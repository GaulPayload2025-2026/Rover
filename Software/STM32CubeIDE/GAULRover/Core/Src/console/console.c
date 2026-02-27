/*
 * console.c
 *
 *  Created on: Feb 26, 2026
 *      Author: etien
 */

/* Private includes */

#include "console/console.h"
#include "map/hardware_map.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


/* Private defines */

#define CONSOLE_BUFFER_SIZE 256

/* Private typedefs */

/* Private function prototype */

/* Private variables */

static char gBuffer[CONSOLE_BUFFER_SIZE];

static const char *gcStringLevel[CONSOLE_END] = {"LOG", "WARNING", "ERROR"};

/* Function definitions */

void console_Init()
{
}

void console_PrintF(eConsole_LogLevel_t eLevel, const char *fmt, ...)
{
    /* Write log level prefix */

	const char *cLevel = gcStringLevel[eLevel];

    int offset = snprintf(gBuffer, sizeof(gBuffer), "[%s] ", cLevel);

    if (offset >= 0 && offset < CONSOLE_BUFFER_SIZE)
    {
		/* Format user message */
		va_list args;
		va_start(args, fmt);
		vsnprintf(gBuffer + offset, CONSOLE_BUFFER_SIZE - offset, fmt, args);
		va_end(args);

		/* Add newline */
		strncat(gBuffer, "\r\n", CONSOLE_BUFFER_SIZE - strlen(gBuffer) - 1);

		/* Blocking transmit */
		HAL_UART_Transmit(CONSOLE_UART, (uint8_t*)gBuffer, strlen(gBuffer), HAL_MAX_DELAY);
    }
}
