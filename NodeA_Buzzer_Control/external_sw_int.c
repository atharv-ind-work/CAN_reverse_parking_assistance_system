#include"header.h"

extern u32 flag;
extern volatile u32 toggle_flag;
volatile u32 last_intr=0;

void eint0_handler(void) __irq
{
	if((toggle_flag-last_intr)>=200)//avoiding the key-debouncing error
	{
		flag^=1;
		last_intr=toggle_flag;
	}
	EXTINT=1;
	VICVectAddr=0;
}

void config_vic_for_eint0(void)
{
	PINSEL1|=1;
	EXTMODE=1; //edge triggering
	EXTPOLAR=0; //falling edge
	VICIntSelect=0;
	VICVectCntl0=14|(1<<5);
	VICVectAddr0=(u32)eint0_handler;
	VICIntEnable=1<<14;
}
