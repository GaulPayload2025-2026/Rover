/*
 * sd.c
 *
 *  Created on: Feb 27, 2026
 *      Author: etien
 */

/* Private includes */

#include "sd/sd.h"
#include "fatfs.h"
#include "console/console.h"
#include <string.h>
#include <stdio.h>

/* Private defines */

/* Private typedefs */

/* Private function prototype */

/* Private variables */

static FATFS gFatFs;
static FIL gFile;
static FRESULT gFsRes;

/* Function definitions */

void sd_Init()
{
	//Open the file system
	gFsRes = f_mount(&gFatFs, "", 1);
	if (gFsRes != FR_OK)
	{
		LOG_ERROR("f_mount error (%i)\r\n", gFsRes);
		while(1);
	}
}

void sd_Test()
{
	//Let's get some statistics from the SD card
	DWORD free_clusters, free_sectors, total_sectors;
	FATFS* getFreeFs;

	gFsRes = f_getfree("", &free_clusters, &getFreeFs);
	if (gFsRes != FR_OK)
	{
		LOG_ERROR("f_getfree error (%i)\r\n", gFsRes);
		while(1);
	}

	//Formula comes from tutorial documentation
	total_sectors = (getFreeFs->n_fatent - 2) * getFreeFs->csize;
	free_sectors = free_clusters * getFreeFs->csize;

	LOG_INFO("SD card stats:\r\n%10lu KiB total drive space.\r\n%10lu KiB available.\r\n", total_sectors / 2, free_sectors / 2);

	//Now let's try to open file "test.txt"
	gFsRes = f_open(&gFile, "test.txt", FA_OPEN_ALWAYS);
	if (gFsRes != FR_OK) {
		LOG_ERROR("f_open error (%i)\r\n");
		while(1);
	}
	LOG_INFO("I was able to open 'test.txt' for reading!\r\n");

	//Read 30 bytes from "test.txt" on the SD card
	BYTE readBuf[30];

	//We can either use f_read OR f_gets to get data out of files
	//f_gets is a wrapper on f_read that does some string formatting for us
	TCHAR* rres = f_gets((TCHAR*)readBuf, 30, &gFile);
	if(rres != 0) {
		LOG_INFO("Read string from 'test.txt' contents: %s\r\n", readBuf);
	} else {
		LOG_ERROR("f_gets error (%i)\r\n", gFsRes);
	}

	//Be a tidy kiwi - don't forget to close your file!
	f_close(&gFile);

	//Now let's try and write a file "write.txt"
	gFsRes = f_open(&gFile, "write.txt", FA_WRITE | FA_OPEN_ALWAYS | FA_CREATE_ALWAYS);
	if(gFsRes == FR_OK)
	{
		LOG_INFO("I was able to open 'write.txt' for writing\r\n");
	}
	else
	{
		LOG_ERROR("f_open error (%i)\r\n", gFsRes);
	}

	//Copy in a string
	snprintf((char*)readBuf, sizeof(readBuf), "a new file is made!");
	UINT bytesWrote;
	gFsRes = f_write(&gFile, readBuf, 19, &bytesWrote);
	if(gFsRes == FR_OK)
	{
		LOG_INFO("Wrote %i bytes to 'write.txt'!\r\n", bytesWrote);
	}
	else
	{
		LOG_ERROR("f_write error (%i)\r\n");
	}

	//don't forget to close your file
	f_close(&gFile);

	//de-mount the drive
	f_mount(NULL, "", 0);
}
