


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

/******************************** Includes ************************************/
#include "../include/ESP32_Robot.h"

/******************************** Defines ************************************/
//Priorities for Rtos tasks
#define HIGH_PRIORITY 1
#define MED_PRIORITY 2
#define LOW_PRIORITY 3
//Other defines


//to use c and c++ functions
extern "C" {
	void app_main();
}


/*
 * Main
*/
void app_main()
{

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is ESP32 chip with %d CPU cores, WiFi%s%s, ",
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    /*
     * Create different Tasks
     * 	-sensor_task -> reading and processing sensor values
     * 	-wifi_task -> communication to host pc for mapping
     * 	-control_task -> control movement of the robot
     *
     *ToDo: Add Queues to Task to exchange data between tasks
     *ToDo: 	-> for example struct lsr_msg from sensor_task to wif_task to send data via wifi to host pc
     */

    //sensor_task
    TaskHandle_t sensor_handle = NULL;
    xTaskCreate(sensor_task, "sensor_task", 2000, NULL, MED_PRIORITY, &sensor_handle);

    //maybe not needed and implement in main loop
    //wifi_task
    TaskHandle_t wifi_handle = NULL;
    xTaskCreate(wifi_task, "wifi_task", 2000, NULL, LOW_PRIORITY, &wifi_handle);

    //control_task
    TaskHandle_t control_handle = NULL;
    xTaskCreate(control_task, "control_task", 2000, NULL, HIGH_PRIORITY, &control_handle);

}
