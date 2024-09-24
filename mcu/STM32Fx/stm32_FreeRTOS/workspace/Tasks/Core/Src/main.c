/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"

// #define TASKS
// #define TASKS_DELAY
#define PERIODIC_TASKS

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
extern void initialise_monitor_handles(void);
static void task1_handler(void* parameters);
static void task2_handler(void* parameters);
static void task3_handler(void* parameters);

int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Configure OpenOCD */
  initialise_monitor_handles();

  /* Task handlers */
  TaskHandle_t task1_handle;
  TaskHandle_t task2_handle;
  TaskHandle_t task3_handle;

  /* Task status */
  BaseType_t status_t1 = 0;
  BaseType_t status_t2 = 0;
  BaseType_t status_t3 = 0;

  // Creating tasks with 200 words stack and priority 2, tasks allocated on HEAP
  status_t1 = xTaskCreate(task1_handler, "Task-1", 200, "Task-1 Running", 2, &task1_handle);
  status_t2 = xTaskCreate(task2_handler, "Task-2", 200, "Task-2 Running", 1, &task2_handle);
  status_t3 = xTaskCreate(task3_handler, "Task-3", 200, "Task-3 Running", 2, &task3_handle);
  /*
    !If the task was created successfully then pdPASS is returned.
    !Otherwise errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY is returned.
  */
  configASSERT(status_t1 == pdPASS);
  configASSERT(status_t2 == pdPASS);
  configASSERT(status_t3 == pdPASS);

  /* Starting scheduler */
  vTaskStartScheduler();


  /* Infinite loop */
  while (1)
  {}
}

// #############################################################################################################
#ifdef TASKS
// Creates tasks yielding that gives up CPU so another task can run (Coop scheduling - No preemption tasks (configUSE_PREEMPTION = 0))
static void task1_handler(void* parameters)
{
  while (1)
  {
    printf("%s\n", (char*)parameters);
    taskYIELD();
  }
}

static void task2_handler(void* parameters)
{
  while (1)
  {
    printf("%s\n", (char*)parameters);
    taskYIELD();
  }
}

static void task3_handler(void* parameters)
{
  while (1)
  {
    printf("%s\n", (char*)parameters);
    taskYIELD();
  }
}
#endif


// #############################################################################################################
#ifdef TASKS_DELAY
// Creates Idle tasks saving CPU cycles and power
static void task1_handler(void* parameters)
{
  while (1)
  {
    printf("%s\n", (char*)parameters);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

static void task2_handler(void* parameters)
{
  while (1)
  {
    printf("%s\n", (char*)parameters);
    vTaskDelay(pdMS_TO_TICKS(800));
  }
}

static void task3_handler(void* parameters)
{
  while (1)
  {
    printf("%s\n", (char*)parameters);
    vTaskDelay(pdMS_TO_TICKS(400));
  }
}
#endif

// #############################################################################################################
#ifdef PERIODIC_TASKS
// Creates Idle tasks saving CPU cycles and power
static void task1_handler(void* parameters)
{
  TickType_t last_wakeup_time = xTaskGetTickCount();

  while (1)
  {
    printf("%s\n", (char*)parameters);
    vTaskDelayUntil(&last_wakeup_time, pdMS_TO_TICKS(1000));
  }
}

static void task2_handler(void* parameters)
{
  TickType_t last_wakeup_time = xTaskGetTickCount();

  while (1)
  {
    printf("%s\n", (char*)parameters);
    vTaskDelayUntil(&last_wakeup_time, pdMS_TO_TICKS(1000));
  }
}

static void task3_handler(void* parameters)
{
  TickType_t last_wakeup_time = xTaskGetTickCount();

  while (1)
  {
    printf("%s\n", (char*)parameters);
    vTaskDelayUntil(&last_wakeup_time, pdMS_TO_TICKS(1000));
  }
}
#endif

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
