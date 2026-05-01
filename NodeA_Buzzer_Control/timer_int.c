#include "header.h"

volatile u32 counter=0;
volatile u32 threshold=1000;
volatile u32 buzzer_state=0;
volatile u32 continue1=0;
extern u32 flag;
volatile u32 toggle_flag=0;

void timer1_handler(void) __irq
{
	T1IR=1;
	counter++;
	toggle_flag++;
	if(flag==0)
	{
		IOSET0=BUZZER_PIN;
		counter=0;
	}
	else if(continue1==1)
	{
		IOCLR0=BUZZER_PIN;
	}
	else
	{
		if(counter>threshold)
		{
			buzzer_state=!buzzer_state;

			if(buzzer_state)
			IOCLR0=BUZZER_PIN;
			else
			IOSET0=BUZZER_PIN;

			counter=0;
		}
	}
	VICVectAddr=0;
}

void timer1_init(void)
{
	s32 arrt[]={15,60,30,15,15};
	u32 pclk1=arrt[VPBDIV%4]*1000;
	T1PC=0;
	T1PR=pclk1;
	T1MR0=1; //MATCH EVERY 1TICK---1TICK AFTER EVERY 1ms
	T1MCR=3; 
	VICVectAddr5=(u32)timer1_handler;	//PASSING ADDRESS OF TIMER-INTR
	VICVectCntl5=5|(1<<5);	// ENABLE SLOT 5 FOR TIMER
	VICIntEnable|=(1<<5); //ENABLE TIMER INTERRUPT
	T1TCR=1;//START TIMER
}

void update_buzzer(int distance)
{
	if(flag==1)
	{
		if(distance>400)
		{
			threshold=1000;
			continue1=0;
			IOCLR0=BUZZER_PIN;
		}
		else if(distance>300)
		{
			threshold=800;
			continue1=0;
		}
		else if(distance>200)
		{
			threshold=400;
			continue1=0;
		}
		else if(distance>50)
		{
			threshold=150;
			continue1=0;
		}
		else
		{
			continue1=1;
		}
	}	
}

