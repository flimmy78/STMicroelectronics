/**
  ******************************************************************************
  * @file    USART_PhysicalLayerCommunication_Class.c
  * @author  STMicroelectronics - System Lab - MC Team
  * @version 4.3.0
  * @date    22-Sep-2016 15:29
  * @brief   Private implementation for Physical Layer Communication
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

/* Includes ------------------------------------------------------------------*/

#include "PhysicalLayerCommunication_Class.h"
#include "PhysicalLayerCommunication_Private.h"
#include "USART_PhysicalLayerCommunication_Class.h"
#include "USART_PhysicalLayerCommunication_Private.h"
#include "UIIRQHandlerPrivate.h"

#ifdef MC_CLASS_DYNAMIC
  #include "stdlib.h" /* Used for dynamic allocation */
#else
  
  #define MAX_USART_COM_NUM 1

  _CUSART_t USART_COMpool[MAX_USART_COM_NUM];
  u8 USART_COM_Allocated = 0;
#endif

/* Private function prototypes -----------------------------------------------*/
void USART_HWInit(pUSARTParams_t pUSARTParams);
void* USART_IRQ_Handler(void* this,unsigned char flags, unsigned short rx_data);
static void USART_StartReceive(CCOM this);
static void USART_StartTransmit(CCOM this);

/**
  * @brief  Creates an object of the class "Physical Layer Communication"
  * @param  pSensorParam: Physical Layer parameters
  * @retval oCOM: new Physical Layer object
  */
CUSART_COM USART_NewObject(pUSARTParams_t pUSARTParams)
{
  _CCOM _oCOM;
  _CUSART _oUSART;
  
  _oCOM = (_CCOM)COM_NewObject();

  #ifdef MC_CLASS_DYNAMIC
    _oUSART = (_CUSART)calloc(1,sizeof(_CUSART_t));
  #else
    if (USART_COM_Allocated  < MAX_USART_COM_NUM)
    {
      _oUSART = &USART_COMpool[USART_COM_Allocated++];
    }
    else
    {
      _oUSART = MC_NULL;
    }
  #endif
  
  _oUSART->pDParams_str = pUSARTParams;
  _oCOM->DerivedClass = (void*)_oUSART;
  _oCOM->Methods_str.pStartReceive = &USART_StartReceive;
  _oCOM->Methods_str.pStartTransmit = &USART_StartTransmit;
  
  _oCOM->Methods_str.pIRQ_Handler = &USART_IRQ_Handler;
  Set_UI_IRQ_Handler(pUSARTParams->bUIIRQn, (_CUIIRQ)_oCOM);
  
  //Init Struct communication
  COM_ResetTX((CCOM)_oCOM);
  COM_ResetRX((CCOM)_oCOM);
  
  USART_HWInit(pUSARTParams);
  
  return ((CUSART_COM)_oCOM);
}

void USART_HWInit(pUSARTParams_t pUSARTParams)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  /* Enable USART clock: UASRT1 -> APB2, USART2-5 -> APB1 */
  if (pUSARTParams->wUSARTClockSource == RCC_APB2Periph_USART1)
  {
    RCC_APB2PeriphClockCmd(pUSARTParams->wUSARTClockSource, ENABLE);
  }
  else
  {
    RCC_APB1PeriphClockCmd(pUSARTParams->wUSARTClockSource, ENABLE);
  }  
  
  /* USART Init structure */
  /* Configure USART */
  USART_Init(pUSARTParams->USARTx, pUSARTParams->USART_InitStructure);
    
  /* Configures the GPIO ports for USART. */
  if (pUSARTParams->wUSARTRemapping != 0)
  {
    /* Enable USART AFIO clock if remapped */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    
    /* Enable the USART Pins Software Remapping */
    GPIO_PinRemapConfig(pUSARTParams->wUSARTRemapping , ENABLE);
  }
  
  /* Configure Rx as input floating */
  GPIO_InitStructure.GPIO_Pin = pUSARTParams->hRxPin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(pUSARTParams->hRxPort, &GPIO_InitStructure);
    
  /* Configure Tx as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = pUSARTParams->hTxPin;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(pUSARTParams->hTxPort, &GPIO_InitStructure);
  
  if (pUSARTParams->NVIC_InitStructure->NVIC_IRQChannelCmd == ENABLE)
  {
    /* Enable USART Receive and Transmit interrupts */
    if ((pUSARTParams->USART_InitStructure->USART_Mode & USART_Mode_Rx) == USART_Mode_Rx)
    {
      USART_ITConfig(pUSARTParams->USARTx, USART_IT_RXNE, ENABLE);
    }
    if ((pUSARTParams->USART_InitStructure->USART_Mode & USART_Mode_Tx) == USART_Mode_Tx)
    {
      USART_ITConfig(pUSARTParams->USARTx, USART_IT_TXE, DISABLE);
    }
    /* Enable the USARTy Interrupt */
    NVIC_Init(pUSARTParams->NVIC_InitStructure);
  }
  
  /* Enable the USART */
  USART_Cmd(pUSARTParams->USARTx, ENABLE);
}

/*******************************************************************************
* Function Name  : USART_IRQ_Handler
* Description    : Interrupt function for the serial communication
* Input          : none 
* Return         : none
*******************************************************************************/
void* USART_IRQ_Handler(void* this,unsigned char flags, unsigned short rx_data)
{
  void* pRetVal = MC_NULL;
  if (flags == 0) // Flag 0 = RX
  {
    /* Read one byte from the receive data register */
    if (((_CCOM)this)->Vars_str.PL_Data.RX.Buffer != MC_NULL && 
        ((_CCOM)this)->Vars_str.PL_Data.RX.BufferTransfer < ((_CCOM)this)->Vars_str.PL_Data.RX.BufferCount)
    {
      ((_CCOM)this)->Vars_str.PL_Data.RX.Buffer[((_CCOM)this)->Vars_str.PL_Data.RX.BufferTransfer++] = (uint16_t)(rx_data & (uint16_t)0x01FF);
            
      pRetVal = ReceivingFrame(((_CCOM)this)->Vars_str.parent,((_CCOM)this)->Vars_str.PL_Data.RX.Buffer,((_CCOM)this)->Vars_str.PL_Data.RX.BufferTransfer);
    }
  }
  
  if (flags == 1) // Flag 1 = TX
  {
    /* Write one byte to the transmit data register */
    USART_SendData(((_CUSART)(((_CCOM)this)->DerivedClass))->pDParams_str->USARTx, ((_CCOM)this)->Vars_str.PL_Data.TX.Buffer[((_CCOM)this)->Vars_str.PL_Data.TX.BufferTransfer++]);                   
    
    if (((_CCOM)this)->Vars_str.PL_Data.TX.BufferCount <= ((_CCOM)this)->Vars_str.PL_Data.TX.BufferTransfer)
    {
      /* Disable the USART Transfer interrupt */
      USART_ITConfig(((_CUSART)(((_CCOM)this)->DerivedClass))->pDParams_str->USARTx, USART_IT_TXE, DISABLE);
  
      SendingFrame(((_CCOM)this)->Vars_str.parent,((_CCOM)this)->Vars_str.PL_Data.TX.Buffer, ((_CCOM)this)->Vars_str.PL_Data.TX.BufferTransfer);

      //Init communication for next transfer;
      //PL_ResetTX();
    }
  }
  if (flags == 2) // Flag 2 = Send overrun error
  {
    FCP_SendOverrunMeassage(((_CCOM)this)->Vars_str.parent);
  }
  if (flags == 3) // Flag 3 = Send timeout error
  {
    FCP_SendTimeoutMeassage(((_CCOM)this)->Vars_str.parent);
  }
  if (flags == 4) // Flag 4 = Send ATR message
  {
    FCP_SendATRMeassage(((_CCOM)this)->Vars_str.parent);
  }
  return pRetVal;
}

/**
  * @brief  Start receive from the channel (IRQ enabling implementation)
  * @param  this: COM object 
  * @retval None
  */
static void USART_StartReceive(CCOM this)
{
  USART_ITConfig(((_CUSART)(((_CCOM)this)->DerivedClass))->pDParams_str->USARTx, USART_IT_RXNE, ENABLE);
}

/**
  * @brief  Start transmit to the channel (IRQ enabling implementation)
  * @param  this: COM object 
  * @retval None
  */
static void USART_StartTransmit(CCOM this)
{
  USART_ITConfig(((_CUSART)(((_CCOM)this)->DerivedClass))->pDParams_str->USARTx, USART_IT_TXE, ENABLE);
}
/******************* (C) COPYRIGHT 2016 STMicroelectronics *****END OF FILE****/
