 #ifndef __BSP_HEADER_
 #define __BSP_HEADER_
 #include <stdint.h>
 
 #define BSP_TICKS_PER_SEC    100U
 #define LED1									GPIO_ODR_ODR12
 #define LED2									GPIO_ODR_ODR13
 #define LED3									GPIO_ODR_ODR14
 
	void SysTick_Handler (void);
	void bsp_init (void);
	void LED1_ON (void);
	void LED1_OFF (void);
	void LED2_ON (void);
	void LED2_OFF (void);
	void LED3_ON (void);
	void LED3_OFF (void);

	
 
 
 #endif