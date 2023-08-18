#include <stdint.h>
#include "Miros.h"


OSThread * volatile OS_curr;	/* pointer to the current thread */
OSThread * volatile OS_next;	/*pointer to the next thread */

void OS_init (void){
	*(uint32_t volatile*)0xE000ED20 |= (0xFFU << 16);
}

void OS_sched(void){
	
	extern OSThread blinky1;
	extern OSThread blinky2;
	
	if(OS_curr == &blinky1){
		OS_next = &blinky2;
	}
	else{
		OS_next = &blinky1;
	}
	
	if (OS_next != OS_curr){
		*(uint32_t volatile *)0xE000ED04 = (1U << 28); //PENDSVSET
	}
}

void OSThread_start(
			OSThread *me,
			OSThreadHandler treadHandler,
			void *stcsto,uint32_t stcSize)
{
		uint32_t *sp = (uint32_t *)((((uint32_t)stcsto + stcSize) / 8)*8);
		uint32_t *stk_limit;
	
		*(--sp) = (1U<<24); // xPSR->Thumb 
		*(--sp) = (uint32_t)treadHandler; //PC
		*(--sp) = 0x0000000EU; // LR
		*(--sp) = 0x0000000CU; // R12
		*(--sp) = 0x00000003U; // R3
		*(--sp) = 0x00000002U; // R2
		*(--sp) = 0x00000001U; // R1
		*(--sp) = 0x00000000U; // R0
		//Faek Registers Blinky1
		*(--sp) = 0x0000000BU; // R11
		*(--sp) = 0x0000000AU; // R10
		*(--sp) = 0x00000009U; // R9
		*(--sp) = 0x00000008U; // R8
		*(--sp) = 0x00000007U; // R7
		*(--sp) = 0x00000006U; // R6
		*(--sp) = 0x00000005U; // R5
		*(--sp) = 0x00000004U; // R4
		
		/* save the top of the stack in the thread's */ 
		me->sp = sp;
		
		/* Round up the bottom of the stack to the 8-byte boundary */
		stk_limit = (uint32_t *)(((((uint32_t)stcsto - 1U) / 8) + 1U) * 8);
		
		/* pre-fill the unsed satck frame with 0xDEEDBEEF */
		for(sp = sp - 1U;sp >= stk_limit; --sp){
			*sp = 0xDEEDBEEFU;
		}
				
}


//void PendSV_Handler (void){
//	
//	void *sp;
//	
//	__disable_irq();
//	if (OS_curr != (OSThread *)0){		
//		//push registers
//		OS_curr->sp = sp;
//		
//	}
//	
//	sp = OS_next->sp;
//	OS_curr = OS_next;
//	
//	//pop registers
//	__enable_irq();
//}

void PendSV_Handler (void){
	
	__asm(
			//Disable Interupts
			"CPSID		I\n"
			
			//if (OS_curr != (OSThread *)0( {
			"LDR			r0,=OS_curr\n"
			"LDR      r0,[r0,#0x00]\n"
			"CBZ      r0,PendSV_restore\n"

			//Push r4 to r11 register
			"PUSH			{r4-r11}\n"
	
			//OS_curr->sp = sp;
//			"LDR      r0,[sp,#0x00]\n"
//			"LDR			r1,=OS_curr\n"
			"LDR      r1,[r0,#0x00]\n"
//			"LDR			sp,[r1,#0x00]\n"
			"STR      r0,[r1,#0x00]\n"
	
	
			"PendSV_restore:\n"
			//sp = OS_next->sp; 
			"LDR			r0,=OS_next\n"
			"LDR      r1,[r0,#0x00]\n"
//			"LDR      r1,[r1,#0x00]\n"
			"LDR      sp,[r1,#0x00]\n"
			
			
			//OS_curr = OS_next
			"LDR      r0,[r0,#0x00]\n"
//			"LDR      r0,=OS_next\n"
			"LDR			r1,=OS_curr\n"
			"STR      r0,[r1,#0x00]\n"

			//POP Registers r4 to r11
			"POP			{r4-r11}\n"
			"CPSID		I\n"
//			"ADD      sp,sp,#0x04\n"
//			"BX				lr\n"

	);
	
}


