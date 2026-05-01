#include"header.h"

extern int flag;
extern volatile unsigned long GLO_ID;
extern volatile u32 GLO_DLC;


void can1_rx_handler(void) __irq
{
	u32 fr_info=C1RFS; //receiver buffer

	if(fr_info & (1<<30))
	{
		GLO_ID = C1RID;	   // extracting IDENTIFIER
		GLO_DLC = (fr_info >> 16) & 0x0F; // extracting DLC value
		flag=1;
	}
	C1CMR=(1<<2); //RBR-release the buffer
	VICVectAddr=0;
} 

void config_vic_for_rx_can1(void)
{
	VICIntSelect=0;
	VICVectCntl0=26|(1<<5);
	VICVectAddr0=(u32)can1_rx_handler;
	VICIntEnable=1<<26;
}

