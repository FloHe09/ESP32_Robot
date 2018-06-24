/*
 * sensor_task.cpp
 *
 *  Created on: 23.06.2018
 *      Author: flo
 */
#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


#include "../include/sensor_task.h"

#define MAX_ENTRY_LSR_MSG 100


//Define Structs

/*
 * Ros GMapping Laser_msg
 */
struct lsr_msg {
	float angle_min;													//start angle of the scan [rad]
	float anle_max;														//end angle of the scan [rad]
	float angel_increment;												//angular distance between measurements [rad]
	float time_increment;												//time between measurements [seconds]
	float scan_time;													//time between scans [seconds]
	float range_min;													//min range in [m]
	float range_max;													//max range in [m]
	float ranges[MAX_ENTRY_LSR_MSG]; 									//range data in [m]
	//float intensities[MAX_ENTRY_LSR_MSG];
};




float read_sensor_value() {
 //return dummy value
	return 1;
}


/*
 * task for reading sensor and control the stepper motor for LIDAR
 */
void sensor_task(void *pvParameters) {
	const TickType_t delay_in_ms = 100/ portTICK_PERIOD_MS;

	//continouus loop
	for(;;){



		//delay
		vTaskDelay(delay_in_ms);
	}
}




