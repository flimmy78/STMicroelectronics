/**
  ******************************************************************************
  * @file    STM32F4xx_dual.h
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file contains definitions for STM32F4xx_dual's Leds, push-buttons
  *          COM ports, SD Card (on SPI), sFLASH (on SPI) and Temperature sensor 
  *          LM75 (on I2C) hardware resources.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4XX_DUAL_H
#define __STM32F4XX_DUAL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32_eval.h"
#include "stm32f4xx_spi.h"
#include "stm32f4xx_i2c.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32_EVAL
  * @{
  */
    
/** @addtogroup STM32F4XX_DUAL
  * @{
  */ 

/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL
  * @{
  */
  
/** @defgroup STM32F4XX_DUAL_LOW_LEVEL_Exported_Types
  * @{
  */
/**
  * @}
  */


/** @defgroup STM32F4XX_DUAL_LOW_LEVEL_Exported_Constants
  * @{
  */ 
/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL_LED
  * @{
  */
#define LEDn                             4
#define LED1_PIN                         GPIO_Pin_1
#define LED1_GPIO_PORT                   GPIOE
#define LED1_GPIO_CLK                    RCC_AHB1Periph_GPIOE
  
#define LED2_PIN                         GPIO_Pin_2
#define LED2_GPIO_PORT                   GPIOE
#define LED2_GPIO_CLK                    RCC_AHB1Periph_GPIOE

#define LED3_PIN                         GPIO_Pin_3  
#define LED3_GPIO_PORT                   GPIOE
#define LED3_GPIO_CLK                    RCC_AHB1Periph_GPIOE
  
#define LED4_PIN                         GPIO_Pin_4
#define LED4_GPIO_PORT                   GPIOE
#define LED4_GPIO_CLK                    RCC_AHB1Periph_GPIOE

/**
  * @}
  */ 
  
/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL_BUTTON
  * @{
  */  
#define BUTTONn                          8

/**
 * @brief Wakeup push-button
 */
#define WAKEUP_BUTTON_PIN                GPIO_Pin_6
#define WAKEUP_BUTTON_GPIO_PORT          GPIOG
#define WAKEUP_BUTTON_GPIO_CLK           RCC_AHB1Periph_GPIOG
#define WAKEUP_BUTTON_EXTI_LINE          EXTI_Line0
#define WAKEUP_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOA
#define WAKEUP_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource0
#define WAKEUP_BUTTON_EXTI_IRQn          EXTI0_IRQn 
/**
 * @brief Tamper push-button
 */
#define TAMPER_BUTTON_PIN                GPIO_Pin_7
#define TAMPER_BUTTON_GPIO_PORT          GPIOG
#define TAMPER_BUTTON_GPIO_CLK           RCC_AHB1Periph_GPIOG
#define TAMPER_BUTTON_EXTI_LINE          EXTI_Line13
#define TAMPER_BUTTON_EXTI_PORT_SOURCE   EXTI_PortSourceGPIOC
#define TAMPER_BUTTON_EXTI_PIN_SOURCE    EXTI_PinSource13
#define TAMPER_BUTTON_EXTI_IRQn          EXTI15_10_IRQn 
/**
 * @brief Key push-button
 */
#define KEY_BUTTON_PIN                   GPIO_Pin_5
#define KEY_BUTTON_GPIO_PORT             GPIOG
#define KEY_BUTTON_GPIO_CLK              RCC_AHB1Periph_GPIOG
#define KEY_BUTTON_EXTI_LINE             EXTI_Line9
#define KEY_BUTTON_EXTI_PORT_SOURCE      EXTI_PortSourceGPIOB
#define KEY_BUTTON_EXTI_PIN_SOURCE       EXTI_PinSource9
#define KEY_BUTTON_EXTI_IRQn             EXTI9_5_IRQn
/**
 * @brief Joystick Right push-button
 */
#define RIGHT_BUTTON_PIN                 GPIO_Pin_1
#define RIGHT_BUTTON_GPIO_PORT           GPIOG
#define RIGHT_BUTTON_GPIO_CLK            RCC_AHB1Periph_GPIOG
#define RIGHT_BUTTON_EXTI_LINE           EXTI_Line0
#define RIGHT_BUTTON_EXTI_PORT_SOURCE    EXTI_PortSourceGPIOE
#define RIGHT_BUTTON_EXTI_PIN_SOURCE     EXTI_PinSource0
#define RIGHT_BUTTON_EXTI_IRQn           EXTI0_IRQn
/**
 * @brief Joystick Left push-button
 */
#define LEFT_BUTTON_PIN                  GPIO_Pin_2
#define LEFT_BUTTON_GPIO_PORT            GPIOG
#define LEFT_BUTTON_GPIO_CLK             RCC_AHB1Periph_GPIOG   
#define LEFT_BUTTON_EXTI_LINE            EXTI_Line1
#define LEFT_BUTTON_EXTI_PORT_SOURCE     EXTI_PortSourceGPIOE
#define LEFT_BUTTON_EXTI_PIN_SOURCE      EXTI_PinSource1
#define LEFT_BUTTON_EXTI_IRQn            EXTI1_IRQn  
/**
 * @brief Joystick Up push-button
 */
#define UP_BUTTON_PIN                    GPIO_Pin_0
#define UP_BUTTON_GPIO_PORT              GPIOG
#define UP_BUTTON_GPIO_CLK               RCC_AHB1Periph_GPIOG
#define UP_BUTTON_EXTI_LINE              EXTI_Line8
#define UP_BUTTON_EXTI_PORT_SOURCE       EXTI_PortSourceGPIOD
#define UP_BUTTON_EXTI_PIN_SOURCE        EXTI_PinSource8
#define UP_BUTTON_EXTI_IRQn              EXTI9_5_IRQn  
/**
 * @brief Joystick Down push-button
 */  
#define DOWN_BUTTON_PIN                  GPIO_Pin_3
#define DOWN_BUTTON_GPIO_PORT            GPIOG
#define DOWN_BUTTON_GPIO_CLK             RCC_AHB1Periph_GPIOG
#define DOWN_BUTTON_EXTI_LINE            EXTI_Line14
#define DOWN_BUTTON_EXTI_PORT_SOURCE     EXTI_PortSourceGPIOD
#define DOWN_BUTTON_EXTI_PIN_SOURCE      EXTI_PinSource14
#define DOWN_BUTTON_EXTI_IRQn            EXTI15_10_IRQn  
/**
 * @brief Joystick Sel push-button
 */
#define SEL_BUTTON_PIN                   GPIO_Pin_4
#define SEL_BUTTON_GPIO_PORT             GPIOG
#define SEL_BUTTON_GPIO_CLK              RCC_AHB1Periph_GPIOG
#define SEL_BUTTON_EXTI_LINE             EXTI_Line12
#define SEL_BUTTON_EXTI_PORT_SOURCE      EXTI_PortSourceGPIOD
#define SEL_BUTTON_EXTI_PIN_SOURCE       EXTI_PinSource12
#define SEL_BUTTON_EXTI_IRQn             EXTI15_10_IRQn   
/**
 * @brief Re-definition for STEVAL-IHM039V1
 */
#define BUTTON_1 BUTTON_KEY
#define BUTTON_2 BUTTON_WAKEUP
#define BUTTON_3 BUTTON_TAMPER
   
/**
  * @}
  */ 
   
/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL_COM
  * @{
  */
#define COMn                             2

/**
 * @brief Definition for COM port1, connected to USART1
 */ 
#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2Periph_USART1
#define EVAL_COM1_TX_PIN                 GPIO_Pin_9
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHB1Periph_GPIOA
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource9
#define EVAL_COM1_TX_AF                  GPIO_AF_USART1
#define EVAL_COM1_RX_PIN                 GPIO_Pin_10
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHB1Periph_GPIOA
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource10
#define EVAL_COM1_RX_AF                  GPIO_AF_USART1
#define EVAL_COM1_IRQn                   USART1_IRQn

/**
 * @brief Definition for COM port2, connected to USART2 (USART2 pins remapped on GPIOD)
 */ 
#define EVAL_COM2                        USART2
#define EVAL_COM2_CLK                    RCC_APB1Periph_USART2
#define EVAL_COM2_TX_PIN                 GPIO_Pin_5
#define EVAL_COM2_TX_GPIO_PORT           GPIOD
#define EVAL_COM2_TX_GPIO_CLK            RCC_AHB1Periph_GPIOD
#define EVAL_COM2_TX_SOURCE              GPIO_PinSource5
#define EVAL_COM2_TX_AF                  GPIO_AF_USART2
#define EVAL_COM2_RX_PIN                 GPIO_Pin_6
#define EVAL_COM2_RX_GPIO_PORT           GPIOD
#define EVAL_COM2_RX_GPIO_CLK            RCC_AHB1Periph_GPIOD
#define EVAL_COM2_RX_SOURCE              GPIO_PinSource6
#define EVAL_COM2_RX_AF                  GPIO_AF_USART2
#define EVAL_COM2_IRQn                   USART2_IRQn

/**
  * @}
  */ 

/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL_SD_SPI
  * @{
  */
/**
  * @brief  SD SPI Interface pins
  */
#define SD_SPI                           SPI1
#define SD_SPI_CLK                       RCC_APB2Periph_SPI1
#define SD_SPI_SCK_PIN                   GPIO_Pin_5                  /* PA.05 */
#define SD_SPI_SCK_GPIO_PORT             GPIOA                       /* GPIOA */
#define SD_SPI_SCK_GPIO_CLK              RCC_APB2Periph_GPIOA
#define SD_SPI_MISO_PIN                  GPIO_Pin_6                  /* PA.06 */
#define SD_SPI_MISO_GPIO_PORT            GPIOA                       /* GPIOA */
#define SD_SPI_MISO_GPIO_CLK             RCC_APB2Periph_GPIOA
#define SD_SPI_MOSI_PIN                  GPIO_Pin_7                  /* PA.07 */
#define SD_SPI_MOSI_GPIO_PORT            GPIOA                       /* GPIOA */
#define SD_SPI_MOSI_GPIO_CLK             RCC_APB2Periph_GPIOA
#define SD_CS_PIN                        GPIO_Pin_12                 /* PC.12 */
#define SD_CS_GPIO_PORT                  GPIOC                       /* GPIOC */
#define SD_CS_GPIO_CLK                   RCC_APB2Periph_GPIOC
#define SD_DETECT_PIN                    GPIO_Pin_7                  /* PE.07 */
#define SD_DETECT_GPIO_PORT              GPIOE                       /* GPIOE */
#define SD_DETECT_GPIO_CLK               RCC_APB2Periph_GPIOE

/**
  * @}
  */

/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL_M25P_FLASH_SPI
  * @{
  */
/**
  * @brief  M25P FLASH SPI Interface pins
  */  
#define sFLASH_SPI                       SPI1
#define sFLASH_SPI_CLK                   RCC_APB2Periph_SPI1
#define sFLASH_SPI_SCK_PIN               GPIO_Pin_5                  /* PA.05 */
#define sFLASH_SPI_SCK_GPIO_PORT         GPIOA                       /* GPIOA */
#define sFLASH_SPI_SCK_GPIO_CLK          RCC_APB2Periph_GPIOA
#define sFLASH_SPI_MISO_PIN              GPIO_Pin_6                  /* PA.06 */
#define sFLASH_SPI_MISO_GPIO_PORT        GPIOA                       /* GPIOA */
#define sFLASH_SPI_MISO_GPIO_CLK         RCC_APB2Periph_GPIOA
#define sFLASH_SPI_MOSI_PIN              GPIO_Pin_7                  /* PA.07 */
#define sFLASH_SPI_MOSI_GPIO_PORT        GPIOA                       /* GPIOA */
#define sFLASH_SPI_MOSI_GPIO_CLK         RCC_APB2Periph_GPIOA
#define sFLASH_CS_PIN                    GPIO_Pin_4                  /* PA.04 */
#define sFLASH_CS_GPIO_PORT              GPIOA                       /* GPIOA */
#define sFLASH_CS_GPIO_CLK               RCC_APB2Periph_GPIOA 

/**
  * @}
  */

/** @addtogroup STM32F4XX_DUAL_LOW_LEVEL_TSENSOR_I2C
  * @{
  */
/**
  * @brief  LM75 Temperature Sensor I2C Interface pins
  */  
#define LM75_I2C                         I2C1
#define LM75_I2C_CLK                     RCC_APB1Periph_I2C1
#define LM75_I2C_SCL_PIN                 GPIO_Pin_6                  /* PB.06 */
#define LM75_I2C_SCL_GPIO_PORT           GPIOB                       /* GPIOB */
#define LM75_I2C_SCL_GPIO_CLK            RCC_APB2Periph_GPIOB
#define LM75_I2C_SDA_PIN                 GPIO_Pin_7                  /* PB.07 */
#define LM75_I2C_SDA_GPIO_PORT           GPIOB                       /* GPIOB */
#define LM75_I2C_SDA_GPIO_CLK            RCC_APB2Periph_GPIOB
#define LM75_I2C_SMBUSALERT_PIN          GPIO_Pin_5                  /* PB.05 */
#define LM75_I2C_SMBUSALERT_GPIO_PORT    GPIOB                       /* GPIOB */
#define LM75_I2C_SMBUSALERT_GPIO_CLK     RCC_APB2Periph_GPIOB

/**
  * @}
  */
    
/**
  * @}
  */ 
  
/** @defgroup STM32F4XX_DUAL_LOW_LEVEL_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup STM32F4XX_DUAL_LOW_LEVEL_Exported_Functions
  * @{
  */ 
void STM_EVAL_LEDInit(Led_TypeDef Led);
void STM_EVAL_LEDOn(Led_TypeDef Led);
void STM_EVAL_LEDOff(Led_TypeDef Led);
void STM_EVAL_LEDToggle(Led_TypeDef Led);
void STM_EVAL_PBInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t STM_EVAL_PBGetState(Button_TypeDef Button);
void STM_EVAL_COMInit(COM_TypeDef COM, USART_InitTypeDef* USART_InitStruct);
void SD_LowLevel_DeInit(void);
void SD_LowLevel_Init(void); 
void sFLASH_LowLevel_DeInit(void);
void sFLASH_LowLevel_Init(void); 
void LM75_LowLevel_DeInit(void);
void LM75_LowLevel_Init(void); 

void STM_EVAL_JOYInit(void);
 
/**
  * @}
  */ 
    
#ifdef __cplusplus
}
#endif
  
#endif /* __STM32F4XX_DUAL_H */
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */  

/**
  * @}
  */    

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
