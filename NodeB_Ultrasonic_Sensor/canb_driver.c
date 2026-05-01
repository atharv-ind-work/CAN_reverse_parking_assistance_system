/*can1_driver.c in nodeB*/

#include <LPC21xx.H>
#include "header.h"

#define TCS ((C1GSR>>3)&1)
void can1_init(void)
{
	VPBDIV=1;//PCLK=60MHz
	PINSEL1|=0x00040000;//P0.25->RD1
	C1MOD=1;//reset mode
	C1BTR=0x001C001D;//125KBps baud
	//AFMR=2;//accept all incoming msgs
		AFMR = 0x01;  // Disable filter (reset mode)

   
    SFF_sa = 0x00;//starting address
    SFF_GRP_sa = 0x04;
    EFF_sa = 0x04;
    EFF_GRP_sa = 0x04;
    ENDofTable = 0x04;//ending address

    
    *((volatile unsigned int *)0xE0038000) = (0x6AB << 5);// Standard ID entry (11-bit ID)

    AFMR = 0x00;            // Enable filtering

    C1IER = 0x01;           // Enable RX interrupt
		C1MOD=0;//release reset mode
}

#define RBS (C1GSR&1)
void can1_rx(CAN1 *ptr)
{
	while(RBS==0);//waiting for CAN msg to receive
	ptr->id=C1RID;//get id
	ptr->rtr=(C1RFS>>30)&1;//extract RTR
	ptr->dlc=(C1RFS>>16)&0xF;//extract DLC
	ptr->ff=(C1RFS>>31)&1;//extract ff
	if(ptr->rtr==0){//if data-frame
		ptr->byteA=C1RDA;//lower 4bytes data
	}
	C1CMR=0x4;//release rxbuf***	
}

void can1_tx(CAN1 v){

	C1TID1=v.id;

	C1TFI1=(v.dlc<<16);//Set DLC, RTR=0, FF=0

	if(v.rtr==0){

		C1TDA1=v.byteA;
	}
	else
		C1TFI1|=(1<<30);//RTR=1

	C1CMR=0x21;//Select Txbuf1 & Start Xmission

	while(TCS==0);
}




