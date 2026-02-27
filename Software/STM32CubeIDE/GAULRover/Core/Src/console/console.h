/*
 * console.h
 *
 *  Created on: Feb 26, 2026
 *      Author: etien
 */

#ifndef SRC_CONSOLE_CONSOLE_H_
#define SRC_CONSOLE_CONSOLE_H_

#define LOG_INFO(fmt, ...)    console_PrintF(CONSOLE_LOG, fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...) console_PrintF(CONSOLE_WARNING, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)   console_PrintF(CONSOLE_ERROR, fmt, ##__VA_ARGS__)

typedef enum
{
	CONSOLE_LOG = (0),
	CONSOLE_WARNING,
	CONSOLE_ERROR,
	CONSOLE_END
} eConsole_LogLevel_t;

void console_Init();
void console_PrintF(eConsole_LogLevel_t level, const char *fmt, ...);

#endif /* SRC_CONSOLE_CONSOLE_H_ */
