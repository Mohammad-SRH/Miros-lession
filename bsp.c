#include "bsp.h"
#include "stm32f10x.h"
#include "Miros.h"


static uint32_t volatile tick = 0;

void bsp_init (void){
	
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;
	GPIOB->CRH 	= (0<<18U) | (0<<22U) | (0<<26U);
	GPIOB->CRH |= (1<<17U) | (1<<21U) | (1<<25U);
	
}

void SysTick_Handler (void){

	++tick;	
	__disable_irq();
	OS_sched();
	__enable_irq();

}

uint32_t BSP_tickctr (void){
	
	uint32_t tickctr;
	__disable_irq();
	tickctr = tick;
	__enable_irq();
	
	return tickctr;
	
}

void BSP_Delay (uint32_t prescale){
	
	uint32_t start;
	start = BSP_tickctr();
	while((BSP_tickctr()-start) < prescale);

}


void LED1_ON (void){
	GPIOB->ODR |= LED1;
}

void LED1_OFF (void){
	GPIOB->ODR &= ~LED1;
}

void LED2_ON (void){
	GPIOB->ODR |= LED2;
}

void LED2_OFF (void){
	GPIOB->ODR &= ~LED2;
}

void LED3_ON (void){
	GPIOB->ODR |= LED3;
}

void LED3_OFF (void){
	GPIOB->ODR &= ~LED3;
}

void OS_onStartup (void){
	
	SysTick->CTRL |= (1<<0U) | (1<<1U) |(1<<2U);
	SysTick->LOAD = (HSE_VALUE/100);	//HSE Value is 8000000->LOAD=80'000
	SystemCoreClockUpdate();
	SystemInit();
	NVIC_SetPriority(SysTick_IRQn,0); 	
	
}


void Q_onAssert(char const *module,int loc){
	
	(void)module;
	(void)loc;
	NVIC_SystemReset();
}





