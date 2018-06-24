/*
 * wifi_task.cpp
 *
 * Task to:
 * 		-handle wifi connection to host pc
 *
 *  Created on: 23.06.2018
 *      Author: flo
 */

#include "../include/wifi_task.h"


void wifi_task(void *pvParameters) {
	// set the delay at the end of task loop [ms]
	const TickType_t delay_in_ms = 100/ portTICK_PERIOD_MS;

	for(;;) {

		vTaskDelay(delay_in_ms);
	}
}
