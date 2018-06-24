/*
 * sensor_task.h
 *
 *  Created on: 23.06.2018
 *      Author: flo
 */

#ifndef INCLUDE_SENSOR_TASK_H_
#define INCLUDE_SENSOR_TASK_H_

#include "Stepper.h"



/*
 * The actually task for reading and processing the sensor values
 */
void sensor_task(void *pvParameters);

#endif /* INCLUDE_SENSOR_TASK_H_ */
