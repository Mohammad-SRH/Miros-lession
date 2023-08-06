#include "stm32f10x.h"
#include "stdio.h"
#include "bsp.h"


uint32_t stack_blinky1[40];
uint32_t *sp_blinky1 = &stack_blinky1[40];

void main_blinky1 (void){
		
	while(1){
	
		LED1_ON();
		BSP_Delay(BSP_TICKS_PER_SEC/4);
		LED1_OFF();
		BSP_Delay((BSP_TICKS_PER_SEC*3)/4);
	}
	
}

uint32_t stack_blinky2[40];
uint32_t *sp_blinky2 = &stack_blinky2[40];

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
	
	
	*(--sp_blinky1) = (1U<<24); // xPSR->Thumb 
	*(--sp_blinky1) = (uint32_t)&main_blinky1; //PC
	*(--sp_blinky1) = 0x0000000EU; // LR
	*(--sp_blinky1) = 0x0000000CU; // R12
	*(--sp_blinky1) = 0x00000003U; // R3
	*(--sp_blinky1) = 0x00000002U; // R2
	*(--sp_blinky1) = 0x00000001U; // R1
	*(--sp_blinky1) = 0x00000000U; // R0
	//Faek Registers Blinky1
	*(--sp_blinky1) = 0x0000000BU; // R11
	*(--sp_blinky1) = 0x0000000AU; // R10
	*(--sp_blinky1) = 0x00000009U; // R9
	*(--sp_blinky1) = 0x00000008U; // R8
	*(--sp_blinky1) = 0x00000007U; // R7
	*(--sp_blinky1) = 0x00000006U; // R6
	*(--sp_blinky1) = 0x00000005U; // R5
	*(--sp_blinky1) = 0x00000004U; // R4
	
	
	
	*(--sp_blinky2) = (1U<<24); // xPSR->Thumb 
	*(--sp_blinky2) = (uint32_t)&main_blinky2; //PC
	*(--sp_blinky2) = 0x0000000EU; // LR
	*(--sp_blinky2) = 0x0000000CU; // R12
	*(--sp_blinky2) = 0x00000003U; // R3
	*(--sp_blinky2) = 0x00000002U; // R2
	*(--sp_blinky2) = 0x00000001U; // R1
	*(--sp_blinky2) = 0x00000000U; // R0
		//Faek Registers Blinky1
	*(--sp_blinky2) = 0x0000000BU; // R11
	*(--sp_blinky2) = 0x0000000AU; // R10
	*(--sp_blinky2) = 0x00000009U; // R9
	*(--sp_blinky2) = 0x00000008U; // R8
	*(--sp_blinky2) = 0x00000007U; // R7
	*(--sp_blinky2) = 0x00000006U; // R6
	*(--sp_blinky2) = 0x00000005U; // R5
	*(--sp_blinky2) = 0x00000004U; // R4
	
		while(1){
			
		}
	
		
	
//		return 0;
	
}

