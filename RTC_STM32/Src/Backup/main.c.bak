/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "main.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
	RTC_TimeTypeDef	sTime1;
	RTC_DateTypeDef sDate1;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hrtc;

	uint8_t buffer_dias[20];
	uint8_t buffer_tiempo[20];
  
	uint8_t digitos[20];
	
	
	uint16_t BaseDatosled [10] = {0x007E, 0x000C, 0x00B6, 0x009E, 0x00CC, 0x00DA, 0x00F8, 0x000E, 0x00FE, 0x00CE}; 

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_RTC_Init(void);
	
	uint8_t BCD_a_DEC(uint8_t data);
	
/* USER CODE BEGIN PFP */

void Get_rtc()
{
			//digitos[0]= 0x00;
			HAL_RTC_GetTime(&hrtc, &sTime1, RTC_FORMAT_BCD);
			HAL_RTC_GetDate(&hrtc, &sDate1, RTC_FORMAT_BCD);
		
			buffer_dias[0] =	(sDate1.Date / 16) + 48;
			buffer_dias[1] =	(sDate1.Date % 16) + 48;
			buffer_dias[2] =	'.';
			buffer_dias[3] =	(sDate1.Month / 16) + 48;
			buffer_dias[4] =	(sDate1.Month % 16) + 48;
			buffer_dias[5] = '.';
			buffer_dias[6] = '2';
			buffer_dias[7] = '0';
			buffer_dias[8] = (sDate1.Year / 16) + 48;
			buffer_dias[9] = (sDate1.Year % 16 ) + 48;
			buffer_tiempo[0] = '@';
			buffer_tiempo[1] = (sTime1.Hours /16) + 48;
			buffer_tiempo[2] = (sTime1.Hours % 16) + 48;
			buffer_tiempo[3] = ':';
			buffer_tiempo[4] = (sTime1.Minutes /16) + 48;
			buffer_tiempo[5] = (sTime1.Minutes % 16) + 48;
			buffer_tiempo[6] = ':';
			buffer_tiempo[7] = (sTime1.Seconds / 16) + 48;
			buffer_tiempo[8] = (sTime1.Seconds % 16) + 48;
			

			digitos[14] = (BCD_a_DEC(sTime1.Minutes) / 10);
		
			digitos[15] = (BCD_a_DEC(sTime1.Minutes) % 10);
			digitos[17] = (BCD_a_DEC(sTime1.Seconds) / 10);
			digitos[18] = (BCD_a_DEC(sTime1.Seconds) % 10);
      
}

		void encender_display ()
		{
			uint16_t digito1;
			
			
			GPIOA->ODR = ~(BaseDatosled[digitos[18]]); //Displaying 1
			//HAL_Delay(500);
			GPIOB->ODR = 0x0040;
			HAL_Delay(5);
			
			
			GPIOA->ODR = ~(BaseDatosled[digitos[17]]); //Displaying 2
			//HAL_Delay(500);
			GPIOB->ODR = 0x0080;
			HAL_Delay(5);
			
			GPIOB->ODR = 0x0100;
			//HAL_Delay(500);
			GPIOA->ODR = ~(BaseDatosled[digitos[15]]); //Displaying 3
			HAL_Delay(5);
			
			GPIOB->ODR = 0x0200;
		//	HAL_Delay(500);
			GPIOA->ODR = ~(BaseDatosled[digitos[14]]); //Displaying 4
			HAL_Delay(5);
			
			
		}
		
	
		
		
		// add function to convert  bcd to decimal and decimal to bcd

uint8_t BCD_a_DEC(uint8_t data){			// BCD to Decimal
	return (data>>4)*10+(data&0x0F);
}

uint8_t DEC_a_BCD(uint8_t data){			// Decimal to BCD
	return (data/10)<<4 | (data%10);
}
		

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	
	// RTC_DateTypeDef sDate1;
	
	
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		
		Get_rtc();
			
		encender_display();
			
			if(sTime1.Hours == 0x18)
		{
			if(sTime1.Minutes == 0x12)
		{
			if(sTime1.Seconds == 0x00)
			{
			
		//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			HAL_GPIO_WritePin(GPIOA, Led_motor_Pin, GPIO_PIN_SET);
			
		HAL_Delay(1000);
			}
		}
		
		}
		
		if(sTime1.Hours == 0x18)
		{
			if(sTime1.Minutes == 0x50)
		{
			if (sTime1.Seconds == 0x10)
			{
			
		//HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
			HAL_GPIO_WritePin(GPIOA, Led_motor_Pin, GPIO_PIN_RESET);
			
		HAL_Delay(1000);
			}
		}
		
		}
			
			
			
			//HAL_UART_Transmit(huart1, (uint8_t *) _out, strlen(_out), 10);
			//HAL_UART_Transmit(&huart1, (uint8_t *) buffer_dias, 10, 10);
			//HAL_UART_Transmit(&huart1, (uint8_t *) buffer_tiempo, 10, 10);
			char newline[2] = "\r\n";
			//HAL_UART_Transmit(&huart1, (uint8_t *) newline, 2, 10);
			//HAL_Delay(1000);

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef DateToUpdate = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only 
  */
  hrtc.Instance = RTC;
  hrtc.Init.AsynchPrediv = RTC_AUTO_1_SECOND;
  hrtc.Init.OutPut = RTC_OUTPUTSOURCE_NONE;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */
    
  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date 
  */
  sTime.Hours = 0x12;
  sTime.Minutes = 0x52;
  sTime.Seconds = 0x0;

  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  DateToUpdate.WeekDay = RTC_WEEKDAY_MONDAY;
  DateToUpdate.Month = RTC_MONTH_MARCH;
  DateToUpdate.Date = 0x16;
  DateToUpdate.Year = 0x20;

  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Digito_a_Pin|Digito_b_Pin|Digito_c_Pin|Digito_d_Pin 
                          |Digito_e_Pin|Digito_f_Pin|Digito_g_Pin|Led_motor_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Digito_1_Pin|Digito_2_Pin|Digito_3_Pin|Digito_4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA8 PA9 PA11 
                           PA12 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_11 
                          |GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Digito_a_Pin Digito_b_Pin Digito_c_Pin Digito_d_Pin 
                           Digito_e_Pin Digito_f_Pin Digito_g_Pin Led_motor_Pin */
  GPIO_InitStruct.Pin = Digito_a_Pin|Digito_b_Pin|Digito_c_Pin|Digito_d_Pin 
                          |Digito_e_Pin|Digito_f_Pin|Digito_g_Pin|Led_motor_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Sumar_Pin Enter_Pin Restar_Pin */
  GPIO_InitStruct.Pin = Sumar_Pin|Enter_Pin|Restar_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB10 PB11 PB12 PB13 
                           PB14 PB15 PB3 PB4 
                           PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13 
                          |GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4 
                          |GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Digito_1_Pin Digito_2_Pin Digito_3_Pin Digito_4_Pin */
  GPIO_InitStruct.Pin = Digito_1_Pin|Digito_2_Pin|Digito_3_Pin|Digito_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
