#include "header.h"

volatile u32 flag=0;
volatile unsigned long GLO_ID;
volatile u32 GLO_DLC;
volatile u32 curr_dist;

CAN1 r1,tx;

int main()
{
	curr_dist=0;
	config_vic_for_rx_can1();
	can1_init();
	uart_init(9600);
	IODIR0=(1<<11);
	//uart_tx_str("CAN1 & UART0 Initialized\r\n");
	while(1)
	{
		if(flag==1)
		{
			curr_dist=dis();  //caluculating distance function
			tx.id=GLO_ID;
			tx.dlc=GLO_DLC;
			tx.rtr=0; //data frame
			tx.ff=0;
			
			tx.byteA = curr_dist;     
			can1_tx(tx);
			flag=0;
		}
	}	 
} 
