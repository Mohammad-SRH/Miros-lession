#include "stm32f10x.h"
#include "bsp.h"
#include "Miros.h"


uint32_t stack_blinky1[40];
OSThread blinky1;

void main_blinky1 (void){
		
	while(1){
	
		LED1_ON();
		BSP_Delay(BSP_TICKS_PER_SEC/4);
		LED1_OFF();
		BSP_Delay((BSP_TICKS_PER_SEC*3)/4);
	}
	
}

uint32_t stack_blinky2[40];
OSThread blinky2;

void main_blinky2 (void){
	
	while(1){
	
		LED2_ON();
		BSP_Delay(BSP_TICKS_PER_SEC/2);
		LED2_OFF();
		BSP_Delay(BSP_TICKS_PER_SEC/3);
	}
		
}


int main (void){
		
	bsp_init();
	OS_init();
	
	
	OSThread_start(&blinky1,
									&main_blinky1,
									stack_blinky1,sizeof(stack_blinky1));
	
	OSThread_start(&blinky2,
									&main_blinky2,
									stack_blinky2,sizeof(stack_blinky2));
	
		while(1){
			
		}
	
		
	
//		return 0;
	
}

