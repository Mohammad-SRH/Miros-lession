#ifndef __MIROS_HEDER_
#define __MIROS_HEDER_

#include "stm32f10x.h"

/*Thread Control Block (TCB) */
typedef struct {
		void *sp; //Stack Pointer
}OSThread;

typedef void(*OSThreadHandler)();

void OSThread_start(
			OSThread *me,
			OSThreadHandler treadHandler,
			void *stcsto,uint32_t stcSize);

void OS_init (void);

void OS_sched (void);

void OS_run (void);

void OS_onStartup (void);

#endif