/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CN2_STMOD_UART_SEL_Pin GPIO_PIN_15
#define CN2_STMOD_UART_SEL_GPIO_Port GPIOH
#define STMD_PWR_EN_Pin GPIO_PIN_4
#define STMD_PWR_EN_GPIO_Port GPIOB
#define STMD_RING_Pin GPIO_PIN_6
#define STMD_RING_GPIO_Port GPIOE
#define STMD_RING_EXTI_IRQn EXTI6_IRQn
#define STMD_SIM_DATA_Pin GPIO_PIN_5
#define STMD_SIM_DATA_GPIO_Port GPIOD
#define STMD_SIM_SELECT1_Pin GPIO_PIN_12
#define STMD_SIM_SELECT1_GPIO_Port GPIOC
#define STMD_SIM_SELECT0_Pin GPIO_PIN_2
#define STMD_SIM_SELECT0_GPIO_Port GPIOD
#define STMD_DTR_Pin GPIO_PIN_9
#define STMD_DTR_GPIO_Port GPIOC
#define STMD_SIM_DATAG1_Pin GPIO_PIN_1
#define STMD_SIM_DATAG1_GPIO_Port GPIOG
#define STMD_SIM_CLK_Pin GPIO_PIN_0
#define STMD_SIM_CLK_GPIO_Port GPIOG
#define STMD_RESET_Pin GPIO_PIN_13
#define STMD_RESET_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
