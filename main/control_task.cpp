/*
 * control_task.cpp
 *
 * Task to:
 * 		-control the motordriver
 * 		-calculate the kinematic
 *
 *  Created on: 23.06.2018
 *      Author: flo
 */

#include "../include/control_task.h"


void control_task(void *pvParameters) {
	// set the delay at the end of task loop [ms]
	const TickType_t delay_in_ms = 100/ portTICK_PERIOD_MS;

	for(;;) {

		vTaskDelay(delay_in_ms);
	}
}


