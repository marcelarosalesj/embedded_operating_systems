/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

SemaphoreHandle_t xMutex;
#define MAX_NUM	100

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void write_task_1(void *pvParameters);
static void write_task_2(void *pvParameters);
static void write_task_3(void *pvParameters);
static void write_task_4(void *pvParameters);
static void write_task_5(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    xMutex = xSemaphoreCreateMutex();

    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    if (xTaskCreate(write_task_1, "WRITE_TASK_1", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(write_task_2, "WRITE_TASK_2", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    if (xTaskCreate(write_task_3, "WRITE_TASK_3", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
            pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
	if (xTaskCreate(write_task_4, "WRITE_TASK_4", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
	if (xTaskCreate(write_task_5, "WRITE_TASK_5", configMINIMAL_STACK_SIZE + 128, NULL, tskIDLE_PRIORITY + 1, NULL) !=
		pdPASS)
	{
		PRINTF("Task creation failed!.\r\n");
		while (1)
			;
	}
    /* Start scheduling. */
    vTaskStartScheduler();
    for (;;)
        ;
}

static void write_task_1(void *pvParameters)
{
    for(int i=0; i<MAX_NUM; i++)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("A[%d]\r\n", i);
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}

static void write_task_2(void *pvParameters)
{
	for(int i=0; i<MAX_NUM; i++)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("B[%d]\r\n", i);
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}

static void write_task_3(void *pvParameters)
{
    for(int i=0; i<MAX_NUM; i++)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("C[%d]\r\n", i);
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}

static void write_task_4(void *pvParameters)
{
    for(int i=0; i<MAX_NUM; i++)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("D[%d]\r\n", i);
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}

static void write_task_5(void *pvParameters)
{
    for(int i=0; i<MAX_NUM; i++)
    {
        xSemaphoreTake(xMutex, portMAX_DELAY);
        PRINTF("E[%d]\r\n", i);
        xSemaphoreGive(xMutex);
        taskYIELD();
    }
}

