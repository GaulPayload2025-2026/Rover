/*
 * app_main.c
 *
 *  Created on: Feb 20, 2026
 *      Author: Etienne
 */

/* Private includes */

#include "bno055/bno055.h"

/* Private defines */

/* Private typedefs */

typedef enum
{
	SM_ROVER_INIT = (0),
	SM_ROVER_PREFLIGHT,
	SM_ROVER_FLIGHT,
	SM_ROVER_POSTFLIGHT,
	SM_ROVER_IDLE
}
eSMRover_t;

/* Private variables */

static eSMRover_t geRoverState = SM_ROVER_INIT;

/* Private function prototype */


void app_main_Task(void)
{
	switch (geRoverState)
	{
	    case SM_ROVER_INIT:
	        bno055_Init();
	        break;
	    case SM_ROVER_PREFLIGHT:
	        // Preflight code
	        break;
	    case SM_ROVER_FLIGHT:
	        // Flight code
	        break;
	    case SM_ROVER_POSTFLIGHT:
	        // Postflight code
	        break;
	    case SM_ROVER_IDLE:
	        // Idle code
	        break;
	    default:
	        geRoverState = SM_ROVER_INIT;
	        break;
	}
}


