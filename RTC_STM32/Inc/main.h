/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define Digito_a_Pin GPIO_PIN_1
#define Digito_a_GPIO_Port GPIOA
#define Digito_b_Pin GPIO_PIN_2
#define Digito_b_GPIO_Port GPIOA
#define Digito_c_Pin GPIO_PIN_3
#define Digito_c_GPIO_Port GPIOA
#define Digito_d_Pin GPIO_PIN_4
#define Digito_d_GPIO_Port GPIOA
#define Digito_e_Pin GPIO_PIN_5
#define Digito_e_GPIO_Port GPIOA
#define Digito_f_Pin GPIO_PIN_6
#define Digito_f_GPIO_Port GPIOA
#define Digito_g_Pin GPIO_PIN_7
#define Digito_g_GPIO_Port GPIOA
#define Sumar_Pin GPIO_PIN_0
#define Sumar_GPIO_Port GPIOB
#define Enter_Pin GPIO_PIN_1
#define Enter_GPIO_Port GPIOB
#define Restar_Pin GPIO_PIN_2
#define Restar_GPIO_Port GPIOB
#define Boton_subir_Pin GPIO_PIN_12
#define Boton_subir_GPIO_Port GPIOB
#define Boton_Enter_Pin GPIO_PIN_13
#define Boton_Enter_GPIO_Port GPIOB
#define Boton_bajar_Pin GPIO_PIN_14
#define Boton_bajar_GPIO_Port GPIOB
#define Led_motor_Pin GPIO_PIN_10
#define Led_motor_GPIO_Port GPIOA
#define Digito_1_Pin GPIO_PIN_6
#define Digito_1_GPIO_Port GPIOB
#define Digito_2_Pin GPIO_PIN_7
#define Digito_2_GPIO_Port GPIOB
#define Digito_3_Pin GPIO_PIN_8
#define Digito_3_GPIO_Port GPIOB
#define Digito_4_Pin GPIO_PIN_9
#define Digito_4_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
