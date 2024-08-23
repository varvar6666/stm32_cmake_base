#include <stdint.h>

#if defined(STM32F405RG) || defined(STM32F446RE)
#define RAM_SIZE		128 * 1024
#elif defined(STM32F722RE)
#define RAM_SIZE		256 * 1024
#elif defined(STM32F746ZG)
#define RAM_SIZE		320 * 1024
#elif defined(STM32F767VI)
#define RAM_SIZE		512 * 1024
#else
#error "No RAM SIZE chip!"
#endif

#define RAM_START		0x20000000
#define RAM_END			((RAM_START) + (RAM_SIZE))

void Default_Handler(void) {
	while(1) {}
}

#if defined(STM32F446xx)

void Reset_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void NMI_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));

void SVC_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)               	__attribute__ ((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)        	__attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)               	__attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)               	__attribute__ ((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)     	__attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)     	__attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)            	__attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)            	__attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)            	__attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)         	__attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)         	__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)       	__attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler(void)    	__attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler(void)     	__attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void FMC_IRQHandler(void)               	__attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)             	__attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void)            	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void)      	__attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler(void)            	__attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler(void)    	__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler(void)     	__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler(void)       	__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler(void)            	__attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void SAI1_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void SAI2_IRQHandler(void)              	__attribute__ ((weak, alias("Default_Handler")));
void QuadSPI_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void HDMI_CEC_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void SPDIF_Rx_IRQHandler(void)          	__attribute__ ((weak, alias("Default_Handler")));
void FMPI2C1_IRQHandler(void)           	__attribute__ ((weak, alias("Default_Handler")));
void FMPI2C1_error_IRQHandler(void)     	__attribute__ ((weak, alias("Default_Handler")));


__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
    (uint32_t) RAM_END,
	(uint32_t)	Reset_Handler,
	(uint32_t)	NMI_Handler,
	(uint32_t)	HardFault_Handler,
	(uint32_t)	MemManage_Handler,
	(uint32_t)	BusFault_Handler,
	(uint32_t)	UsageFault_Handler,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	SVC_Handler,
	(uint32_t)	DebugMon_Handler,
	(uint32_t)	0,
	(uint32_t)	PendSV_Handler,
	(uint32_t)	SysTick_Handler,
	(uint32_t)	WWDG_IRQHandler,              			/* Window Watchdog interrupt                                          */
	(uint32_t)	PVD_IRQHandler,               			/* PVD through EXTI line detection interrupt                          */
	(uint32_t)	TAMP_STAMP_IRQHandler,        			/* Tamper and TimeStamp interrupts through the EXTI line              */
	(uint32_t)	RTC_WKUP_IRQHandler,          			/* RTC Wakeup interrupt through the EXTI line                         */
	(uint32_t)	FLASH_IRQHandler,             			/* Flash global interrupt                                             */
	(uint32_t)	RCC_IRQHandler,               			/* RCC global interrupt                                               */
	(uint32_t)	EXTI0_IRQHandler,             			/* EXTI Line0 interrupt                                               */
	(uint32_t)	EXTI1_IRQHandler,             			/* EXTI Line1 interrupt                                               */
	(uint32_t)	EXTI2_IRQHandler,             			/* EXTI Line2 interrupt                                               */
	(uint32_t)	EXTI3_IRQHandler,             			/* EXTI Line3 interrupt                                               */
	(uint32_t)	EXTI4_IRQHandler,             			/* EXTI Line4 interrupt                                               */
	(uint32_t)	DMA1_Stream0_IRQHandler,      			/* DMA1 Stream0 global interrupt                                      */
	(uint32_t)	DMA1_Stream1_IRQHandler,      			/* DMA1 Stream1 global interrupt                                      */
	(uint32_t)	DMA1_Stream2_IRQHandler,      			/* DMA1 Stream2 global interrupt                                      */
	(uint32_t)	DMA1_Stream3_IRQHandler,      			/* DMA1 Stream3 global interrupt                                      */
	(uint32_t)	DMA1_Stream4_IRQHandler,      			/* DMA1 Stream4 global interrupt                                      */
	(uint32_t)	DMA1_Stream5_IRQHandler,      			/* DMA1 Stream5 global interrupt                                      */
	(uint32_t)	DMA1_Stream6_IRQHandler,      			/* DMA1 Stream6 global interrupt                                      */
	(uint32_t)	ADC_IRQHandler,               			/* ADC1 global interrupt                                              */
	(uint32_t)	CAN1_TX_IRQHandler,           			/* CAN1 TX interrupts                                                 */
	(uint32_t)	CAN1_RX0_IRQHandler,          			/* CAN1 RX0 interrupts                                                */
	(uint32_t)	CAN1_RX1_IRQHandler,          			/* CAN1 RX1 interrupts                                                */
	(uint32_t)	CAN1_SCE_IRQHandler,          			/* CAN1 SCE interrupt                                                 */
	(uint32_t)	EXTI9_5_IRQHandler,           			/* EXTI Line[9:5] interrupts                                          */
	(uint32_t)	TIM1_BRK_TIM9_IRQHandler,     			/* TIM1 Break interrupt and TIM9 global interrupt                     */
	(uint32_t)	TIM1_UP_TIM10_IRQHandler,     			/* TIM1 Update interrupt and TIM10 global interrupt                   */
	(uint32_t)	TIM1_TRG_COM_TIM11_IRQHandler,			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
	(uint32_t)	TIM1_CC_IRQHandler,           			/* TIM1 Capture Compare interrupt                                     */
	(uint32_t)	TIM2_IRQHandler,              			/* TIM2 global interrupt                                              */
	(uint32_t)	TIM3_IRQHandler,              			/* TIM3 global interrupt                                              */
	(uint32_t)	TIM4_IRQHandler,              			/* TIM4 global interrupt                                              */
	(uint32_t)	I2C1_EV_IRQHandler,           			/* I2C1 event interrupt                                               */
	(uint32_t)	I2C1_ER_IRQHandler,           			/* I2C1 error interrupt                                               */
	(uint32_t)	I2C2_EV_IRQHandler,           			/* I2C2 event interrupt                                               */
	(uint32_t)	I2C2_ER_IRQHandler,           			/* I2C2 error interrupt                                               */
	(uint32_t)	SPI1_IRQHandler,              			/* SPI1 global interrupt                                              */
	(uint32_t)	SPI2_IRQHandler,              			/* SPI2 global interrupt                                              */
	(uint32_t)	USART1_IRQHandler,            			/* USART1 global interrupt                                            */
	(uint32_t)	USART2_IRQHandler,            			/* USART2 global interrupt                                            */
	(uint32_t)	USART3_IRQHandler,            			/* USART3 global interrupt                                            */
	(uint32_t)	EXTI15_10_IRQHandler,         			/* EXTI Line[15:10] interrupts                                        */
	(uint32_t)	RTC_Alarm_IRQHandler,         			/* RTC Alarms (A and B) through EXTI line interrupt                   */
	(uint32_t)	OTG_FS_WKUP_IRQHandler,       			/* USB On-The-Go FS Wakeup through EXTI line interrupt                */
	(uint32_t)	TIM8_BRK_TIM12_IRQHandler,    			/* TIM8 Break interrupt and TIM12 global interrupt                    */
	(uint32_t)	TIM8_UP_TIM13_IRQHandler,     			/* TIM8 Update interrupt and TIM13 global interrupt                   */
	(uint32_t)	TIM8_TRG_COM_TIM14_IRQHandler,			/* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
	(uint32_t)	TIM8_CC_IRQHandler,           			/* TIM8 Capture Compare interrupt                                     */
	(uint32_t)	DMA1_Stream7_IRQHandler,      			/* DMA1 Stream7 global interrupt                                      */
	(uint32_t)	FMC_IRQHandler,               			/* FMC global interrupt                                               */
	(uint32_t)	SDIO_IRQHandler,              			/* SDIO global interrupt                                              */
	(uint32_t)	TIM5_IRQHandler,              			/* TIM5 global interrupt                                              */
	(uint32_t)	SPI3_IRQHandler,              			/* SPI3 global interrupt                                              */
	(uint32_t)	UART4_IRQHandler,             			/* UART4 global interrupt                                             */
	(uint32_t)	UART5_IRQHandler,             			/* UART5 global interrupt                                             */
	(uint32_t)	TIM6_DAC_IRQHandler,          			/* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt      */
	(uint32_t)	TIM7_IRQHandler,              			/* TIM7 global interrupt                                              */
	(uint32_t)	DMA2_Stream0_IRQHandler,      			/* DMA2 Stream0 global interrupt                                      */
	(uint32_t)	DMA2_Stream1_IRQHandler,      			/* DMA2 Stream1 global interrupt                                      */
	(uint32_t)	DMA2_Stream2_IRQHandler,      			/* DMA2 Stream2 global interrupt                                      */
	(uint32_t)	DMA2_Stream3_IRQHandler,      			/* DMA2 Stream3 global interrupt                                      */
	(uint32_t)	DMA2_Stream4_IRQHandler,      			/* DMA2 Stream4 global interrupt                                      */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	CAN2_TX_IRQHandler,           			/* CAN2 TX interrupts                                                 */
	(uint32_t)	CAN2_RX0_IRQHandler,          			/* CAN2 RX0 interrupts                                                */
	(uint32_t)	CAN2_RX1_IRQHandler,          			/* CAN2 RX1 interrupts                                                */
	(uint32_t)	CAN2_SCE_IRQHandler,          			/* CAN2 SCE interrupt                                                 */
	(uint32_t)	OTG_FS_IRQHandler,            			/* USB On The Go FS global interrupt                                  */
	(uint32_t)	DMA2_Stream5_IRQHandler,      			/* DMA2 Stream5 global interrupt                                      */
	(uint32_t)	DMA2_Stream6_IRQHandler,      			/* DMA2 Stream6 global interrupt                                      */
	(uint32_t)	DMA2_Stream7_IRQHandler,      			/* DMA2 Stream7 global interrupt                                      */
	(uint32_t)	USART6_IRQHandler,            			/* USART6 global interrupt                                            */
	(uint32_t)	I2C3_EV_IRQHandler,           			/* I2C3 event interrupt                                               */
	(uint32_t)	I2C3_ER_IRQHandler,           			/* I2C3 error interrupt                                               */
	(uint32_t)	OTG_HS_EP1_OUT_IRQHandler,    			/* USB On The Go HS End Point 1 Out                                   */
	(uint32_t)	OTG_HS_EP1_IN_IRQHandler,     			/* USB On The Go HS End Point 1 In                                    */
	(uint32_t)	OTG_HS_WKUP_IRQHandler,       			/* USB On The Go HS Wakeup                                            */
	(uint32_t)	OTG_HS_IRQHandler,            			/* USB On The Go HS global interrupt                                  */
	(uint32_t)	DCMI_IRQHandler,              			/* DCMI global interrupt                                              */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	SPI4_IRQHandler,              			/* SPI 4 global interrupt                                             */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	SAI1_IRQHandler,              			/* SAI1 global interrupt                                              */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	SAI2_IRQHandler,              			/* SAI2 global interrupt                                              */
	(uint32_t)	QuadSPI_IRQHandler,           			/* QuadSPI global interrupt                                           */
	(uint32_t)	HDMI_CEC_IRQHandler,          			/* HDMI-CEC global interrupt                                          */
	(uint32_t)	SPDIF_Rx_IRQHandler,          			/* SPDIF-Rx global interrupt                                          */
	(uint32_t)	FMPI2C1_IRQHandler,           			/* FMPI2C1 event interrupt                                            */
	(uint32_t)	FMPI2C1_error_IRQHandler,     			/* FMPI2C1 error interrupt                                            */
};

#elif defined(STM32F405xx)

void Reset_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void NMI_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)			__attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)			__attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)			__attribute__ ((weak, alias("Default_Handler")));

void SVC_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)__attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler(void)__attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void FMC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DCMI_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SAI1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SAI2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void QuadSPI_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void HDMI_CEC_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void SPDIF_Rx_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void FMPI2C1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void FMPI2C1_error_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));

__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
	(uint32_t) RAM_END,
	(uint32_t)	Reset_Handler,
	(uint32_t)	NMI_Handler,
	(uint32_t)	HardFault_Handler,
	(uint32_t)	MemManage_Handler,
	(uint32_t)	BusFault_Handler,
	(uint32_t)	UsageFault_Handler,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	SVC_Handler,
	(uint32_t)	DebugMon_Handler,
	(uint32_t)	0,
	(uint32_t)	PendSV_Handler,
	(uint32_t)	SysTick_Handler,
	(uint32_t)	WWDG_IRQHandler,              			/* Window Watchdog interrupt                                          */
	(uint32_t)	PVD_IRQHandler,               			/* PVD through EXTI line detection interrupt                          */
	(uint32_t)	TAMP_STAMP_IRQHandler,        			/* Tamper and TimeStamp interrupts through the EXTI line              */
	(uint32_t)	RTC_WKUP_IRQHandler,          			/* RTC Wakeup interrupt through the EXTI line                         */
	(uint32_t)	FLASH_IRQHandler,             			/* Flash global interrupt                                             */
	(uint32_t)	RCC_IRQHandler,               			/* RCC global interrupt                                               */
	(uint32_t)	EXTI0_IRQHandler,             			/* EXTI Line0 interrupt                                               */
	(uint32_t)	EXTI1_IRQHandler,             			/* EXTI Line1 interrupt                                               */
	(uint32_t)	EXTI2_IRQHandler,             			/* EXTI Line2 interrupt                                               */
	(uint32_t)	EXTI3_IRQHandler,             			/* EXTI Line3 interrupt                                               */
	(uint32_t)	EXTI4_IRQHandler,             			/* EXTI Line4 interrupt                                               */
	(uint32_t)	DMA1_Stream0_IRQHandler,      			/* DMA1 Stream0 global interrupt                                      */
	(uint32_t)	DMA1_Stream1_IRQHandler,      			/* DMA1 Stream1 global interrupt                                      */
	(uint32_t)	DMA1_Stream2_IRQHandler,      			/* DMA1 Stream2 global interrupt                                      */
	(uint32_t)	DMA1_Stream3_IRQHandler,      			/* DMA1 Stream3 global interrupt                                      */
	(uint32_t)	DMA1_Stream4_IRQHandler,      			/* DMA1 Stream4 global interrupt                                      */
	(uint32_t)	DMA1_Stream5_IRQHandler,      			/* DMA1 Stream5 global interrupt                                      */
	(uint32_t)	DMA1_Stream6_IRQHandler,      			/* DMA1 Stream6 global interrupt                                      */
	(uint32_t)	ADC_IRQHandler,               			/* ADC1 global interrupt                                              */
	(uint32_t)	CAN1_TX_IRQHandler,           			/* CAN1 TX interrupts                                                 */
	(uint32_t)	CAN1_RX0_IRQHandler,          			/* CAN1 RX0 interrupts                                                */
	(uint32_t)	CAN1_RX1_IRQHandler,          			/* CAN1 RX1 interrupts                                                */
	(uint32_t)	CAN1_SCE_IRQHandler,          			/* CAN1 SCE interrupt                                                 */
	(uint32_t)	EXTI9_5_IRQHandler,           			/* EXTI Line[9:5] interrupts                                          */
	(uint32_t)	TIM1_BRK_TIM9_IRQHandler,     			/* TIM1 Break interrupt and TIM9 global interrupt                     */
	(uint32_t)	TIM1_UP_TIM10_IRQHandler,     			/* TIM1 Update interrupt and TIM10 global interrupt                   */
	(uint32_t)	TIM1_TRG_COM_TIM11_IRQHandler,			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
	(uint32_t)	TIM1_CC_IRQHandler,           			/* TIM1 Capture Compare interrupt                                     */
	(uint32_t)	TIM2_IRQHandler,              			/* TIM2 global interrupt                                              */
	(uint32_t)	TIM3_IRQHandler,              			/* TIM3 global interrupt                                              */
	(uint32_t)	TIM4_IRQHandler,              			/* TIM4 global interrupt                                              */
	(uint32_t)	I2C1_EV_IRQHandler,           			/* I2C1 event interrupt                                               */
	(uint32_t)	I2C1_ER_IRQHandler,           			/* I2C1 error interrupt                                               */
	(uint32_t)	I2C2_EV_IRQHandler,           			/* I2C2 event interrupt                                               */
	(uint32_t)	I2C2_ER_IRQHandler,           			/* I2C2 error interrupt                                               */
	(uint32_t)	SPI1_IRQHandler,              			/* SPI1 global interrupt                                              */
	(uint32_t)	SPI2_IRQHandler,              			/* SPI2 global interrupt                                              */
	(uint32_t)	USART1_IRQHandler,            			/* USART1 global interrupt                                            */
	(uint32_t)	USART2_IRQHandler,            			/* USART2 global interrupt                                            */
	(uint32_t)	USART3_IRQHandler,            			/* USART3 global interrupt                                            */
	(uint32_t)	EXTI15_10_IRQHandler,         			/* EXTI Line[15:10] interrupts                                        */
	(uint32_t)	RTC_Alarm_IRQHandler,         			/* RTC Alarms (A and B) through EXTI line interrupt                   */
	(uint32_t)	OTG_FS_WKUP_IRQHandler,       			/* USB On-The-Go FS Wakeup through EXTI line interrupt                */
	(uint32_t)	TIM8_BRK_TIM12_IRQHandler,    			/* TIM8 Break interrupt and TIM12 global interrupt                    */
	(uint32_t)	TIM8_UP_TIM13_IRQHandler,     			/* TIM8 Update interrupt and TIM13 global interrupt                   */
	(uint32_t)	TIM8_TRG_COM_TIM14_IRQHandler,			/* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
	(uint32_t)	TIM8_CC_IRQHandler,           			/* TIM8 Capture Compare interrupt                                     */
	(uint32_t)	DMA1_Stream7_IRQHandler,      			/* DMA1 Stream7 global interrupt                                      */
	(uint32_t)	FMC_IRQHandler,               			/* FMC global interrupt                                               */
	(uint32_t)	SDIO_IRQHandler,              			/* SDIO global interrupt                                              */
	(uint32_t)	TIM5_IRQHandler,              			/* TIM5 global interrupt                                              */
	(uint32_t)	SPI3_IRQHandler,              			/* SPI3 global interrupt                                              */
	(uint32_t)	UART4_IRQHandler,             			/* UART4 global interrupt                                             */
	(uint32_t)	UART5_IRQHandler,             			/* UART5 global interrupt                                             */
	(uint32_t)	TIM6_DAC_IRQHandler,          			/* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt      */
	(uint32_t)	TIM7_IRQHandler,              			/* TIM7 global interrupt                                              */
	(uint32_t)	DMA2_Stream0_IRQHandler,      			/* DMA2 Stream0 global interrupt                                      */
	(uint32_t)	DMA2_Stream1_IRQHandler,      			/* DMA2 Stream1 global interrupt                                      */
	(uint32_t)	DMA2_Stream2_IRQHandler,      			/* DMA2 Stream2 global interrupt                                      */
	(uint32_t)	DMA2_Stream3_IRQHandler,      			/* DMA2 Stream3 global interrupt                                      */
	(uint32_t)	DMA2_Stream4_IRQHandler,      			/* DMA2 Stream4 global interrupt                                      */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	CAN2_TX_IRQHandler,           			/* CAN2 TX interrupts                                                 */
	(uint32_t)	CAN2_RX0_IRQHandler,          			/* CAN2 RX0 interrupts                                                */
	(uint32_t)	CAN2_RX1_IRQHandler,          			/* CAN2 RX1 interrupts                                                */
	(uint32_t)	CAN2_SCE_IRQHandler,          			/* CAN2 SCE interrupt                                                 */
	(uint32_t)	OTG_FS_IRQHandler,            			/* USB On The Go FS global interrupt                                  */
	(uint32_t)	DMA2_Stream5_IRQHandler,      			/* DMA2 Stream5 global interrupt                                      */
	(uint32_t)	DMA2_Stream6_IRQHandler,      			/* DMA2 Stream6 global interrupt                                      */
	(uint32_t)	DMA2_Stream7_IRQHandler,      			/* DMA2 Stream7 global interrupt                                      */
	(uint32_t)	USART6_IRQHandler,            			/* USART6 global interrupt                                            */
	(uint32_t)	I2C3_EV_IRQHandler,           			/* I2C3 event interrupt                                               */
	(uint32_t)	I2C3_ER_IRQHandler,           			/* I2C3 error interrupt                                               */
	(uint32_t)	OTG_HS_EP1_OUT_IRQHandler,    			/* USB On The Go HS End Point 1 Out                                   */
	(uint32_t)	OTG_HS_EP1_IN_IRQHandler,     			/* USB On The Go HS End Point 1 In                                    */
	(uint32_t)	OTG_HS_WKUP_IRQHandler,       			/* USB On The Go HS Wakeup                                            */
	(uint32_t)	OTG_HS_IRQHandler,            			/* USB On The Go HS global interrupt                                  */
	(uint32_t)	DCMI_IRQHandler,              			/* DCMI global interrupt                                              */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	SPI4_IRQHandler,              			/* SPI 4 global interrupt                                             */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	SAI1_IRQHandler,              			/* SAI1 global interrupt                                              */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	0,                            			/* Reserved                                                           */
	(uint32_t)	SAI2_IRQHandler,              			/* SAI2 global interrupt                                              */
	(uint32_t)	QuadSPI_IRQHandler,           			/* QuadSPI global interrupt                                           */
	(uint32_t)	HDMI_CEC_IRQHandler,          			/* HDMI-CEC global interrupt                                          */
	(uint32_t)	SPDIF_Rx_IRQHandler,          			/* SPDIF-Rx global interrupt                                          */
	(uint32_t)	FMPI2C1_IRQHandler,           			/* FMPI2C1 event interrupt                                            */
	(uint32_t)	FMPI2C1_error_IRQHandler,     			/* FMPI2C1 error interrupt                                            */
};

#elif defined(STM32F722xx)

void Reset_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void NMI_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));

void WWDG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void FMC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SDMMC1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void RNG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UART7_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UART8_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SPI5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SAI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SAI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));
void QUADSPI_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SDMMC2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));

__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
	(uint32_t)	RAM_END,
	(uint32_t)	Reset_Handler,
	(uint32_t)	NMI_Handler,
	(uint32_t)	HardFault_Handler,
	(uint32_t)	MemManage_Handler,
	(uint32_t)	BusFault_Handler,
	(uint32_t)	UsageFault_Handler,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	SVC_Handler,
	(uint32_t)	DebugMon_Handler,
	(uint32_t)	0,
	(uint32_t)	PendSV_Handler,
	(uint32_t)	SysTick_Handler,
	(uint32_t)	WWDG_IRQHandler,                   /* Window WatchDog              */                                        
	(uint32_t)	PVD_IRQHandler,                    /* PVD through EXTI Line detection */                        
	(uint32_t)	TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */            
	(uint32_t)	RTC_WKUP_IRQHandler,               /* RTC Wakeup through the EXTI line */                      
	(uint32_t)	FLASH_IRQHandler,                  /* FLASH                        */                                          
	(uint32_t)	RCC_IRQHandler,                    /* RCC                          */                                            
	(uint32_t)	EXTI0_IRQHandler,                  /* EXTI Line0                   */                        
	(uint32_t)	EXTI1_IRQHandler,                  /* EXTI Line1                   */                          
	(uint32_t)	EXTI2_IRQHandler,                  /* EXTI Line2                   */                          
	(uint32_t)	EXTI3_IRQHandler,                  /* EXTI Line3                   */                          
	(uint32_t)	EXTI4_IRQHandler,                  /* EXTI Line4                   */                          
	(uint32_t)	DMA1_Stream0_IRQHandler,           /* DMA1 Stream 0                */                  
	(uint32_t)	DMA1_Stream1_IRQHandler,           /* DMA1 Stream 1                */                   
	(uint32_t)	DMA1_Stream2_IRQHandler,           /* DMA1 Stream 2                */                   
	(uint32_t)	DMA1_Stream3_IRQHandler,           /* DMA1 Stream 3                */                   
	(uint32_t)	DMA1_Stream4_IRQHandler,           /* DMA1 Stream 4                */                   
	(uint32_t)	DMA1_Stream5_IRQHandler,           /* DMA1 Stream 5                */                   
	(uint32_t)	DMA1_Stream6_IRQHandler,           /* DMA1 Stream 6                */                   
	(uint32_t)	ADC_IRQHandler,                    /* ADC1, ADC2 and ADC3s         */                   
	(uint32_t)	CAN1_TX_IRQHandler,                /* CAN1 TX                      */                         
	(uint32_t)	CAN1_RX0_IRQHandler,               /* CAN1 RX0                     */                          
	(uint32_t)	CAN1_RX1_IRQHandler,               /* CAN1 RX1                     */                          
	(uint32_t)	CAN1_SCE_IRQHandler,               /* CAN1 SCE                     */                          
	(uint32_t)	EXTI9_5_IRQHandler,                /* External Line[9:5]s          */                          
	(uint32_t)	TIM1_BRK_TIM9_IRQHandler,          /* TIM1 Break and TIM9          */         
	(uint32_t)	TIM1_UP_TIM10_IRQHandler,          /* TIM1 Update and TIM10        */         
	(uint32_t)	TIM1_TRG_COM_TIM11_IRQHandler,     /* TIM1 Trigger and Commutation and TIM11 */
	(uint32_t)	TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */                          
	(uint32_t)	TIM2_IRQHandler,                   /* TIM2                         */                   
	(uint32_t)	TIM3_IRQHandler,                   /* TIM3                         */                   
	(uint32_t)	TIM4_IRQHandler,                   /* TIM4                         */                   
	(uint32_t)	I2C1_EV_IRQHandler,                /* I2C1 Event                   */                          
	(uint32_t)	I2C1_ER_IRQHandler,                /* I2C1 Error                   */                          
	(uint32_t)	I2C2_EV_IRQHandler,                /* I2C2 Event                   */                          
	(uint32_t)	I2C2_ER_IRQHandler,                /* I2C2 Error                   */                            
	(uint32_t)	SPI1_IRQHandler,                   /* SPI1                         */                   
	(uint32_t)	SPI2_IRQHandler,                   /* SPI2                         */                   
	(uint32_t)	USART1_IRQHandler,                 /* USART1                       */                   
	(uint32_t)	USART2_IRQHandler,                 /* USART2                       */                   
	(uint32_t)	USART3_IRQHandler,                 /* USART3                       */                   
	(uint32_t)	EXTI15_10_IRQHandler,              /* External Line[15:10]s        */                          
	(uint32_t)	RTC_Alarm_IRQHandler,              /* RTC Alarm (A and B) through EXTI Line */                 
	(uint32_t)	OTG_FS_WKUP_IRQHandler,            /* USB OTG FS Wakeup through EXTI line */                       
	(uint32_t)	TIM8_BRK_TIM12_IRQHandler,         /* TIM8 Break and TIM12         */         
	(uint32_t)	TIM8_UP_TIM13_IRQHandler,          /* TIM8 Update and TIM13        */         
	(uint32_t)	TIM8_TRG_COM_TIM14_IRQHandler,     /* TIM8 Trigger and Commutation and TIM14 */
	(uint32_t)	TIM8_CC_IRQHandler,                /* TIM8 Capture Compare         */                          
	(uint32_t)	DMA1_Stream7_IRQHandler,           /* DMA1 Stream7                 */                          
	(uint32_t)	FMC_IRQHandler,                    /* FMC                          */                   
	(uint32_t)	SDMMC1_IRQHandler,                 /* SDMMC1                       */                   
	(uint32_t)	TIM5_IRQHandler,                   /* TIM5                         */                   
	(uint32_t)	SPI3_IRQHandler,                   /* SPI3                         */                   
	(uint32_t)	UART4_IRQHandler,                  /* UART4                        */                   
	(uint32_t)	UART5_IRQHandler,                  /* UART5                        */                   
	(uint32_t)	TIM6_DAC_IRQHandler,               /* TIM6 and DAC1&2 underrun errors */                   
	(uint32_t)	TIM7_IRQHandler,                   /* TIM7                         */
	(uint32_t)	DMA2_Stream0_IRQHandler,           /* DMA2 Stream 0                */                   
	(uint32_t)	DMA2_Stream1_IRQHandler,           /* DMA2 Stream 1                */                   
	(uint32_t)	DMA2_Stream2_IRQHandler,           /* DMA2 Stream 2                */                   
	(uint32_t)	DMA2_Stream3_IRQHandler,           /* DMA2 Stream 3                */                   
	(uint32_t)	DMA2_Stream4_IRQHandler,           /* DMA2 Stream 4                */                   
	(uint32_t)	0,                                 /* Reserved                     */                   
	(uint32_t)	0,                                 /* Reserved                     */                    
	(uint32_t)	0,                                 /* Reserved                     */                          
	(uint32_t)	0,                                 /* Reserved                     */                          
	(uint32_t)	0,                                 /* Reserved                     */                          
	(uint32_t)	0,                                 /* Reserved                     */                          
	(uint32_t)	OTG_FS_IRQHandler,                 /* USB OTG FS                   */                   
	(uint32_t)	DMA2_Stream5_IRQHandler,           /* DMA2 Stream 5                */                   
	(uint32_t)	DMA2_Stream6_IRQHandler,           /* DMA2 Stream 6                */                   
	(uint32_t)	DMA2_Stream7_IRQHandler,           /* DMA2 Stream 7                */                   
	(uint32_t)	USART6_IRQHandler,                 /* USART6                       */                    
	(uint32_t)	I2C3_EV_IRQHandler,                /* I2C3 event                   */                          
	(uint32_t)	I2C3_ER_IRQHandler,                /* I2C3 error                   */                          
	(uint32_t)	OTG_HS_EP1_OUT_IRQHandler,         /* USB OTG HS End Point 1 Out   */                   
	(uint32_t)	OTG_HS_EP1_IN_IRQHandler,          /* USB OTG HS End Point 1 In    */                   
	(uint32_t)	OTG_HS_WKUP_IRQHandler,            /* USB OTG HS Wakeup through EXTI */                         
	(uint32_t)	OTG_HS_IRQHandler,                 /* USB OTG HS                   */                   
	(uint32_t)	0,                                 /* Reserved                     */                   
	(uint32_t)	0,                                 /* Reserved                     */                   
	(uint32_t)	RNG_IRQHandler,                    /* RNG                          */
	(uint32_t)	FPU_IRQHandler,                    /* FPU                          */
	(uint32_t)	UART7_IRQHandler,                  /* UART7                        */      
	(uint32_t)	UART8_IRQHandler,                  /* UART8                        */
	(uint32_t)	SPI4_IRQHandler,                   /* SPI4                         */
	(uint32_t)	SPI5_IRQHandler,                   /* SPI5                         */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	SAI1_IRQHandler,                   /* SAI1                         */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	SAI2_IRQHandler,                   /* SAI2                         */
	(uint32_t)	QUADSPI_IRQHandler,                /* QUADSPI                      */
	(uint32_t)	LPTIM1_IRQHandler,                 /* LPTIM1                       */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	SDMMC2_IRQHandler,                 /* SDMMC2                       */

};

#elif defined(STM32F746xx)

void Reset_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void NMI_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));

/* External Interrupts */
void WWDG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* Window WatchDog              */
void PVD_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* PVD through EXTI Line detection */
void TAMP_STAMP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* Tamper and TimeStamps through the EXTI line */
void RTC_WKUP_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* RTC Wakeup through the EXTI line */
void FLASH_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* FLASH                        */
void RCC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* RCC                          */
void EXTI0_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* EXTI Line0                   */
void EXTI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* EXTI Line1                   */
void EXTI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* EXTI Line2                   */
void EXTI3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* EXTI Line3                   */
void EXTI4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* EXTI Line4                   */
void DMA1_Stream0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 0                */
void DMA1_Stream1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 1                */
void DMA1_Stream2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 2                */
void DMA1_Stream3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 3                */
void DMA1_Stream4_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 4                */
void DMA1_Stream5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 5                */
void DMA1_Stream6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream 6                */
void ADC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* ADC1, ADC2 and ADC3s         */
void CAN1_TX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN1 TX                      */
void CAN1_RX0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN1 RX0                     */
void CAN1_RX1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN1 RX1                     */
void CAN1_SCE_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN1 SCE                     */
void EXTI9_5_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* External Line[9:5]s          */
void TIM1_BRK_TIM9_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* TIM1 Break and TIM9          */
void TIM1_UP_TIM10_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* TIM1 Update and TIM10        */
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));	/* TIM1 Trigger and Commutation and TIM11 */
void TIM1_CC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* TIM1 Capture Compare         */
void TIM2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* TIM2                         */
void TIM3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* TIM3                         */
void TIM4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* TIM4                         */
void I2C1_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C1 Event                   */
void I2C1_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C1 Error                   */
void I2C2_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C2 Event                   */
void I2C2_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C2 Error                   */
void SPI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SPI1                         */
void SPI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SPI2                         */
void USART1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* USART1                       */
void USART2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* USART2                       */
void USART3_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* USART3                       */
void EXTI15_10_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* External Line[15:10]s        */
void RTC_Alarm_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* RTC Alarm (A and B) through EXTI Line */
void OTG_FS_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* USB OTG FS Wakeup through EXTI line */
void TIM8_BRK_TIM12_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));	/* TIM8 Break and TIM12         */
void TIM8_UP_TIM13_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* TIM8 Update and TIM13        */
void TIM8_TRG_COM_TIM14_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));	/* TIM8 Trigger and Commutation and TIM14 */
void TIM8_CC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* TIM8 Capture Compare         */
void DMA1_Stream7_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA1 Stream7                 */
void FMC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* FMC                          */
void SDMMC1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* SDMMC1                       */
void TIM5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* TIM5                         */
void SPI3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SPI3                         */
void UART4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* UART4                        */
void UART5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* UART5                        */
void TIM6_DAC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* TIM6 and DAC1&2 underrun errors */
void TIM7_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* TIM7                         */
void DMA2_Stream0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 0                */
void DMA2_Stream1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 1                */
void DMA2_Stream2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 2                */
void DMA2_Stream3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 3                */
void DMA2_Stream4_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 4                */
void ETH_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* Ethernet                     */
void ETH_WKUP_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* Ethernet Wakeup through EXTI line */
void CAN2_TX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN2 TX                      */
void CAN2_RX0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN2 RX0                     */
void CAN2_RX1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN2 RX1                     */
void CAN2_SCE_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* CAN2 SCE                     */
void OTG_FS_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* USB OTG FS                   */
void DMA2_Stream5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 5                */
void DMA2_Stream6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 6                */
void DMA2_Stream7_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* DMA2 Stream 7                */
void USART6_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* USART6                       */
void I2C3_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C3 event                   */
void I2C3_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C3 error                   */
void OTG_HS_EP1_OUT_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));	/* USB OTG HS End Point 1 Out   */
void OTG_HS_EP1_IN_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* USB OTG HS End Point 1 In    */
void OTG_HS_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));	/* USB OTG HS Wakeup through EXTI */
void OTG_HS_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* USB OTG HS                   */
void DCMI_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* DCMI                         */
void RNG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* Rng                          */
void FPU_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* FPU                          */
void UART7_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* UART7                        */
void UART8_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* UART8                        */
void SPI4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SPI4                         */
void SPI5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SPI5                           */
void SPI6_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SPI6                         */
void SAI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SAI1                          */
void LTDC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* LTDC                          */
void LTDC_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* LTDC error                      */
void DMA2D_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* DMA2D                          */
void SAI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* SAI2                         */
void QUADSPI_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* QUADSPI                      */
void LPTIM1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* LPTIM1                       */
void CEC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));	/* HDMI_CEC                     */
void I2C4_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C4 Event                   */
void I2C4_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* I2C4 Error                   */
void SPDIF_RX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));	/* SPDIF_RX                     */

__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
	(uint32_t)	RAM_END,
	(uint32_t)	Reset_Handler,
	(uint32_t)	NMI_Handler,
	(uint32_t)	HardFault_Handler,
	(uint32_t)	MemManage_Handler,
	(uint32_t)	BusFault_Handler,
	(uint32_t)	UsageFault_Handler,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	SVC_Handler,
	(uint32_t)	DebugMon_Handler,
	(uint32_t)	0,
	(uint32_t)	PendSV_Handler,
	(uint32_t)	SysTick_Handler,
	(uint32_t)	WWDG_IRQHandler,				/* Window WatchDog              */
	(uint32_t)	PVD_IRQHandler,					/* PVD through EXTI Line detection */
	(uint32_t)	TAMP_STAMP_IRQHandler,			/* Tamper and TimeStamps through the EXTI line */
	(uint32_t)	RTC_WKUP_IRQHandler,			/* RTC Wakeup through the EXTI line */
	(uint32_t)	FLASH_IRQHandler,				/* FLASH                        */
	(uint32_t)	RCC_IRQHandler,					/* RCC                          */
	(uint32_t)	EXTI0_IRQHandler,				/* EXTI Line0                   */
	(uint32_t)	EXTI1_IRQHandler,				/* EXTI Line1                   */
	(uint32_t)	EXTI2_IRQHandler,				/* EXTI Line2                   */
	(uint32_t)	EXTI3_IRQHandler,				/* EXTI Line3                   */
	(uint32_t)	EXTI4_IRQHandler,				/* EXTI Line4                   */
	(uint32_t)	DMA1_Stream0_IRQHandler,		/* DMA1 Stream 0                */
	(uint32_t)	DMA1_Stream1_IRQHandler,		/* DMA1 Stream 1                */
	(uint32_t)	DMA1_Stream2_IRQHandler,		/* DMA1 Stream 2                */
	(uint32_t)	DMA1_Stream3_IRQHandler,		/* DMA1 Stream 3                */
	(uint32_t)	DMA1_Stream4_IRQHandler,		/* DMA1 Stream 4                */
	(uint32_t)	DMA1_Stream5_IRQHandler,		/* DMA1 Stream 5                */
	(uint32_t)	DMA1_Stream6_IRQHandler,		/* DMA1 Stream 6                */
	(uint32_t)	ADC_IRQHandler,					/* ADC1, ADC2 and ADC3s         */
	(uint32_t)	CAN1_TX_IRQHandler,				/* CAN1 TX                      */
	(uint32_t)	CAN1_RX0_IRQHandler,			/* CAN1 RX0                     */
	(uint32_t)	CAN1_RX1_IRQHandler,			/* CAN1 RX1                     */
	(uint32_t)	CAN1_SCE_IRQHandler,			/* CAN1 SCE                     */
	(uint32_t)	EXTI9_5_IRQHandler,				/* External Line[9:5]s          */
	(uint32_t)	TIM1_BRK_TIM9_IRQHandler,		/* TIM1 Break and TIM9          */
	(uint32_t)	TIM1_UP_TIM10_IRQHandler,		/* TIM1 Update and TIM10        */
	(uint32_t)	TIM1_TRG_COM_TIM11_IRQHandler,	/* TIM1 Trigger and Commutation and TIM11 */
	(uint32_t)	TIM1_CC_IRQHandler,				/* TIM1 Capture Compare         */
	(uint32_t)	TIM2_IRQHandler,				/* TIM2                         */
	(uint32_t)	TIM3_IRQHandler,				/* TIM3                         */
	(uint32_t)	TIM4_IRQHandler,				/* TIM4                         */
	(uint32_t)	I2C1_EV_IRQHandler,				/* I2C1 Event                   */
	(uint32_t)	I2C1_ER_IRQHandler,				/* I2C1 Error                   */
	(uint32_t)	I2C2_EV_IRQHandler,				/* I2C2 Event                   */
	(uint32_t)	I2C2_ER_IRQHandler,				/* I2C2 Error                   */
	(uint32_t)	SPI1_IRQHandler,				/* SPI1                         */
	(uint32_t)	SPI2_IRQHandler,				/* SPI2                         */
	(uint32_t)	USART1_IRQHandler,				/* USART1                       */
	(uint32_t)	USART2_IRQHandler,				/* USART2                       */
	(uint32_t)	USART3_IRQHandler,				/* USART3                       */
	(uint32_t)	EXTI15_10_IRQHandler,			/* External Line[15:10]s        */
	(uint32_t)	RTC_Alarm_IRQHandler,			/* RTC Alarm (A and B) through EXTI Line */
	(uint32_t)	OTG_FS_WKUP_IRQHandler,			/* USB OTG FS Wakeup through EXTI line */
	(uint32_t)	TIM8_BRK_TIM12_IRQHandler,		/* TIM8 Break and TIM12         */
	(uint32_t)	TIM8_UP_TIM13_IRQHandler,		/* TIM8 Update and TIM13        */
	(uint32_t)	TIM8_TRG_COM_TIM14_IRQHandler,	/* TIM8 Trigger and Commutation and TIM14 */
	(uint32_t)	TIM8_CC_IRQHandler,				/* TIM8 Capture Compare         */
	(uint32_t)	DMA1_Stream7_IRQHandler,		/* DMA1 Stream7                 */
	(uint32_t)	FMC_IRQHandler,					/* FMC                          */
	(uint32_t)	SDMMC1_IRQHandler,				/* SDMMC1                       */
	(uint32_t)	TIM5_IRQHandler,				/* TIM5                         */
	(uint32_t)	SPI3_IRQHandler,				/* SPI3                         */
	(uint32_t)	UART4_IRQHandler,				/* UART4                        */
	(uint32_t)	UART5_IRQHandler,				/* UART5                        */
	(uint32_t)	TIM6_DAC_IRQHandler,			/* TIM6 and DAC1&2 underrun errors */
	(uint32_t)	TIM7_IRQHandler,				/* TIM7                         */
	(uint32_t)	DMA2_Stream0_IRQHandler,		/* DMA2 Stream 0                */
	(uint32_t)	DMA2_Stream1_IRQHandler,		/* DMA2 Stream 1                */
	(uint32_t)	DMA2_Stream2_IRQHandler,		/* DMA2 Stream 2                */
	(uint32_t)	DMA2_Stream3_IRQHandler,		/* DMA2 Stream 3                */
	(uint32_t)	DMA2_Stream4_IRQHandler,		/* DMA2 Stream 4                */
	(uint32_t)	ETH_IRQHandler,					/* Ethernet                     */
	(uint32_t)	ETH_WKUP_IRQHandler,			/* Ethernet Wakeup through EXTI line */
	(uint32_t)	CAN2_TX_IRQHandler,				/* CAN2 TX                      */
	(uint32_t)	CAN2_RX0_IRQHandler,			/* CAN2 RX0                     */
	(uint32_t)	CAN2_RX1_IRQHandler,			/* CAN2 RX1                     */
	(uint32_t)	CAN2_SCE_IRQHandler,			/* CAN2 SCE                     */
	(uint32_t)	OTG_FS_IRQHandler,				/* USB OTG FS                   */
	(uint32_t)	DMA2_Stream5_IRQHandler,		/* DMA2 Stream 5                */
	(uint32_t)	DMA2_Stream6_IRQHandler,		/* DMA2 Stream 6                */
	(uint32_t)	DMA2_Stream7_IRQHandler,		/* DMA2 Stream 7                */
	(uint32_t)	USART6_IRQHandler,				/* USART6                       */
	(uint32_t)	I2C3_EV_IRQHandler,				/* I2C3 event                   */
	(uint32_t)	I2C3_ER_IRQHandler,				/* I2C3 error                   */
	(uint32_t)	OTG_HS_EP1_OUT_IRQHandler,		/* USB OTG HS End Point 1 Out   */
	(uint32_t)	OTG_HS_EP1_IN_IRQHandler,		/* USB OTG HS End Point 1 In    */
	(uint32_t)	OTG_HS_WKUP_IRQHandler,			/* USB OTG HS Wakeup through EXTI */
	(uint32_t)	OTG_HS_IRQHandler,				/* USB OTG HS                   */
	(uint32_t)	DCMI_IRQHandler,				/* DCMI                         */
	(uint32_t)	0,								/* Reserved                     */
	(uint32_t)	RNG_IRQHandler,					/* Rng                          */
	(uint32_t)	FPU_IRQHandler,					/* FPU                          */
	(uint32_t)	UART7_IRQHandler,				/* UART7                        */
	(uint32_t)	UART8_IRQHandler,				/* UART8                        */
	(uint32_t)	SPI4_IRQHandler,				/* SPI4                         */
	(uint32_t)	SPI5_IRQHandler,				/* SPI5                         */
	(uint32_t)	SPI6_IRQHandler,				/* SPI6                         */
	(uint32_t)	SAI1_IRQHandler,				/* SAI1                         */
	(uint32_t)	LTDC_IRQHandler,				/* LTDC                         */
	(uint32_t)	LTDC_ER_IRQHandler,				/* LTDC error                   */
	(uint32_t)	DMA2D_IRQHandler,				/* DMA2D                        */
	(uint32_t)	SAI2_IRQHandler,				/* SAI2                         */
	(uint32_t)	QUADSPI_IRQHandler,				/* QUADSPI                      */
	(uint32_t)	LPTIM1_IRQHandler,				/* LPTIM1                       */
	(uint32_t)	CEC_IRQHandler,					/* HDMI_CEC                     */
	(uint32_t)	I2C4_EV_IRQHandler,				/* I2C4 Event                   */
	(uint32_t)	I2C4_ER_IRQHandler,				/* I2C4 Error                   */
	(uint32_t)	SPDIF_RX_IRQHandler,			/* SPDIF_RX                     */
};

#elif defined(STM32F767xx)

void Reset_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));
void NMI_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));				
void MemManage_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));				
void BusFault_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));				
void UsageFault_Handler(void)				__attribute__ ((weak, alias("Default_Handler")));				
void SVC_Handler(void)						__attribute__ ((weak, alias("Default_Handler")));				
void DebugMon_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));				
void PendSV_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));				
void SysTick_Handler(void)					__attribute__ ((weak, alias("Default_Handler")));				
void WWDG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* Window WatchDog              */
void PVD_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* PVD through EXTI Line detection */
void TAMP_STAMP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				             /* Tamper and TimeStamps through the EXTI line */
void RTC_WKUP_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* RTC Wakeup through the EXTI line */
void FLASH_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* FLASH                        */
void RCC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* RCC                          */
void EXTI0_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* EXTI Line0                   */
void EXTI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* EXTI Line1                   */
void EXTI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* EXTI Line2                   */
void EXTI3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* EXTI Line3                   */
void EXTI4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* EXTI Line4                   */
void DMA1_Stream0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 0                */
void DMA1_Stream1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 1                */
void DMA1_Stream2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 2                */
void DMA1_Stream3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 3                */
void DMA1_Stream4_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 4                */
void DMA1_Stream5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 5                */
void DMA1_Stream6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream 6                */
void ADC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* ADC1, ADC2 and ADC3s         */
void CAN1_TX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* CAN1 TX                      */
void CAN1_RX0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN1 RX0                     */
void CAN1_RX1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN1 RX1                     */
void CAN1_SCE_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN1 SCE                     */
void EXTI9_5_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* External Line[9:5]s          */
void TIM1_BRK_TIM9_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				          /* TIM1 Break and TIM9          */
void TIM1_UP_TIM10_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				          /* TIM1 Update and TIM10        */
void TIM1_TRG_COM_TIM11_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));				     /* TIM1 Trigger and Commutation and TIM11 */
void TIM1_CC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* TIM1 Capture Compare         */
void TIM2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* TIM2                         */
void TIM3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* TIM3                         */
void TIM4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* TIM4                         */
void I2C1_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C1 Event                   */
void I2C1_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C1 Error                   */
void I2C2_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C2 Event                   */
void I2C2_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C2 Error                   */
void SPI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SPI1                         */
void SPI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SPI2                         */
void USART1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* USART1                       */
void USART2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* USART2                       */
void USART3_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* USART3                       */
void EXTI15_10_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				              /* External Line[15:10]s        */
void RTC_Alarm_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				              /* RTC Alarm (A and B) through EXTI Line */
void OTG_FS_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				            /* USB OTG FS Wakeup through EXTI line */
void TIM8_BRK_TIM12_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));				         /* TIM8 Break and TIM12         */
void TIM8_UP_TIM13_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				          /* TIM8 Update and TIM13        */
void TIM8_TRG_COM_TIM14_IRQHandler(void)	__attribute__ ((weak, alias("Default_Handler")));				     /* TIM8 Trigger and Commutation and TIM14 */
void TIM8_CC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* TIM8 Capture Compare         */
void DMA1_Stream7_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA1 Stream7                 */
void FMC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* FMC                          */
void SDMMC1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* SDMMC1                       */
void TIM5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* TIM5                         */
void SPI3_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SPI3                         */
void UART4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* UART4                        */
void UART5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* UART5                        */
void TIM6_DAC_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* TIM6 and DAC1&2 underrun errors */
void TIM7_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* TIM7                         */
void DMA2_Stream0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 0                */
void DMA2_Stream1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 1                */
void DMA2_Stream2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 2                */
void DMA2_Stream3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 3                */
void DMA2_Stream4_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 4                */
void ETH_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* Ethernet                     */
void ETH_WKUP_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* Ethernet Wakeup through EXTI line */
void CAN2_TX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* CAN2 TX                      */
void CAN2_RX0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN2 RX0                     */
void CAN2_RX1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN2 RX1                     */
void CAN2_SCE_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN2 SCE                     */
void OTG_FS_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* USB OTG FS                   */
void DMA2_Stream5_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 5                */
void DMA2_Stream6_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 6                */
void DMA2_Stream7_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				           /* DMA2 Stream 7                */
void USART6_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* USART6                       */
void I2C3_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C3 event                   */
void I2C3_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C3 error                   */
void OTG_HS_EP1_OUT_IRQHandler(void)		__attribute__ ((weak, alias("Default_Handler")));				         /* USB OTG HS End Point 1 Out   */
void OTG_HS_EP1_IN_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				          /* USB OTG HS End Point 1 In    */
void OTG_HS_WKUP_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				            /* USB OTG HS Wakeup through EXTI */
void OTG_HS_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* USB OTG HS                   */
void DCMI_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* DCMI                         */
void RNG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* RNG                          */
void FPU_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* FPU                          */
void UART7_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* UART7                        */
void UART8_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* UART8                        */
void SPI4_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SPI4                         */
void SPI5_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SPI5                         */
void SPI6_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SPI6                         */
void SAI1_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SAI1                         */
void LTDC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* LTDC                         */
void LTDC_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* LTDC error                   */
void DMA2D_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* DMA2D                        */
void SAI2_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* SAI2                         */
void QUADSPI_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* QUADSPI                      */
void LPTIM1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* LPTIM1                       */
void CEC_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                    /* HDMI_CEC                     */
void I2C4_EV_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C4 Event                   */
void I2C4_ER_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* I2C4 Error                   */
void SPDIF_RX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* SPDIF_RX                     */
void DFSDM1_FLT0_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				            /* DFSDM1 Filter 0 global Interrupt */
void DFSDM1_FLT1_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				            /* DFSDM1 Filter 1 global Interrupt */
void DFSDM1_FLT2_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				            /* DFSDM1 Filter 2 global Interrupt */
void DFSDM1_FLT3_IRQHandler(void)			__attribute__ ((weak, alias("Default_Handler")));				            /* DFSDM1 Filter 3 global Interrupt */
void SDMMC2_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                 /* SDMMC2                       */
void CAN3_TX_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				                /* CAN3 TX                      */
void CAN3_RX0_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN3 RX0                     */
void CAN3_RX1_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN3 RX1                     */
void CAN3_SCE_IRQHandler(void)				__attribute__ ((weak, alias("Default_Handler")));				               /* CAN3 SCE                     */
void JPEG_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                   /* JPEG                         */
void MDIOS_IRQHandler(void)					__attribute__ ((weak, alias("Default_Handler")));				                  /* MDIOS                        */

__attribute__ ((section(".isr_vector")))
uint32_t vector_table[] = {
	(uint32_t)	RAM_END,
	(uint32_t)	Reset_Handler,
	(uint32_t)	NMI_Handler,
	(uint32_t)	HardFault_Handler,
	(uint32_t)	MemManage_Handler,
	(uint32_t)	BusFault_Handler,
	(uint32_t)	UsageFault_Handler,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	0,
	(uint32_t)	SVC_Handler,
	(uint32_t)	DebugMon_Handler,
	(uint32_t)	0,
	(uint32_t)	PendSV_Handler,
	(uint32_t)	SysTick_Handler,
	(uint32_t)	WWDG_IRQHandler,                   /* Window WatchDog              */
	(uint32_t)	PVD_IRQHandler,                    /* PVD through EXTI Line detection */
	(uint32_t)	TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */
	(uint32_t)	RTC_WKUP_IRQHandler,               /* RTC Wakeup through the EXTI line */
	(uint32_t)	FLASH_IRQHandler,                  /* FLASH                        */
	(uint32_t)	RCC_IRQHandler,                    /* RCC                          */
	(uint32_t)	EXTI0_IRQHandler,                  /* EXTI Line0                   */
	(uint32_t)	EXTI1_IRQHandler,                  /* EXTI Line1                   */
	(uint32_t)	EXTI2_IRQHandler,                  /* EXTI Line2                   */
	(uint32_t)	EXTI3_IRQHandler,                  /* EXTI Line3                   */
	(uint32_t)	EXTI4_IRQHandler,                  /* EXTI Line4                   */
	(uint32_t)	DMA1_Stream0_IRQHandler,           /* DMA1 Stream 0                */
	(uint32_t)	DMA1_Stream1_IRQHandler,           /* DMA1 Stream 1                */
	(uint32_t)	DMA1_Stream2_IRQHandler,           /* DMA1 Stream 2                */
	(uint32_t)	DMA1_Stream3_IRQHandler,           /* DMA1 Stream 3                */
	(uint32_t)	DMA1_Stream4_IRQHandler,           /* DMA1 Stream 4                */
	(uint32_t)	DMA1_Stream5_IRQHandler,           /* DMA1 Stream 5                */
	(uint32_t)	DMA1_Stream6_IRQHandler,           /* DMA1 Stream 6                */
	(uint32_t)	ADC_IRQHandler,                    /* ADC1, ADC2 and ADC3s         */
	(uint32_t)	CAN1_TX_IRQHandler,                /* CAN1 TX                      */
	(uint32_t)	CAN1_RX0_IRQHandler,               /* CAN1 RX0                     */
	(uint32_t)	CAN1_RX1_IRQHandler,               /* CAN1 RX1                     */
	(uint32_t)	CAN1_SCE_IRQHandler,               /* CAN1 SCE                     */
	(uint32_t)	EXTI9_5_IRQHandler,                /* External Line[9:5]s          */
	(uint32_t)	TIM1_BRK_TIM9_IRQHandler,          /* TIM1 Break and TIM9          */
	(uint32_t)	TIM1_UP_TIM10_IRQHandler,          /* TIM1 Update and TIM10        */
	(uint32_t)	TIM1_TRG_COM_TIM11_IRQHandler,     /* TIM1 Trigger and Commutation and TIM11 */
	(uint32_t)	TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */
	(uint32_t)	TIM2_IRQHandler,                   /* TIM2                         */
	(uint32_t)	TIM3_IRQHandler,                   /* TIM3                         */
	(uint32_t)	TIM4_IRQHandler,                   /* TIM4                         */
	(uint32_t)	I2C1_EV_IRQHandler,                /* I2C1 Event                   */
	(uint32_t)	I2C1_ER_IRQHandler,                /* I2C1 Error                   */
	(uint32_t)	I2C2_EV_IRQHandler,                /* I2C2 Event                   */
	(uint32_t)	I2C2_ER_IRQHandler,                /* I2C2 Error                   */
	(uint32_t)	SPI1_IRQHandler,                   /* SPI1                         */
	(uint32_t)	SPI2_IRQHandler,                   /* SPI2                         */
	(uint32_t)	USART1_IRQHandler,                 /* USART1                       */
	(uint32_t)	USART2_IRQHandler,                 /* USART2                       */
	(uint32_t)	USART3_IRQHandler,                 /* USART3                       */
	(uint32_t)	EXTI15_10_IRQHandler,              /* External Line[15:10]s        */
	(uint32_t)	RTC_Alarm_IRQHandler,              /* RTC Alarm (A and B) through EXTI Line */
	(uint32_t)	OTG_FS_WKUP_IRQHandler,            /* USB OTG FS Wakeup through EXTI line */
	(uint32_t)	TIM8_BRK_TIM12_IRQHandler,         /* TIM8 Break and TIM12         */
	(uint32_t)	TIM8_UP_TIM13_IRQHandler,          /* TIM8 Update and TIM13        */
	(uint32_t)	TIM8_TRG_COM_TIM14_IRQHandler,     /* TIM8 Trigger and Commutation and TIM14 */
	(uint32_t)	TIM8_CC_IRQHandler,                /* TIM8 Capture Compare         */
	(uint32_t)	DMA1_Stream7_IRQHandler,           /* DMA1 Stream7                 */
	(uint32_t)	FMC_IRQHandler,                    /* FMC                          */
	(uint32_t)	SDMMC1_IRQHandler,                 /* SDMMC1                       */
	(uint32_t)	TIM5_IRQHandler,                   /* TIM5                         */
	(uint32_t)	SPI3_IRQHandler,                   /* SPI3                         */
	(uint32_t)	UART4_IRQHandler,                  /* UART4                        */
	(uint32_t)	UART5_IRQHandler,                  /* UART5                        */
	(uint32_t)	TIM6_DAC_IRQHandler,               /* TIM6 and DAC1&2 underrun errors */
	(uint32_t)	TIM7_IRQHandler,                   /* TIM7                         */
	(uint32_t)	DMA2_Stream0_IRQHandler,           /* DMA2 Stream 0                */
	(uint32_t)	DMA2_Stream1_IRQHandler,           /* DMA2 Stream 1                */
	(uint32_t)	DMA2_Stream2_IRQHandler,           /* DMA2 Stream 2                */
	(uint32_t)	DMA2_Stream3_IRQHandler,           /* DMA2 Stream 3                */
	(uint32_t)	DMA2_Stream4_IRQHandler,           /* DMA2 Stream 4                */
	(uint32_t)	ETH_IRQHandler,                    /* Ethernet                     */
	(uint32_t)	ETH_WKUP_IRQHandler,               /* Ethernet Wakeup through EXTI line */
	(uint32_t)	CAN2_TX_IRQHandler,                /* CAN2 TX                      */
	(uint32_t)	CAN2_RX0_IRQHandler,               /* CAN2 RX0                     */
	(uint32_t)	CAN2_RX1_IRQHandler,               /* CAN2 RX1                     */
	(uint32_t)	CAN2_SCE_IRQHandler,               /* CAN2 SCE                     */
	(uint32_t)	OTG_FS_IRQHandler,                 /* USB OTG FS                   */
	(uint32_t)	DMA2_Stream5_IRQHandler,           /* DMA2 Stream 5                */
	(uint32_t)	DMA2_Stream6_IRQHandler,           /* DMA2 Stream 6                */
	(uint32_t)	DMA2_Stream7_IRQHandler,           /* DMA2 Stream 7                */
	(uint32_t)	USART6_IRQHandler,                 /* USART6                       */
	(uint32_t)	I2C3_EV_IRQHandler,                /* I2C3 event                   */
	(uint32_t)	I2C3_ER_IRQHandler,                /* I2C3 error                   */
	(uint32_t)	OTG_HS_EP1_OUT_IRQHandler,         /* USB OTG HS End Point 1 Out   */
	(uint32_t)	OTG_HS_EP1_IN_IRQHandler,          /* USB OTG HS End Point 1 In    */
	(uint32_t)	OTG_HS_WKUP_IRQHandler,            /* USB OTG HS Wakeup through EXTI */
	(uint32_t)	OTG_HS_IRQHandler,                 /* USB OTG HS                   */
	(uint32_t)	DCMI_IRQHandler,                   /* DCMI                         */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	RNG_IRQHandler,                    /* RNG                          */
	(uint32_t)	FPU_IRQHandler,                    /* FPU                          */
	(uint32_t)	UART7_IRQHandler,                  /* UART7                        */
	(uint32_t)	UART8_IRQHandler,                  /* UART8                        */
	(uint32_t)	SPI4_IRQHandler,                   /* SPI4                         */
	(uint32_t)	SPI5_IRQHandler,                   /* SPI5                         */
	(uint32_t)	SPI6_IRQHandler,                   /* SPI6                         */
	(uint32_t)	SAI1_IRQHandler,                   /* SAI1                         */
	(uint32_t)	LTDC_IRQHandler,                   /* LTDC                         */
	(uint32_t)	LTDC_ER_IRQHandler,                /* LTDC error                   */
	(uint32_t)	DMA2D_IRQHandler,                  /* DMA2D                        */
	(uint32_t)	SAI2_IRQHandler,                   /* SAI2                         */
	(uint32_t)	QUADSPI_IRQHandler,                /* QUADSPI                      */
	(uint32_t)	LPTIM1_IRQHandler,                 /* LPTIM1                       */
	(uint32_t)	CEC_IRQHandler,                    /* HDMI_CEC                     */
	(uint32_t)	I2C4_EV_IRQHandler,                /* I2C4 Event                   */
	(uint32_t)	I2C4_ER_IRQHandler,                /* I2C4 Error                   */
	(uint32_t)	SPDIF_RX_IRQHandler,               /* SPDIF_RX                     */
	(uint32_t)	0,                                 /* Reserved                     */
	(uint32_t)	DFSDM1_FLT0_IRQHandler,            /* DFSDM1 Filter 0 global Interrupt */
	(uint32_t)	DFSDM1_FLT1_IRQHandler,            /* DFSDM1 Filter 1 global Interrupt */
	(uint32_t)	DFSDM1_FLT2_IRQHandler,            /* DFSDM1 Filter 2 global Interrupt */
	(uint32_t)	DFSDM1_FLT3_IRQHandler,            /* DFSDM1 Filter 3 global Interrupt */
	(uint32_t)	SDMMC2_IRQHandler,                 /* SDMMC2                       */
	(uint32_t)	CAN3_TX_IRQHandler,                /* CAN3 TX                      */
	(uint32_t)	CAN3_RX0_IRQHandler,               /* CAN3 RX0                     */
	(uint32_t)	CAN3_RX1_IRQHandler,               /* CAN3 RX1                     */
	(uint32_t)	CAN3_SCE_IRQHandler,               /* CAN3 SCE                     */
	(uint32_t)	JPEG_IRQHandler,                   /* JPEG                         */
	(uint32_t)	MDIOS_IRQHandler,                  /* MDIOS                        */
};
#else
#error "No interrupt vector for chip!"
#endif