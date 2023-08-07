#ifndef __MIROS_HEDER_
#define __MIROS_HEDER_

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

void OS_sched(void);


#endif