#include "tim14.h"

void TIM14_Config(u16 arr, u16 psc)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_StructInit;

    RCC_APB1PeriphClockCmd(RCC_APB1ENR_TIM14, ENABLE);
	
	NVIC_StructInit.NVIC_IRQChannel = TIM14_IRQn;
    NVIC_StructInit.NVIC_IRQChannelPriority = 1;
    NVIC_StructInit.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_StructInit);

    TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
	

    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = arr;
    TIM_TimeBaseStructure.TIM_Prescaler = psc;
    //Setting Clock Segmentation
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
    ///TIM Upward Counting Mode
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);
	
	TIM_ITConfig(TIM14,TIM_IT_Update,ENABLE);
	
	TIM_Cmd(TIM14,ENABLE);
	
}

void TIM14_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM14, TIM_IT_Update) != RESET) 
	{
        TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
        //GPIOA->ODR ^= GPIO_Pin_2;
    }
}















