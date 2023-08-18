#ifndef __MIROS_HEDER_
#define __MIROS_HEDER_

#include "stm32f10x.h"

/*Thread Control Block (TCB) */
typedef struct {
		void *sp; //Stack Pointer
		uint32_t	timeout;
}OSThread;

typedef void(*OSThreadHandler)();

void OSThread_start(
			OSThread *me,
			OSThreadHandler treadHandler,
			void *stcsto,uint32_t stcSize);

void OS_init (void *stcsto,uint32_t stcSize);

void OS_sched (void);

void OS_run (void);

void OS_onStartup (void);

void OS_onIdle (void);

void OS_Delay (uint32_t ticks);

void OS_tick (void);

#endif