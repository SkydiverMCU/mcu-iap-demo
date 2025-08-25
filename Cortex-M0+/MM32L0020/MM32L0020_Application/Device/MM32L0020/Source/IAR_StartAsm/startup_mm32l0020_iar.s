;/***********************************************************************************************************************
;    @file     startup_mm32_iar.s
;    @author   VV TEAM
;    @brief    THIS FILE PROVIDES ALL THE Device Startup File of MM32 Cortex-M
;              Core Device for IAR EWARM toolchain.
;  **********************************************************************************************************************
;    @attention
;
;    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>
;
;      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
;    following conditions are met:
;    1. Redistributions of source code must retain the above copyright notice,
;       this list of conditions and the following disclaimer.
;    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
;       the following disclaimer in the documentation and/or other materials provided with the distribution.
;    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
;       promote products derived from this software without specific prior written permission.
;
;      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
;    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
;    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
;    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
;    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
;    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;  *********************************************************************************************************************/


                MODULE  ?cstartup

                                                                                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC  __vector_table
                PUBLIC  __Vectors
                PUBLIC  __Vectors_End
                PUBLIC  __Vectors_Size

                DATA
__vector_table
                DCD     sfe(CSTACK)                                             ;       Top of Stack                    |   0 0x0000                 
                DCD     Reset_Handler                                           ;    Reset Handler                 
                DCD     NMI_Handler                                             ;    NMI Handler                   
                DCD     HardFault_Handler                                       ;    Hard Fault Handler            
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved      
                DCD     0                                                       ;    Reserved   
                DCD     0                                                       ;    Reserved   
                DCD     0                                                       ;    Reserved   
                DCD     0                                                       ;    Reserved   				
                DCD     SVC_Handler                                             ;    SVCall Handler                
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     PendSV_Handler                                          ;    PendSV Handler                
                DCD     SysTick_Handler                                         ;    SysTick Handler               

                ; External Interrupts
                DCD     WWDG_IWDG_IRQHandler                                    ;    WWDG_IWDG thru EXTI21         
                DCD     PVD_IRQHandler                                          ;    PVD through EXTI 16           
                DCD     0                                                       ;    Reserved                      
                DCD     FLASH_IRQHandler                                        ;    FLASH                         
                DCD     RCC_IRQHandler                                          ;    RCC                           
                DCD     EXTI0_1_IRQHandler                                      ;    EXTI Line 0 and 1             
                DCD     EXTI2_3_IRQHandler                                      ;    EXTI Line 2 and 3             
                DCD     EXTI4_15_IRQHandler                                     ;    EXTI Line 4 to 15             
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     ADC_COMP_IRQHandler                                     ;    ADC_COMP                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     TIM3_IRQHandler                                         ;    TIM3                          
                DCD     LPUART_IRQHandler                                       ;    LPUART                       
                DCD     LPTIMER_IRQHandler                                      ;    LPTIMER                         
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     TIM16_IRQHandler                                        ;    TIM16                         
                DCD     TIM17_IRQHandler                                        ;    TIM17                         
                DCD     I2C1_IRQHandler                                         ;    I2C1                          
                DCD     0                                                       ;    Reserved                      
                DCD     SPI1_IRQHandler                                         ;    SPI1                          
                DCD     0                                                       ;    Reserved                      
                DCD     UART1_IRQHandler                                        ;    UART1                         
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      
                DCD     0                                                       ;    Reserved                      

                                                                                ; Total Cortex-M0 32 Interrupts are setting

__Vectors_End

__Vectors       EQU     __vector_table
__Vectors_Size  EQU     __Vectors_End - __Vectors



                THUMB

; Reset Handler

                PUBWEAK Reset_Handler
                SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                PUBWEAK HardFault_Handler
                PUBWEAK SVC_Handler
                PUBWEAK PendSV_Handler
                PUBWEAK SysTick_Handler
                PUBWEAK WWDG_IWDG_IRQHandler
                PUBWEAK PVD_IRQHandler
                PUBWEAK FLASH_IRQHandler
                PUBWEAK RCC_IRQHandler
                PUBWEAK EXTI0_1_IRQHandler
                PUBWEAK EXTI2_3_IRQHandler
                PUBWEAK EXTI4_15_IRQHandler
                PUBWEAK ADC_COMP_IRQHandler
                PUBWEAK TIM3_IRQHandler
                PUBWEAK LPUART_IRQHandler
                PUBWEAK LPTIMER_IRQHandler
                PUBWEAK TIM16_IRQHandler
                PUBWEAK TIM17_IRQHandler
                PUBWEAK I2C1_IRQHandler
                PUBWEAK SPI1_IRQHandler
                PUBWEAK UART1_IRQHandler

                SECTION .text:CODE:REORDER:NOROOT(1)




NMI_Handler
HardFault_Handler
SVC_Handler
PendSV_Handler
SysTick_Handler
WWDG_IWDG_IRQHandler
PVD_IRQHandler
FLASH_IRQHandler
RCC_IRQHandler
EXTI0_1_IRQHandler
EXTI2_3_IRQHandler
EXTI4_15_IRQHandler
ADC_COMP_IRQHandler
TIM3_IRQHandler
LPUART_IRQHandler
LPTIMER_IRQHandler
TIM16_IRQHandler
TIM17_IRQHandler
I2C1_IRQHandler
SPI1_IRQHandler
UART1_IRQHandler

Default_Handler
                B       .
                END

