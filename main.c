#include "stm32f10x.h"
#include "stdio.h"
#include "bsp.h"


void main_blinky1 (void){
		
	while(1){
	
		LED1_ON();
		BSP_Delay(BSP_TICKS_PER_SEC/4);
		LED1_OFF();
		BSP_Delay((BSP_TICKS_PER_SEC*3)/4);
	}
	
}

void main_blinky2 (void){
	
	while(1){
	
		LED2_ON();
		BSP_Delay(BSP_TICKS_PER_SEC/4);
		LED2_OFF();
		BSP_Delay((BSP_TICKS_PER_SEC*3)/4);
	}
		
}


int main (void){
		
	uint8_t volatile run =0;
	bsp_init();
	
	while(1){
			if(run){
					main_blinky1();
			}
			else{
					main_blinky2();
			}
		

	}
		
	
//		return 0;
	
}

