/**
  ******************************************************************************
  * @file    Parameters conversion_F10X motor 2.h
  * @author  STMicroelectronics - System Lab - MC Team
  * @version 4.3.0
  * @date    22-Sep-2016 15:29
  * @brief   This file implements the Parameter conversion on the base
  *          of stdlib F10x for the second drive
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2016 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PARAMETERS_CONVERSION_F10X_MOTOR2_H
#define __PARAMETERS_CONVERSION_F10X_MOTOR2_H

#include "Definitions.h"
#include "PMSM motor 2 parameters.h"
#include "Drive parameters motor 2.h"
#include "Power stage parameters motor 2.h"
#include "Control stage parameters motor 2.h"
#include "stm32f10x.h"

#include "Power stage parameters.h"
/************************* CPU & ADC PERIPHERAL CLOCK CONFIG ******************/

#if defined CPU_CLK_72_MHZ
#define ADC_CLOCK_DIVIDER2  RCC_PCLK2_Div6
#define TIM_CLOCK_DIVIDER2  1
#define ADV_TIM_CLK_MHz2    72uL/TIM_CLOCK_DIVIDER2
#define ADC_CLK_MHz2        12uL
#define ADC_CLK_MHz2        12uL
#define HALL_TIM_CLK2       SYSCLK_FREQ_72MHz

#elif defined CPU_CLK_56_MHZ
#define ADC_CLOCK_DIVIDER2  RCC_PCLK2_Div4
#define TIM_CLOCK_DIVIDER2  1
#define ADV_TIM_CLK_MHz2    56uL/TIM_CLOCK_DIVIDER2
#define ADC_CLK_MHz2        14uL
#define ADC_CLK_MHz2        14uL
#define HALL_TIM_CLK2       SYSCLK_FREQ_56MHz

#elif defined CPU_CLK_48_MHZ
#define ADC_CLOCK_DIVIDER2  RCC_PCLK2_Div4
#define TIM_CLOCK_DIVIDER2  1
#define ADV_TIM_CLK_MHz2    48uL/TIM_CLOCK_DIVIDER2
#define ADC_CLK_MHz2        12uL
#define ADC_CLK_MHz2        12uL
#define HALL_TIM_CLK2       SYSCLK_FREQ_48MHz

#elif defined CPU_CLK_24_MHZ
#define ADC_CLOCK_DIVIDER2  RCC_PCLK2_Div2
#define TIM_CLOCK_DIVIDER2  1
#define ADV_TIM_CLK_MHz2    24uL/TIM_CLOCK_DIVIDER2
#define ADC_CLK_MHz2        12uL
#define ADC_CLK_MHz2        12uL
#define HALL_TIM_CLK2       SYSCLK_FREQ_24MHz
#else
#endif

/************************* CONTROL FREQUENCIES & DELAIES **********************/
#define TF_REGULATION_RATE2 	(uint16_t) ((uint16_t)(PWM_FREQUENCY2)/REGULATION_EXECUTION_RATE2)
#define REP_COUNTER2 			(uint16_t) ((REGULATION_EXECUTION_RATE2 *2)-1u)

#define MEDIUM_FREQUENCY_TASK_RATE2		(uint16_t)SPEED_LOOP_FREQUENCY_HZ2

#define INRUSH_CURRLIMIT_DELAY_COUNTS2  (uint16_t)(INRUSH_CURRLIMIT_DELAY_MS2 * \
				   ((uint16_t)SPEED_LOOP_FREQUENCY_HZ)/1000u -1u)

#define MF_TASK_OCCURENCE_TICKS2  (SYS_TICK_FREQUENCY/MEDIUM_FREQUENCY_TASK_RATE2)-1u


/************ SENSORLESS REV-UP PARAMETERS ************************************/
#define FIRST_SLESS_ALGO_PHASE2 (ENABLE_SL_ALGO_FROM_PHASE2-1u)  
#if OPEN_LOOP_FOC2 == ENABLE

#define OPEN_LOOP2
#undef DEFAULT_TARGET_SPEED_RPM2
#define DEFAULT_TARGET_SPEED_RPM2       OPEN_LOOP_SPEED_RPM2

#undef PHASE1_DURATION2
#undef PHASE2_DURATION2
#undef PHASE3_DURATION2
#undef PHASE4_DURATION2
#undef PHASE5_DURATION2

#undef PHASE1_FINAL_SPEED_RPM2
#undef PHASE2_FINAL_SPEED_RPM2
#undef PHASE3_FINAL_SPEED_RPM2
#undef PHASE4_FINAL_SPEED_RPM2
#undef PHASE5_FINAL_SPEED_RPM2

#undef VARIANCE_THRESHOLD2
#undef CORD_VARIANCE_THRESHOLD2

/* Phase 1 */
#define PHASE1_DURATION2		    OPEN_LOOP_SPEED_RAMP_DURATION_MS2
#define PHASE1_FINAL_SPEED_RPM2	    OPEN_LOOP_SPEED_RPM2
/* Phase 2 */
#define PHASE2_DURATION2		  65535   /*milliseconds */
#define PHASE2_FINAL_SPEED_RPM2	  PHASE1_FINAL_SPEED_RPM2
/* Phase 3 */
#define PHASE3_DURATION2		  65535   /*milliseconds */
#define PHASE3_FINAL_SPEED_RPM2	  PHASE1_FINAL_SPEED_RPM2
/* Phase 4 */
#define PHASE4_DURATION2		  65535   /*milliseconds */
#define PHASE4_FINAL_SPEED_RPM2	  PHASE1_FINAL_SPEED_RPM2
/* Phase 5 */
#define PHASE5_DURATION2		  65535    /* milliseconds */
#define PHASE5_FINAL_SPEED_RPM2	  PHASE1_FINAL_SPEED_RPM2

#define VARIANCE_THRESHOLD2       0
#define CORD_VARIANCE_THRESHOLD2  0
#endif

/* Legacy for WB 4.0 Beta */
#if !defined(OPEN_LOOP_VF2)
#define OPEN_LOOP_VF2 FALSE
#endif
#if !defined(OPEN_LOOP_OFF2)
#define OPEN_LOOP_OFF2 4400
#endif
#if !defined(OPEN_LOOP_K2)
#define OPEN_LOOP_K2 44
#endif

/************************* OBSERVER PARAMETERS ********************************/
#define MAX_BEMF_VOLTAGE2  (uint16_t)((1.2*MAX_APPLICATION_SPEED2 *\
                           MOTOR_VOLTAGE_CONSTANT2*SQRT_2)/(1000u*SQRT_3))

#if (BUS_VOLTAGE_READING2 == ENABLE)
/*max phase voltage, 0-peak Volts*/
#define MAX_VOLTAGE2 (int16_t)((MCU_SUPPLY_VOLTAGE/2)/BUS_ADC_CONV_RATIO2) 
#else
#define MAX_VOLTAGE2 (int16_t)(500/2) /* Virtual sensor conversion factor */
#endif

#ifdef ICS_SENSORS2 
#define MAX_CURRENT2 (MCU_SUPPLY_VOLTAGE/(2*AMPLIFICATION_GAIN2))
#else
#define MAX_CURRENT2 (MCU_SUPPLY_VOLTAGE/(2*RSHUNT2*AMPLIFICATION_GAIN2))
#endif

#define C12 (int32_t)((((int16_t)F12)*RS2)/(LS2*TF_REGULATION_RATE2))
#define C22 (int32_t) GAIN12
#define C32 (int32_t)((((int16_t)F12)*MAX_BEMF_VOLTAGE2)/(LS2*MAX_CURRENT2*TF_REGULATION_RATE2))
#define C42 (int32_t) GAIN22
#define C52 (int32_t)((((int16_t)F12)*MAX_VOLTAGE2)/(LS2*MAX_CURRENT2*TF_REGULATION_RATE2))

#define PERCENTAGE_FACTOR2    (uint16_t)(VARIANCE_THRESHOLD2*128u)      
#define OBS_MINIMUM_SPEED2        (uint16_t) (OBS_MINIMUM_SPEED_RPM2/6u)
#define HFI_MINIMUM_SPEED2        (uint16_t) (HFI_MINIMUM_SPEED_RPM2/6u)

/*********************** OBSERVER + CORDIC PARAMETERS *************************/
#define CORD_C12 (int32_t)((((int16_t)CORD_F12)*RS)/(LS*TF_REGULATION_RATE))
#define CORD_C22 (int32_t) CORD_GAIN12
#define CORD_C32 (int32_t)((((int16_t)CORD_F12)*MAX_BEMF_VOLTAGE)/(LS*MAX_CURRENT\
                                                           *TF_REGULATION_RATE))
#define CORD_C42 (int32_t) CORD_GAIN2
#define CORD_C52 (int32_t)((((int16_t)CORD_F12)*MAX_VOLTAGE2)/(LS2*MAX_CURRENT2*\
                                                          TF_REGULATION_RATE2))
#define CORD_PERCENTAGE_FACTOR2    (uint16_t)(CORD_VARIANCE_THRESHOLD2*128u)      
#define CORD_MINIMUM_SPEED2        (uint16_t) (CORD_MINIMUM_SPEED_RPM2/6u)

/**************************   VOLTAGE CONVERSIONS  ****************************/
#define BUS_ADC_CONV_RATIO2       VBUS_PARTITIONING_FACTOR2

#define OVERVOLTAGE_THRESHOLD_d2   (uint16_t)(OV_VOLTAGE_THRESHOLD_V2*65535/\
                                  (MCU_SUPPLY_VOLTAGE/VBUS_PARTITIONING_FACTOR2))
#define UNDERVOLTAGE_THRESHOLD_d2  (uint16_t)((UD_VOLTAGE_THRESHOLD_V2*65535)/\
                                  ((uint16_t)(MCU_SUPPLY_VOLTAGE/\
                                                           BUS_ADC_CONV_RATIO2)))

#define INT_SUPPLY_VOLTAGE2          (uint16_t)(65536/MCU_SUPPLY_VOLTAGE)

#define DELTA_TEMP_THRESHOLD2        (OV_TEMPERATURE_THRESHOLD_C2- T0_C2)
#define DELTA_V_THRESHOLD2           (dV_dT2 * DELTA_TEMP_THRESHOLD2)
#define OV_TEMPERATURE_THRESHOLD_d2  ((V0_V2 + DELTA_V_THRESHOLD2)*INT_SUPPLY_VOLTAGE2)

#define DELTA_TEMP_HYSTERESIS2        (OV_TEMPERATURE_HYSTERESIS_C2)
#define DELTA_V_HYSTERESIS2           (dV_dT2 * DELTA_TEMP_HYSTERESIS2)
#define OV_TEMPERATURE_HYSTERESIS_d2  (DELTA_V_HYSTERESIS2*INT_SUPPLY_VOLTAGE2)
														  														  
/*************************  PWM IDLE STATES AND POLARITY  *********************/														  
#define H_ACTIVE_HIGH    0x0000u //TIM_OCPolarity_High
#define H_ACTIVE_LOW     0x0002u //TIM_OCPolarity_Low
#define L_ACTIVE_HIGH    0x0000u  //TIM_OCNPolarity_High
#define L_ACTIVE_LOW     0x0008u  //TIM_OCNPolarity_Low 

#if (HIGH_SIDE_IDLE_STATE2 == TURN_OFF)
#if (PHASE_UH_POLARITY2 == H_ACTIVE_HIGH)
#define IDLE_UH_POLARITY2  TIM_OCIdleState_Reset
#else /* PHASE_UH_POLARITY = H_ACTIVE_LOW */
#define IDLE_UH_POLARITY2  TIM_OCIdleState_Set
#endif
#else /* HIGH_SIDE_IDLE_STATE = TURN_ON */
#if	(PHASE_UH_POLARITY2 == H_ACTIVE_HIGH)
#define IDLE_UH_POLARITY2  TIM_OCIdleState_Set
#else /* PHASE_UH_POLARITY = H_ACTIVE_LOW */
#define IDLE_UH_POLARITY2  TIM_OCIdleState_Reset
#endif
#endif

#if (HIGH_SIDE_IDLE_STATE2 == TURN_OFF)
#if	(PHASE_VH_POLARITY2 == H_ACTIVE_HIGH)
#define IDLE_VH_POLARITY2  TIM_OCIdleState_Reset
#else /* PHASE_VH_POLARITY = H_ACTIVE_LOW */
#define IDLE_VH_POLARITY2  TIM_OCIdleState_Set
#endif
#else /* HIGH_SIDE_IDLE_STATE = TURN_ON */
#if	(PHASE_VH_POLARITY2 == H_ACTIVE_HIGH)
#define IDLE_VH_POLARITY2  TIM_OCIdleState_Set
#else /* PHASE_VH_POLARITY = H_ACTIVE_LOW */
#define IDLE_VH_POLARITY2  TIM_OCIdleState_Reset
#endif
#endif

#if (HIGH_SIDE_IDLE_STATE2 == TURN_OFF)
#if	(PHASE_WH_POLARITY2 == H_ACTIVE_HIGH)
#define IDLE_WH_POLARITY2  TIM_OCIdleState_Reset
#else /* PHASE_WH_POLARITY = H_ACTIVE_LOW */
#define IDLE_WH_POLARITY2  TIM_OCIdleState_Set
#endif
#else /* HIGH_SIDE_IDLE_STATE = TURN_ON */
#if	(PHASE_WH_POLARITY2 == H_ACTIVE_HIGH)
#define IDLE_WH_POLARITY2  TIM_OCIdleState_Set
#else /* PHASE_WH_POLARITY = H_ACTIVE_LOW */
#define IDLE_WH_POLARITY2  TIM_OCIdleState_Reset
#endif
#endif

#if (LOW_SIDE_IDLE_STATE2 == TURN_OFF)
#if	(PHASE_UL_POLARITY2 == L_ACTIVE_HIGH)
#define IDLE_UL_POLARITY2  TIM_OCNIdleState_Reset
#else /* PHASE_UL_POLARITY = L_ACTIVE_LOW */
#define IDLE_UL_POLARITY2  TIM_OCNIdleState_Set
#endif
#else /* LOW_SIDE_IDLE_STATE = TURN_ON */
#if	(PHASE_UL_POLARITY2 == L_ACTIVE_HIGH)
#define IDLE_UL_POLARITY2  TIM_OCNIdleState_Set
#else /* PHASE_UL_POLARITY = L_ACTIVE_LOW */
#define IDLE_UL_POLARITY2  TIM_OCNIdleState_Reset
#endif
#endif

#if (LOW_SIDE_IDLE_STATE2 == TURN_OFF)
#if	(PHASE_VL_POLARITY2 == L_ACTIVE_HIGH)
#define IDLE_VL_POLARITY2  TIM_OCNIdleState_Reset
#else /* PHASE_VL_POLARITY = L_ACTIVE_LOW */
#define IDLE_VL_POLARITY2  TIM_OCNIdleState_Set
#endif
#else /* LOW_SIDE_IDLE_STATE = TURN_ON */
#if	(PHASE_VL_POLARITY2 == L_ACTIVE_HIGH)
#define IDLE_VL_POLARITY2  TIM_OCNIdleState_Set
#else /* PHASE_VL_POLARITY = L_ACTIVE_LOW */
#define IDLE_VL_POLARITY2  TIM_OCNIdleState_Reset
#endif
#endif

#if (LOW_SIDE_IDLE_STATE2 == TURN_OFF)
#if	(PHASE_WL_POLARITY2 == L_ACTIVE_HIGH)
#define IDLE_WL_POLARITY2  TIM_OCNIdleState_Reset
#else /* PHASE_WL_POLARITY = L_ACTIVE_LOW */
#define IDLE_WL_POLARITY2  TIM_OCNIdleState_Set
#endif
#else /* LOW_SIDE_IDLE_STATE = TURN_ON */
#if	(PHASE_WL_POLARITY2 == L_ACTIVE_HIGH)
#define IDLE_WL_POLARITY2  TIM_OCNIdleState_Set
#else /* PHASE_WL_POLARITY = L_ACTIVE_LOW */
#define IDLE_WL_POLARITY2  TIM_OCNIdleState_Reset
#endif
#endif

/**********  SPEED FEEDBACK TIMERS SETTING *************/
#if (defined(HALL_SENSORS2) || defined(AUX_HALL_SENSORS2))
  #if (HALL_TIMER_SELECTION2 == HALL_TIM2)
  #define HALL_TIMER2 				TIM2  
  #define HALL_RCC_PERIPHERAL2		RCC_APB1Periph_TIM2  
  #define HALL_IRQ_CHANNEL2  		TIM2_IRQn
  #elif (HALL_TIMER_SELECTION2 == HALL_TIM3)
  #define HALL_TIMER2 				TIM3  
  #define HALL_RCC_PERIPHERAL2 	RCC_APB1Periph_TIM3
  #define HALL_IRQ_CHANNEL2  		TIM3_IRQn  
  #elif (HALL_TIMER_SELECTION2 == HALL_TIM4)
  #define HALL_TIMER2 				TIM4  
  #define HALL_RCC_PERIPHERAL2 	RCC_APB1Periph_TIM4  
  #define HALL_IRQ_CHANNEL2  		TIM4_IRQn
  #elif (HALL_TIMER_SELECTION2 == HALL_TIM5)
  #define HALL_TIMER2 				TIM5  
  #define HALL_RCC_PERIPHERAL2 	RCC_APB1Periph_TIM5
  #define HALL_IRQ_CHANNEL2  		TIM5_IRQn  
  #else
  #error "Hall parameters not defined in Control Stage parametes motor2.h"
  #endif
#else
  /* Dummy value to avoid compiler error */
  #undef HALL_TIMER2
  #undef HALL_TIMER_REMAPPING2
  #undef HALL_RCC_PERIPHERAL2
  #undef HALL_IRQ_CHANNEL2
  #undef H1_GPIO_PORT2
  #undef H2_GPIO_PORT2
  #undef H3_GPIO_PORT2
  #undef H1_GPIO_PIN2
  #undef H2_GPIO_PIN2
  #undef H3_GPIO_PIN2
  #define HALL_TIMER2 				    TIM2
  #define HALL_TIMER_REMAPPING2  NO_REMAP_TIM2
  #define HALL_RCC_PERIPHERAL2		RCC_APB1Periph_TIM2
  #define HALL_IRQ_CHANNEL2  		TIM2_IRQn
  #define H1_GPIO_PORT2          GPIOA
  #define H2_GPIO_PORT2          GPIOA
  #define H3_GPIO_PORT2          GPIOA
  #define H1_GPIO_PIN2           GPIO_Pin_0
  #define H2_GPIO_PIN2           GPIO_Pin_1
  #define H3_GPIO_PIN2           GPIO_Pin_2
#endif

#if (defined(ENCODER2) || defined(AUX_ENCODER2))
  #if (ENC_TIMER_SELECTION2 == ENC_TIM2)
  #define ENC_TIMER2 				TIM2  
  #define ENC_RCC_PERIPHERAL2		RCC_APB1Periph_TIM2  
  #define ENC_IRQ_CHANNEL2  		TIM2_IRQn
  #elif (ENC_TIMER_SELECTION2 == ENC_TIM3)
  #define ENC_TIMER2 				TIM3  
  #define ENC_RCC_PERIPHERAL2 		RCC_APB1Periph_TIM3
  #define ENC_IRQ_CHANNEL2  		TIM3_IRQn  
  #elif (ENC_TIMER_SELECTION2 == ENC_TIM4)
  #define ENC_TIMER2 				TIM4  
  #define ENC_RCC_PERIPHERAL2 		RCC_APB1Periph_TIM4  
  #define ENC_IRQ_CHANNEL2  		TIM4_IRQn
  #elif (ENC_TIMER_SELECTION2 == ENC_TIM5)
  #define ENC_TIMER2 				TIM5  
  #define ENC_RCC_PERIPHERAL2 		RCC_APB1Periph_TIM5
  #define ENC_IRQ_CHANNEL2  		TIM5_IRQn  
  #else
  #error "Encoder parameters not defined in Control Stage parametes motor2.h"
  #endif
#else
  /* Dummy value to avoid compiler error */
  #undef  ENC_TIMER2
  #undef  ENC_TIMER_REMAPPING2
  #undef  ENC_RCC_PERIPHERAL2
  #undef  ENC_IRQ_CHANNEL2
  #undef  ENC_A_GPIO_PORT2
  #undef  ENC_B_GPIO_PORT2
  #undef  ENC_A_GPIO_PIN2
  #undef  ENC_B_GPIO_PIN2

  #define ENC_TIMER2 				    TIM2
  #define ENC_TIMER_REMAPPING2   NO_REMAP_TIM2
  #define ENC_RCC_PERIPHERAL2		RCC_APB1Periph_TIM2
  #define ENC_IRQ_CHANNEL2  		  TIM2_IRQn
  #define ENC_A_GPIO_PORT2       GPIOA
  #define ENC_B_GPIO_PORT2       GPIOA
  #define ENC_A_GPIO_PIN2        GPIO_Pin_0
  #define ENC_B_GPIO_PIN2        GPIO_Pin_1
#endif

/* Resistive Brake */
#if (ON_OVER_VOLTAGE2 != TURN_ON_R_BRAKE)
  /* Dummy value to avoid compiler error */
  #undef R_BRAKE_GPIO_PORT2
  #undef R_BRAKE_GPIO_PIN2
  
  #define R_BRAKE_GPIO_PORT2    GPIOD
  #define R_BRAKE_GPIO_PIN2     GPIO_Pin_13
#endif

/* Hardware over current protection bypass */
#if (HW_OV_CURRENT_PROT_BYPASS2 != ENABLE)
  /* Dummy value to avoid compiler error */
  #undef OV_CURR_BYPASS_GPIO_PORT2
  #undef OV_CURR_BYPASS_GPIO_PIN2
  
  #define OV_CURR_BYPASS_GPIO_PORT2  GPIOD        
  #define OV_CURR_BYPASS_GPIO_PIN2   GPIO_Pin_13
#endif

/* Inrush current limiter */
#if (INRUSH_CURRLIMIT_ENABLING2 != ENABLE)
  /* Dummy value to avoid compiler error */
  #undef INRUSH_CURRLIMIT_GPIO_PORT2
  #undef INRUSH_CURRLIMIT_GPIO_PIN2
  
  #define INRUSH_CURRLIMIT_GPIO_PORT2  GPIOD
  #define INRUSH_CURRLIMIT_GPIO_PIN2   GPIO_Pin_10
#endif

/* Current sensing topology */
#if (defined(SINGLE_SHUNT2))
  /* Dummy value to avoid compiler error */
  #undef PHASE_U_CURR_ADC2
  #undef PHASE_U_CURR_CHANNEL2
  #undef PHASE_U_GPIO_PORT2
  #undef PHASE_U_GPIO_PIN2
  #undef PHASE_V_CURR_ADC2
  #undef PHASE_V_CURR_CHANNEL2
  #undef PHASE_V_GPIO_PORT2
  #undef PHASE_V_GPIO_PIN2
  #undef PHASE_W_CURR_ADC2
  #undef PHASE_W_CURR_CHANNEL2
  #undef PHASE_W_GPIO_PORT2
  #undef PHASE_W_GPIO_PIN2
  
  #define PHASE_U_CURR_ADC2                ADC1_2
  #define PHASE_U_CURR_CHANNEL2            ADC_Channel_11
  #define PHASE_U_GPIO_PORT2               GPIOC
  #define PHASE_U_GPIO_PIN2                GPIO_Pin_1
  #define PHASE_V_CURR_ADC2                ADC1_2
  #define PHASE_V_CURR_CHANNEL2            ADC_Channel_12
  #define PHASE_V_GPIO_PORT2               GPIOC
  #define PHASE_V_GPIO_PIN2                GPIO_Pin_2
  #define PHASE_W_CURR_ADC2                ADC1_2
  #define PHASE_W_CURR_CHANNEL2            ADC_Channel_13
  #define PHASE_W_GPIO_PORT2               GPIOC
  #define PHASE_W_GPIO_PIN2                GPIO_Pin_3
#elif (defined(ICS_SENSORS2))
  /* Dummy value to avoid compiler error */
  #undef PHASE_W_CURR_ADC2
  #undef PHASE_W_CURR_CHANNEL2
  #undef PHASE_W_GPIO_PORT2
  #undef PHASE_W_GPIO_PIN2
  
  #define PHASE_W_CURR_ADC2                ADC1_2
  #define PHASE_W_CURR_CHANNEL2            ADC_Channel_13
  #define PHASE_W_GPIO_PORT2               GPIOC
  #define PHASE_W_GPIO_PIN2                GPIO_Pin_3
  
  #undef PHASE_CURRENTS_ADC2
  #undef PHASE_CURRENTS_CHANNEL2
  #undef PHASE_CURRENTS_GPIO_PORT2
  #undef PHASE_CURRENTS_GPIO_PIN2
  
  #define PHASE_CURRENTS_ADC2              ADC3
  #define PHASE_CURRENTS_CHANNEL2          ADC_Channel_12
  #define PHASE_CURRENTS_GPIO_PORT2        GPIOC
  #define PHASE_CURRENTS_GPIO_PIN2         GPIO_Pin_2
#else
  /* Dummy value to avoid compiler error */
  #undef PHASE_CURRENTS_ADC2
  #undef PHASE_CURRENTS_CHANNEL2
  #undef PHASE_CURRENTS_GPIO_PORT2
  #undef PHASE_CURRENTS_GPIO_PIN2
  
  #define PHASE_CURRENTS_ADC2              ADC3
  #define PHASE_CURRENTS_CHANNEL2          ADC_Channel_12
  #define PHASE_CURRENTS_GPIO_PORT2        GPIOC
  #define PHASE_CURRENTS_GPIO_PIN2         GPIO_Pin_2
#endif

#if (TEMPERATURE_READING2 != ENABLE)
  /* Dummy value to avoid compiler error */
  #undef TEMP_FDBK_GPIO_PORT2
  #undef TEMP_FDBK_GPIO_PIN2
  #define TEMP_FDBK_GPIO_PORT2             GPIOA
  #define TEMP_FDBK_GPIO_PIN2              GPIO_Pin_1
#endif

#if (BUS_VOLTAGE_READING2 != ENABLE)
  /* Dummy value to avoid compiler error */
  #undef VBUS_GPIO_PORT2
  #undef VBUS_GPIO_PIN2
  #define VBUS_GPIO_PORT2                  GPIOA
  #define VBUS_GPIO_PIN2                   GPIO_Pin_1
#endif

#if (HALL_ICx_FILTER2 <= 1)
#define HALL_IC_FILTER2   0
#elif (HALL_ICx_FILTER2 <= 2)
#define HALL_IC_FILTER2   1
#elif (HALL_ICx_FILTER2 <= 6)
#define HALL_IC_FILTER2   2
#elif (HALL_ICx_FILTER2 <= 10)
#define HALL_IC_FILTER2   3
#elif (HALL_ICx_FILTER2 <= 14)
#define HALL_IC_FILTER2   4
#elif (HALL_ICx_FILTER2 <= 20)
#define HALL_IC_FILTER2   5
#elif (HALL_ICx_FILTER2 <= 28)
#define HALL_IC_FILTER2   6
#elif (HALL_ICx_FILTER2 <= 40)
#define HALL_IC_FILTER2   7
#elif (HALL_ICx_FILTER2 <= 56)
#define HALL_IC_FILTER2   8
#elif (HALL_ICx_FILTER2 <= 72)
#define HALL_IC_FILTER2   9
#elif (HALL_ICx_FILTER2 <= 88)
#define HALL_IC_FILTER2   10
#elif (HALL_ICx_FILTER2 <= 112)
#define HALL_IC_FILTER2   11
#elif (HALL_ICx_FILTER2 <= 144)
#define HALL_IC_FILTER2   12
#elif (HALL_ICx_FILTER2 <= 176)
#define HALL_IC_FILTER2   13
#elif (HALL_ICx_FILTER2 <= 224)
#define HALL_IC_FILTER2   14
#else
#define HALL_IC_FILTER2   15
#endif

#if (ENC_ICx_FILTER2 == 0)
#define ENC_IC_FILTER2   0
#elif (ENC_ICx_FILTER2 <= 2)
#define ENC_IC_FILTER2   1
#elif (ENC_ICx_FILTER2 <= 6)
#define ENC_IC_FILTER2   2
#elif (ENC_ICx_FILTER2 <= 10)
#define ENC_IC_FILTER2   3
#elif (ENC_ICx_FILTER2 <= 14)
#define ENC_IC_FILTER2   4
#elif (ENC_ICx_FILTER2 <= 20)
#define ENC_IC_FILTER2   5
#elif (ENC_ICx_FILTER2 <= 28)
#define ENC_IC_FILTER2   6
#elif (ENC_ICx_FILTER2 <= 40)
#define ENC_IC_FILTER2   7
#elif (ENC_ICx_FILTER2 <= 56)
#define ENC_IC_FILTER2   8
#elif (ENC_ICx_FILTER2 <= 72)
#define ENC_IC_FILTER2   9
#elif (ENC_ICx_FILTER2 <= 88)
#define ENC_IC_FILTER2   10
#elif (ENC_ICx_FILTER2 <= 112)
#define ENC_IC_FILTER2   11
#elif (ENC_ICx_FILTER2 <= 144)
#define ENC_IC_FILTER2   12
#elif (ENC_ICx_FILTER2 <= 176)
#define ENC_IC_FILTER2   13
#elif (ENC_ICx_FILTER2 <= 224)
#define ENC_IC_FILTER2   14
#else
#define ENC_IC_FILTER2   15
#endif

/*************** Encoder Alignemnt ************************/
    
/* Encoder alignment */
#define T_ALIGNMENT2             ALIGNMENT_DURATION2
#define ALIGNMENT_ANGLE_S162      (int16_t)  (ALIGNMENT_ANGLE_DEG2*65536u/360u)

/*************** Timer for PWM generation & currenst sensing parameters  ******/
#define PWM_PERIOD_CYCLES2 (uint16_t)(ADV_TIM_CLK_MHz*\
                                      (unsigned long long)1000000u/((uint16_t)(PWM_FREQUENCY2)))

#if ((LOW_SIDE_SIGNALS_ENABLING2 == ENABLE)||(LOW_SIDE_SIGNALS_ENABLING2 == LS_PWM_TIMER_VAL))
#define DEADTIME_NS2  SW_DEADTIME_NS2
#else
#define DEADTIME_NS2  HW_DEAD_TIME_NS2
#endif

#define DEAD_TIME_ADV_TIM_CLK_MHz2 (ADV_TIM_CLK_MHz2 * TIM_CLOCK_DIVIDER2)
#define DEAD_TIME_COUNTS2_1  (DEAD_TIME_ADV_TIM_CLK_MHz2 * DEADTIME_NS2/1000uL)

#if (DEAD_TIME_COUNTS2_1 <= 255)
  #define DEAD_TIME_COUNTS2 (uint16_t) DEAD_TIME_COUNTS2_1
#elif (DEAD_TIME_COUNTS2_1 <= 508)
  #define DEAD_TIME_COUNTS2 (uint16_t)(((DEAD_TIME_ADV_TIM_CLK_MHz2 * DEADTIME_NS2/2) /1000uL) + 128)
  #elif (DEAD_TIME_COUNTS2_1 <= 1008)
    #define DEAD_TIME_COUNTS2 (uint16_t)(((DEAD_TIME_ADV_TIM_CLK_MHz2 * DEADTIME_NS2/8) /1000uL) + 320)
    #elif (DEAD_TIME_COUNTS2_1 <= 2015)
      #define DEAD_TIME_COUNTS2 (uint16_t)(((DEAD_TIME_ADV_TIM_CLK_MHz2 * DEADTIME_NS2/16) /1000uL) + 384)
      #else
        #define DEAD_TIME_COUNTS2 510
#endif

#define DTCOMPCNT2 (uint16_t)((DEADTIME_NS2 * ADV_TIM_CLK_MHz2) / 2000)
#define TON_NS2  500
#define TOFF_NS2 500
#define TON2  (uint16_t)((TON_NS2 * ADV_TIM_CLK_MHz2)  / 2000)
#define TOFF2 (uint16_t)((TOFF_NS2 * ADV_TIM_CLK_MHz2) / 2000)

#if (TNOISE_NS2 > TRISE_NS2)
  #define MAX_TNTR_NS2 TNOISE_NS2
#else
  #define MAX_TNTR_NS2 TRISE_NS2
#endif


#define SAMPLING_TIME_NS2 (((CURR_SAMPLING_TIME2) * 1000uL/ADC_CLK_MHz2)+(7000uL/(2*ADC_CLK_MHz2)))

#if (CURR_SAMPLING_TIME2 == 1)
#define SAMPLING_TIME_SEL2  ADC_SampleTime_1Cycles5
#elif (CURR_SAMPLING_TIME2 == 7)
#define SAMPLING_TIME_SEL2  ADC_SampleTime_7Cycles5
#elif (CURR_SAMPLING_TIME2 == 13)
#define SAMPLING_TIME_SEL2  ADC_SampleTime_13Cycles5
#elif (CURR_SAMPLING_TIME2 == 28)
#define SAMPLING_TIME_SEL2  ADC_SampleTime_28Cycles5
#endif

#define SAMPLING_TIME2 (uint16_t)(((uint16_t)(SAMPLING_TIME_NS2) * ADV_TIM_CLK_MHz2)/1000uL) 
#define TRISE2 (uint16_t)((((uint16_t)(TRISE_NS2)) * ADV_TIM_CLK_MHz2)/1000uL)
#define TDEAD2 (uint16_t)((DEADTIME_NS2 * ADV_TIM_CLK_MHz2)/1000uL)

#define TMIN2 (((uint16_t)(((DEADTIME_NS2+((uint16_t)(TRISE_NS2))+\
              ((uint16_t)(SAMPLING_TIME_NS2)))*ADV_TIM_CLK_MHz2)/1000ul))+1)
#define HTMIN2 (uint16_t)(TMIN2 >> 1)
#define TSAMPLE2 SAMPLING_TIME2
#define TAFTER2 ((uint16_t)(((DEADTIME_NS2+((uint16_t)(TRISE_NS2)))\
                                                     *ADV_TIM_CLK_MHz2)/1000ul))
#define TBEFORE2 (((uint16_t)(((((uint16_t)(SAMPLING_TIME_NS2)))\
                                                  *ADV_TIM_CLK_MHz2)/1000ul))+1)

#if (TRISE_NS2 > SAMPLING_TIME_NS2)
  #define MAX_TRTS2 (2 * TRISE2)
#else
  #define MAX_TRTS2 (2 * SAMPLING_TIME2)
#endif

#define TNOISE2 (u16)((((u16)(TNOISE_NS2)) * ADV_TIM_CLK_MHz2)/1000uL)

#if (TNOISE_NS2 > TRISE_NS2)
  #define MAX_TNTR_NS2 TNOISE_NS2
#else
  #define MAX_TNTR_NS2 TRISE_NS2
#endif

#define TW_AFTER2 ((uint16_t)(((DEADTIME_NS2+MAX_TNTR_NS2)*ADV_TIM_CLK_MHz2)/1000ul))
#define TW_BEFORE2 (((uint16_t)(((((uint16_t)(SAMPLING_TIME_NS2)))*ADV_TIM_CLK_MHz2)/1000ul))+1u)


#ifdef THREE_SHUNT2
#define MAX_TWAIT (uint16_t)((TW_AFTER2 - SAMPLING_TIME2)/2)
#else //ICS or One shunt
#define MAX_TWAIT 0
#endif

#ifdef THREE_SHUNT
#define MAX_TWAIT2 (uint16_t)((TW_AFTER - SAMPLING_TIME)/2)
#else //ICS or One shunt
#define MAX_TWAIT2 0
#endif

#if (FLUX_WEAKENING_ENABLING2 == ENABLE)
#define FLUX_WEAKENING2
#endif
#if (MTPA_ENABLING2 == ENABLE)
#define IPMSM_MTPA2
#endif
#if (FEED_FORWARD_CURRENT_REG_ENABLING2 == ENABLE)
#define FEED_FORWARD_CURRENT_REGULATION2
#endif

#ifdef MAX_MODULATION_81_PER_CENT2
#define START_INDEX2     41
#define MAX_MODULE2      26541   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*81% 
#define MMITABLE2 {\
32508,32255,32008,31530,31299,30852,30636,30216,30012,29617,29426,29053,28872,\
28520,28349,28015,27853,27536,27382,27081,26934,26647,26507,26234,26101,25840,\
25712,25462,25340,25101,24984,24755,24643,24422,24315,24103,24000,23796,23696,\
23500,23404,23216,23123,22941,22851,22763,22589,22504,22336,22253,22091,22011,\
21854,21776,21624,21549,21401,21329,21186,21115,20976,20908,20773,20706,20575,\
20511,20383,20320,20196,20135,20015,19955,19838,19780,19666,19609,19498,19443,\
19334,19280,19175,19122,19019,18968,18867,18817,18719\
}
#endif

#ifdef MAX_MODULATION_83_PER_CENT2
#define START_INDEX2     44
#define MAX_MODULE2      27196   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*83% 
#define MMITABLE2 {\
32291,32060,31613,31397,30977,30573,30377,29996,29811,29451,29276,28934,28768,\
28444,28286,27978,27827,27533,27390,27110,26973,26705,26574,26318,26069,25948,\
25709,25592,25363,25251,25031,24923,24711,24607,24404,24304,24107,24011,23821,\
23728,23545,23456,23279,23192,23021,22854,22772,22610,22530,22374,22297,22145,\
22070,21922,21850,21707,21636,21497,21429,21294,21227,21096,21032,20904,20778,\
20717,20595,20534,20416,20357,20241,20184,20071,20015,19905,19851,19743,19690,\
19585,19533,19431,19380,19280,19182\
}
#endif


#ifdef MAX_MODULATION_85_PER_CENT2
#define START_INDEX2     46
#define MAX_MODULE2      27851   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*85%  
#define MMITABLE2 {\
32324,32109,31691,31489,31094,30715,30530,30170,29995,29654,29488,29163,29005,\
28696,28397,28250,27965,27825,27552,27418,27157,26903,26779,26535,26416,26182,\
26067,25842,25623,25515,25304,25201,24997,24897,24701,24605,24415,24230,24139,\
23960,23872,23699,23614,23446,23282,23201,23042,22964,22810,22734,22584,22437,\
22365,22223,22152,22014,21945,21811,21678,21613,21484,21421,21296,21234,21112,\
21051,20932,20815,20757,20643,20587,20476,20421,20312,20205,20152,20048,19996\
,19894,19844,19744,19645\
}
#endif



#ifdef MAX_MODULATION_87_PER_CENT2
#define START_INDEX2     48
#define MAX_MODULE2      28507   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*87%  
#define MMITABLE2 {\
32559,32154,31764,31575,31205,31025,30674,30335,30170,29847,\
29689,29381,29083,28937,28652,28375,28239,27974,27844,27589,\
27342,27220,26983,26866,26637,26414,26305,26090,25984,25777,\
25575,25476,25280,25184,24996,24811,24720,24542,24367,24281,\
24112,24028,23864,23703,23624,23468,23391,23240,23091,23018,\
22874,22803,22662,22524,22456,22322,22191,22126,21997,21934,\
21809,21686,21625,21505,21446,21329,21214,21157,21045,20990,\
20880,20772,20719,20613,20561,20458,20356,20306,20207,20158,\
20109\
}
#endif

#ifdef MAX_MODULATION_89_PER_CENT2
#define START_INDEX2     50
#define MAX_MODULE2      29162   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*89%
#define MMITABLE2 {\
32574,32197,32014,31656,31309,31141,30811,30491,30335,30030,\
29734,29589,29306,29031,28896,28632,28375,28249,28002,27881,\
27644,27412,27299,27076,26858,26751,26541,26336,26235,26037,\
25844,25748,25561,25378,25288,25110,24936,24851,24682,24517,\
24435,24275,24118,24041,23888,23738,23664,23518,23447,23305,\
23166,23097,22962,22828,22763,22633,22505,22442,22318,22196,\
22135,22016,21898,21840,21726,21613,21557,21447,21338,21284,\
21178,21074,21022,20919,20819,20769,20670,20573\
}
#endif

#ifdef MAX_MODULATION_91_PER_CENT2
#define START_INDEX2     52
#define MAX_MODULE2      29817   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*91%
#define MMITABLE2 {\
32588,32411,32066,31732,31569,31250,30940,30789,30492,30205,\
29925,29788,29519,29258,29130,28879,28634,28395,28278,28048,\
27823,27713,27497,27285,27181,26977,26777,26581,26485,26296,\
26110,26019,25840,25664,25492,25407,25239,25076,24995,24835,\
24679,24602,24450,24301,24155,24082,23940,23800,23731,23594,\
23460,23328,23263,23135,23008,22946,22822,22701,22641,22522,\
22406,22291,22234,22122,22011,21956,21848,21741,21636,21584,\
21482,21380,21330,21231,21133,21037\
}
#endif


#ifdef MAX_MODULATION_92_PER_CENT2
#define START_INDEX2     54
#define MAX_MODULE2      30145   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*92%
#define MMITABLE2 {\
32424,32091,31929,31611,31302,31002,30855,30568,30289,30017,\
29884,29622,29368,29243,28998,28759,28526,28412,28187,27968,\
27753,27648,27441,27238,27040,26942,26750,26563,26470,26288,\
26110,25935,25849,25679,25513,25350,25269,25111,24955,24803,\
24727,24579,24433,24361,24219,24079,23942,23874,23740,23609,\
23479,23415,23289,23165,23042,22982,22863,22745,22629,22572,\
22459,22347,22292,22183,22075,21970,21917,21813,21711,21610,\
21561,21462,21365,21268\
}
#endif


#ifdef MAX_MODULATION_93_PER_CENT2
#define START_INDEX2     55
#define MAX_MODULE2      30473   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*93%
#define MMITABLE2 {\
32437,32275,31959,31651,31353,31207,30920,30642,30371,30107,\
29977,29723,29476,29234,29116,28883,28655,28433,28324,28110,\
27900,27695,27594,27395,27201,27011,26917,26733,26552,26375,\
26202,26116,25948,25783,25621,25541,25383,25228,25076,25001,\
24854,24708,24565,24495,24356,24219,24084,24018,23887,23758,\
23631,23506,23444,23322,23202,23083,23025,22909,22795,22683,\
22627,22517,22409,22302,22250,22145,22042,21941,21890,21791,\
21693,21596,21500\
}
#endif


#ifdef MAX_MODULATION_94_PER_CENT2
#define START_INDEX2     56
#define MAX_MODULE2      30800   //root(Vd^2+Vq^2) <= MAX_MODULE = 32767*94%
#define MMITABLE2 {\
32607,32293,31988,31691,31546,31261,30984,30714,30451,30322,\
30069,29822,29581,29346,29231,29004,28782,28565,28353,28249,\
28044,27843,27647,27455,27360,27174,26991,26812,26724,26550,\
26380,26213,26049,25968,25808,25652,25498,25347,25272,25125,\
24981,24839,24699,24630,24494,24360,24228,24098,24034,23908,\
23783,23660,23600,23480,23361,23245,23131,23074,22962,22851,\
22742,22635,22582,22477,22373,22271,22170,22120,22021,21924,\
21827,21732\
}
#endif


#ifdef MAX_MODULATION_95_PER_CENT2
#define START_INDEX2     57
#define MAX_MODULE2      31128   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*95%
#define MMITABLE2 {\
32613,32310,32016,31872,31589,31314,31046,30784,30529,30404,\
30158,29919,29684,29456,29343,29122,28906,28695,28488,28285,\
28186,27990,27798,27610,27425,27245,27155,26980,26808,26639,\
26473,26392,26230,26072,25917,25764,25614,25540,25394,25250,\
25109,24970,24901,24766,24633,24501,24372,24245,24182,24058,\
23936,23816,23697,23580,23522,23408,23295,23184,23075,23021,\
22913,22808,22703,22600,22499,22449,22349,22251,22154,22059,\
21964\
}
#endif


#ifdef MAX_MODULATION_96_PER_CENT2
#define START_INDEX2     58
#define MAX_MODULE2      31456   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*96%
#define MMITABLE2 {\
32619,32472,32184,31904,31631,31365,31106,30853,30728,30484,\
30246,30013,29785,29563,29345,29238,29028,28822,28620,28423,\
28229,28134,27946,27762,27582,27405,27231,27061,26977,26811,\
26649,26489,26332,26178,26027,25952,25804,25659,25517,25376,\
25238,25103,25035,24903,24772,24644,24518,24393,24270,24210,\
24090,23972,23855,23741,23627,23516,23461,23352,23244,23138,\
23033,22930,22828,22777,22677,22579,22481,22385,22290,22196\
}
#endif


#ifdef MAX_MODULATION_97_PER_CENT2
#define START_INDEX2     60
#define MAX_MODULE2      31783   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*97%
#define MMITABLE2 {\
32483,32206,31936,31672,31415,31289,31041,30799,30563,30331,\
30105,29884,29668,29456,29352,29147,28947,28750,28557,28369,\
28183,28002,27824,27736,27563,27393,27226,27062,26901,26743,\
26588,26435,26360,26211,26065,25921,25780,25641,25504,25369,\
25236,25171,25041,24913,24788,24664,24542,24422,24303,24186,\
24129,24015,23902,23791,23681,23573,23467,23362,23258,23206,\
23105,23004,22905,22808,22711,22616,22521,22429\
}
#endif


#ifdef MAX_MODULATION_98_PER_CENT2
#define START_INDEX2     61
#define MAX_MODULE2      32111   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*98%
#define MMITABLE2 {\
32494,32360,32096,31839,31587,31342,31102,30868,30639,30415,\
30196,29981,29771,29565,29464,29265,29069,28878,28690,28506,\
28325,28148,27974,27803,27635,27470,27309,27229,27071,26916,\
26764,26614,26467,26322,26180,26039,25901,25766,25632,25500,\
25435,25307,25180,25055,24932,24811,24692,24574,24458,24343,\
24230,24119,24009,23901,23848,23741,23637,23533,23431,23331,\
23231,23133,23036,22941,22846,22753,22661\
}
#endif


#ifdef MAX_MODULATION_99_PER_CENT2
#define START_INDEX2     62
#define MAX_MODULE2      32439   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*99%
#define MMITABLE2 {\
32635,32375,32121,31873,31631,31394,31162,30935,30714,30497,\
30284,30076,29872,29672,29574,29380,29190,29003,28820,28641,\
28464,28291,28122,27955,27791,27630,27471,27316,27163,27012,\
26864,26718,26575,26434,26295,26159,26024,25892,25761,25633,\
25569,25444,25320,25198,25078,24959,24842,24727,24613,24501,\
24391,24281,24174,24067,23963,23859,23757,23656,23556,23458,\
23361,23265,23170,23077,22984,22893\
}
#endif


#ifdef MAX_MODULATION_100_PER_CENT2
#define START_INDEX2     63
#define MAX_MODULE2      32767   // root(Vd^2+Vq^2) <= MAX_MODULE = 32767*100%
#define MMITABLE2 {\
32767,32390,32146,31907,31673,31444,31220,31001,30787,30577,30371,\
30169,29971,29777,29587,29400,29217,29037,28861,28687,28517,\
28350,28185,28024,27865,27709,27555,27404,27256,27110,26966,\
26824,26685,26548,26413,26280,26149,26019,25892,25767,25643,\
25521,25401,25283,25166,25051,24937,24825,24715,24606,24498,\
24392,24287,24183,24081,23980,23880,23782,23684,23588,23493,\
23400,23307,23215,23125\
}
#endif

/*************** PI divisor  ***************/
#if (LOG2(SP_KPDIV2)==-1)
  #error "Error: SP_KPDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define SP_KPDIV_LOG2 LOG2(SP_KPDIV2)
#endif

#if (LOG2(SP_KIDIV2)==-1)
  #error "Error: SP_KIDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define SP_KIDIV_LOG2 LOG2(SP_KIDIV2)
#endif

#if (LOG2(SP_KDDIV2)==-1)
  #error "Error: SP_KDDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define SP_KDDIV_LOG2 LOG2(SP_KDDIV2)
#endif

#if (LOG2(TF_KPDIV2)==-1)
  #error "Error: TF_KPDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define TF_KPDIV_LOG2 LOG2(TF_KPDIV2)
#endif

#if (LOG2(TF_KIDIV2)==-1)
  #error "Error: TF_KIDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define TF_KIDIV_LOG2 LOG2(TF_KIDIV2)
#endif

#if (LOG2(TF_KDDIV2)==-1)
  #error "Error: TF_KDDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define TF_KDDIV_LOG2 LOG2(TF_KDDIV2)
#endif

#if (LOG2(FW_KPDIV2)==-1)
  #error "Error: FW_KPDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define FW_KPDIV_LOG2 LOG2(FW_KPDIV2)
#endif

#if (LOG2(FW_KIDIV2)==-1)
  #error "Error: FW_KIDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define FW_KIDIV_LOG2 LOG2(FW_KIDIV2)
#endif

#define PLL_KPDIV2     16384
#define PLL_KIDIV2     65535

#if (LOG2(PLL_KPDIV2)==-1)
  #error "Error: PLL_KPDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define PLL_KPDIV_LOG2 LOG2(PLL_KPDIV2)
#endif

#if (LOG2(PLL_KIDIV2)==-1)
  #error "Error: PLL_KIDIV2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define PLL_KIDIV_LOG2 LOG2(PLL_KIDIV2)
#endif

#if (LOG2(F12)==-1)
  #error "Error: F12 defined in Drive parameters motor 2.h must be power of two."
#else
  #define F1_LOG2 LOG2(F12)
#endif

#if (LOG2(F22)==-1)
  #error "Error: F22 defined in Drive parameters motor 2.h must be power of two."
#else
  #define F2_LOG2 LOG2(F22)
#endif

#if (LOG2(STO_FIFO_DEPTH_DPP2)==-1)
  #error "Error: STO_FIFO_DEPTH_DPP2 in Drive parameters motor 2.h must be power of two."
#else
  #define STO_FIFO_DEPTH_DPP_LOG2 LOG2(STO_FIFO_DEPTH_DPP2)
#endif

#if (LOG2(CORD_FIFO_DEPTH_DPP2)==-1)
  #error "Error: CORD_FIFO_DEPTH_DPP2 in Drive parameters motor 2.h must be power of two."
#else
  #define CORD_FIFO_DEPTH_DPP_LOG2 LOG2(CORD_FIFO_DEPTH_DPP2)
#endif

#if (LOG2(HFI_PID_KPDIV2)==-1)
  #error "Error: HFI_PID_KPDIV2 defined in Drive parameters.h must be power of two."
#else
  #define HFI_PID_KPDIV_LOG2 LOG2(HFI_PID_KPDIV2)
#endif

#if (LOG2(HFI_PID_KIDIV2)==-1)
  #error "Error: HFI_PID_KIDIV2 defined in Drive parameters.h must be power of two."
#else
  #define HFI_PID_KIDIV_LOG2 LOG2(HFI_PID_KIDIV2)
#endif

#if (BUS_VOLTAGE_READING2 == ENABLE)
 #if ((OV_VOLTAGE_PROT_ENABLING2 != ENABLE) || (UV_VOLTAGE_PROT_ENABLING2!= ENABLE))
  #error "Configuration not supported by this version of the library. Under and Over voltage protections (motor 2) must be enabled if bus voltage sensing is enabled."
 #else
  #define BUS_VOLTAGE_MEASUREMENT2
 #endif
#endif

#if ((TEMPERATURE_READING2 == ENABLE) && (OV_TEMPERATURE_PROT_ENABLING2 == ENABLE))
 #define HEAT_SINK_TEMPERATURE_MEASUREMENT2
#endif

#if (VBUS_ADC_SAMPLING_TIME2 == 1)
#define VBUS_SAMPLING_TIME2  ADC_SampleTime_1Cycles5
#elif (VBUS_ADC_SAMPLING_TIME2 == 7)
#define VBUS_SAMPLING_TIME2  ADC_SampleTime_7Cycles5
#elif (VBUS_ADC_SAMPLING_TIME2 == 13)
#define VBUS_SAMPLING_TIME2  ADC_SampleTime_13Cycles5
#elif (VBUS_ADC_SAMPLING_TIME2 == 28)
#define VBUS_SAMPLING_TIME2  ADC_SampleTime_28Cycles5
#else
#define VBUS_SAMPLING_TIME2  ADC_SampleTime_1Cycles5
#endif

#if (TEMP_ADC_SAMPLING_TIME2 == 1)
#define TEMP_SAMPLING_TIME2  ADC_SampleTime_1Cycles5
#elif (TEMP_ADC_SAMPLING_TIME2 == 7)
#define TEMP_SAMPLING_TIME2  ADC_SampleTime_7Cycles5
#elif (TEMP_ADC_SAMPLING_TIME2 == 13)
#define TEMP_SAMPLING_TIME2  ADC_SampleTime_13Cycles5
#elif (TEMP_ADC_SAMPLING_TIME2 == 28)
#define TEMP_SAMPLING_TIME2  ADC_SampleTime_28Cycles5
#else
#define TEMP_SAMPLING_TIME2  ADC_SampleTime_1Cycles5
#endif

#define TEMP_SW_FILTER_BW_FACTOR2     250u
#define VQD_SW_FILTER_BW_FACTOR2      128u
#define VBUS_SW_FILTER_BW_FACTOR2     10u

#if (LOG2(VQD_SW_FILTER_BW_FACTOR2)==-1)
  #error "Error: VQD_SW_FILTER_BW_FACTOR2 defined in Drive parameters motor 2.h must be power of two."
#else
  #define VQD_SW_FILTER_BW_FACTOR_LOG2 LOG2(VQD_SW_FILTER_BW_FACTOR2)
#endif

#if (FREQ_RELATION ==  HIGHEST_FREQ) /* First instance has higher frequency */
#define PWM_FREQUENCY_CHECK_RATIO   (PWM_FREQUENCY*10000u/PWM_FREQUENCY2)
#else /* Second instance has higher frequency */
#define PWM_FREQUENCY_CHECK_RATIO   (PWM_FREQUENCY2*10000u/PWM_FREQUENCY)
#endif

#define MAGN_FREQ_RATIO   (FREQ_RATIO*10000u)

#ifdef DUALDRIVE
#if (PWM_FREQUENCY_CHECK_RATIO != MAGN_FREQ_RATIO)
#error "The two motor PWM frequencies should be integer multiple"  
#endif
#endif

#undef HIGHEST_FREQ
#undef LOWEST_FREQ
#define HIGHEST_FREQ    HIGHER_FREQ
#define LOWEST_FREQ     LOWER_FREQ

#if ((defined STATE_OBSERVER_PLL2) || (defined STATE_OBSERVER_CORDIC2))
#define NO_SPEED_SENSORS2
#endif

#if (MTPA_ENABLING2 == ENABLE)
#define IPMSM_MTPA2
#endif

#if (FEED_FORWARD_CURRENT_REG_ENABLING2 == ENABLE)
#define FEED_FORWARD_CURRENT_REGULATION2
#endif

#if (FLUX_WEAKENING_ENABLING2 == ENABLE)
#define FLUX_WEAKENING2
#endif

#if defined AUX_ENCODER
#define VIEW_ENCODER_FEEDBACK
#endif

#if defined AUX_HALL_SENSORS
#define VIEW_HALL_FEEDBACK
#endif

#ifdef SINGLE_SHUNT
#define M2FIRSTR1 FALSE
#else
#define M2FIRSTR1 TRUE
#endif

#if (defined(SINGLE_SHUNT2) || defined(THREE_SHUNT2))
#define PQD_CONVERSION_FACTOR2 (int32_t)(( 1000 * 3 * MCU_SUPPLY_VOLTAGE ) /\
             ( 1.732 * RSHUNT2 * AMPLIFICATION_GAIN2 ))
#endif

#if (defined(ICS_SENSORS2))
#define PQD_CONVERSION_FACTOR2 (int32_t)(( 1000 * 3 * MCU_SUPPLY_VOLTAGE ) /\
             ( 1.732 * AMPLIFICATION_GAIN2 ))
#endif

/****** Prepares the UI configurations according the MCconfxx settings ********/
/* Motor 2 settings */
#ifdef FLUX_WEAKENING2
  #define FW_ENABLE2 |UI_CFGOPT_FW
#else
  #define FW_ENABLE2
#endif

#ifdef DIFFERENTIAL_TERM_ENABLED2
  #define DIFFTERM_ENABLE2 |UI_CFGOPT_SPEED_KD|UI_CFGOPT_Iq_KD|UI_CFGOPT_Id_KD
#else
  #define DIFFTERM_ENABLE2
#endif

/* Sensors setting */
#ifdef STATE_OBSERVER_PLL2
  #define MAIN_SCFG2 UI_SCODE_STO_PLL
#endif

#ifdef STATE_OBSERVER_CORDIC2
  #define MAIN_SCFG2 UI_SCODE_STO_CR
#endif

#ifdef AUX_STATE_OBSERVER_PLL2
  #define AUX_SCFG2 UI_SCODE_STO_PLL
#endif

#ifdef AUX_STATE_OBSERVER_CORDIC2
  #define AUX_SCFG2 UI_SCODE_STO_CR
#endif

#ifdef ENCODER2
  #define MAIN_SCFG2 UI_SCODE_ENC
#endif

#ifdef VIEW_ENCODER_FEEDBACK2
  #define AUX_SCFG2 UI_SCODE_ENC
#endif

#ifdef HALL_SENSORS2
  #define MAIN_SCFG2 UI_SCODE_HALL
#endif

#ifdef VIEW_HALL_FEEDBACK2
  #define AUX_SCFG2 UI_SCODE_HALL
#endif

#ifndef AUX_SCFG2
#define AUX_SCFG2 0x0
#endif

#if defined(PLLTUNING)
  #define PLLTUNING_ENABLE2 |UI_CFGOPT_PLLTUNING
#else
  #define PLLTUNING_ENABLE2
#endif

/******************************************************************************* 
  * UI configurations settings. It can be manually overwritten if special 
  * configuartion is required. 
*******************************************************************************/
#ifdef DUALDRIVE
  #define UI_CONFIG_M2 ( UI_CFGOPT_NONE DAC_OP_ENABLE FW_ENABLE DIFFTERM_ENABLE2\
    | (MAIN_SCFG2 << MAIN_SCFG_POS) | (AUX_SCFG2 << AUX_SCFG_POS) | UI_CFGOPT_SETIDINSPDMODE PLLTUNING_ENABLE2 )
#endif

#endif /*__PARAMETERS_CONVERSION_F10X_MOTOR2_H*/

/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
