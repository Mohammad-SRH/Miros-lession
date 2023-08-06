 #ifndef __BSP_HEADER_
 #define __BSP_HEADER_
 #include <stdint.h>
 
 #define BSP_TICKS_PER_SEC    100U
 
	void SysTick_Handler (void);
	uint32_t BSP_tickctr (void);
	void bsp_init (void);
	void LED1_ON (void);
	void LED1_OFF (void);
	void LED2_ON (void);
	void LED2_OFF (void);
	void LED3_ON (void);
	void LED3_OFF (void);
	void BSP_Delay (uint32_t prescale);
	
 
 
 #endif