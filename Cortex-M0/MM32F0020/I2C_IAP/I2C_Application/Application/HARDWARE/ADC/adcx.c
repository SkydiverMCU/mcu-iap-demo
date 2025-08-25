////////////////////////////////////////////////////////////////////////////////
/// @file    adcx.c
/// @author  AE TEAM
/// @brief   Output received data.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////
// Define to prevent recursive inclusion
#define _ADCX_C_

// Files includes
#include "delay.h"
#include "adcx.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ADCX
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ADC_Exported_Functions
/// @{





////////////////////////////////////////////////////////////////////////////////
/// @brief  Set ADCn sample time.
/// @param  ADCn: where n can be 1, 2 to select the ADC peripheral.
/// @param  channel: the ADC channel to configure.
/// @param  sampleTime: the ADC Channel n Sample time to configure.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
static void ADCxSampleTimeConfig(ADC_TypeDef* ADCn, ADCSAM_TypeDef sampleTime)
{
    ADCn->CFGR &= ~ADC_CFGR_SAMCTL;
    ADCn->CFGR |= sampleTime;
}
////////////////////////////////////////////////////////////////////////////////
/// @brief  ADC1 Pin Config
/// @param  None
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void ADC1PinConfigWithParameter(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);
    
    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOA, ENABLE);
	
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource0,GPIO_AF_1);
//	GPIO_PinAFConfig(GPIOB,GPIO_PinSource1,GPIO_AF_1);

    GPIO_InitStructure.GPIO_Pin  =  GPIO_Pin_3|GPIO_Pin_11|GPIO_Pin_12;         //ADC_CH2,ADC_CH4,ADC_CH3
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                           //Output speed
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;                               //GPIO mode
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	

}

////////////////////////////////////////////////////////////////////////////////
/// @brief  Serial port initialization configuration
/// @note
/// @param  bound: Baud rate
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void ADC_Config(void)
{
    ADC_InitTypeDef  ADC_InitStructure;

    ADC_StructInit(&ADC_InitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1ENR_ADC1, ENABLE);                    //Enable ADC clock
	
	ADC1PinConfigWithParameter();
    
	ADC_DeInit(ADC1);
	
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_PRESCARE = ADC_PCLK2_PRESCARE_16;                     //ADC prescale factor
    ADC_InitStructure.ADC_Mode = ADC_Mode_Scan;                                 //ADC_Mode_Continue;                             //Set ADC mode to continuous conversion mode
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;                      //AD data right-justified
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
    ADC_Init(ADC1, &ADC_InitStructure);

	
    ADCxSampleTimeConfig(ADC1, ADC_Samctl_13_5);
	ADC_ANY_NUM_Config(ADC1, 2);                                                //set Single(one) Channel as Analog iuput
    ADC_ANY_CH_Config(ADC1, 0, ADC_Channel_2);                                  //assign ADC channel 2 to RANK 0;
	ADC_ANY_CH_Config(ADC1, 1, ADC_Channel_3);                                  //assign ADC channel 3 to RANK 1;
	ADC_ANY_CH_Config(ADC1, 2, ADC_Channel_4);                                  //assign ADC channel 4 to RANK 2;
	//ADC_ANY_CH_Config(ADC1, 3, ADC_Channel_7);                                  //assign ADC channel 7 to RANK 3;
	
	ADC_ANY_Cmd(ADC1, ENABLE);                                                  //Enable and use ANYChan to control ADC sample
	
    ADC_Cmd(ADC1, ENABLE);                                                      //Enable AD conversion
}

////////////////////////////////////////////////////////////////////////////////
/// @brief  This function is getting the convert data
/// @note   Software enables more than one channel, the channel with the smallest
///         sequence number is converted, and other channels are ignored.
/// @param  None.
/// @retval puiADData.
////////////////////////////////////////////////////////////////////////////////
void GetSingleChannelValue(u16 *pAD_DATA)
{

    ADC_SoftwareStartConvCmd(ADC1, ENABLE);                                     //Software start conversion
    while(ADC_GetFlagStatus(ADC1, ADC_IT_EOC) == 0);
    ADC_ClearFlag(ADC1, ADC_IT_EOC);
    
	pAD_DATA[0] = ADC1->ADDR2&0x0fff;
	pAD_DATA[1] = ADC1->ADDR3&0x0fff;
	pAD_DATA[2] = ADC1->ADDR4&0x0fff;
//	pAD_DATA[3] = ADC1->ADDR7&0x0fff;
}


/// @}


/// @}

/// @}


