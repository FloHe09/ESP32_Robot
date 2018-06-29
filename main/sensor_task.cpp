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

#define STEPS_MEASURE 	 8												//The number of steps between two measurements

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

/*
 * Struct to save motor data
 */
struct motor_data {
	gpio_num_t in1;														//Input 1 of the ULN2003
	gpio_num_t in2;														//Input 2 of the ULN2003
	gpio_num_t in3;														//Input 3 of the ULN2003
	gpio_num_t in4;														//Input 4 of the ULN2003
	uint16_t steps_full_rev;											//Number of steps for 1 revolution with the gear
	uint8_t resolution;													//resolution of the motor gear
	uint16_t max_freq;													//set the max frequency of the motor
	uint16_t steps_to_go;												//steps_to_go for a full resolution of the shaft
	uint16_t step;														//the actual number of step
	uint8_t steps_at_a_time;											//number of steps in one do_steps() call
	unsigned long last_step;											//time in micro seconds of the last step
	bool cw;															//direction of the motor true = cw or false = ccw
};



float read_sensor_value() {
 //return dummy value
	return 1;
}


void do_steps(struct motor_data *motor, uint8_t steps) {
	for (int i = 0; i < steps; i++) {
		//
		switch(motor->step % 8) {
		case 0:
			gpio_set_level(motor->in1, 0);
			gpio_set_level(motor->in2, 0);
			gpio_set_level(motor->in3, 0);
			gpio_set_level(motor->in4, 1);
			break;
		case 1:
			gpio_set_level(motor->in1, 0);
			gpio_set_level(motor->in2, 0);
			gpio_set_level(motor->in3, 1);
			gpio_set_level(motor->in4, 1);
			break;
		case 2:
			gpio_set_level(motor->in1, 0);
			gpio_set_level(motor->in2, 0);
			gpio_set_level(motor->in3, 1);
			gpio_set_level(motor->in4, 0);
			break;
		case 3:
			gpio_set_level(motor->in1, 0);
			gpio_set_level(motor->in2, 1);
			gpio_set_level(motor->in3, 1);
			gpio_set_level(motor->in4, 0);
			break;
		case 4:
			gpio_set_level(motor->in1, 0);
			gpio_set_level(motor->in2, 1);
			gpio_set_level(motor->in3, 0);
			gpio_set_level(motor->in4, 0);
			break;
		case 5:
			gpio_set_level(motor->in1, 1);
			gpio_set_level(motor->in2, 1);
			gpio_set_level(motor->in3, 0);
			gpio_set_level(motor->in4, 0);
			break;
		case 6:
			gpio_set_level(motor->in1, 1);
			gpio_set_level(motor->in2, 0);
			gpio_set_level(motor->in3, 0);
			gpio_set_level(motor->in4, 0);
			break;
		case 7:
			gpio_set_level(motor->in1, 1);
			gpio_set_level(motor->in2, 0);
			gpio_set_level(motor->in3, 0);
			gpio_set_level(motor->in4, 1);
			break;
		default:
			gpio_set_level(motor->in1, 0);
			gpio_set_level(motor->in2, 0);
			gpio_set_level(motor->in3, 0);
			gpio_set_level(motor->in4, 0);
			break;
		}
		//increment if cw or decrement if ccw the number of steps
		if(motor->cw) {
			motor->step += 1;
		} else {
			motor->step -= 1;
		}
		//turn the direction if reached end or start position
		if(motor->step == 0 || motor->step == motor->steps_full_rev) {
			motor->cw = !motor->cw;
		}
	}
}



/*
 * task for reading sensor and control the stepper motor for LIDAR
 */
void sensor_task(void *pvParameters) {
	const TickType_t delay_in_ms = 100/ portTICK_PERIOD_MS;

	struct motor_data stepper_motor = {};

	//continouus loop
	for(;;){

		//
		do_steps(&stepper_motor, STEPS_MEASURE);


		//delay
		vTaskDelay(delay_in_ms);
	}
}
