/*main_nodeA.c*/

#include "header.h"
#define LED (1<<18)  //led pin
volatile int flag=0;	//reverse gear flag
volatile int val=0; //distance variable
u32 sensor_check=0;
CAN1 v2,r1;  //can  variables
int main()
{
	config_vic_for_eint0();
	IODIR0|=LED;
	IOSET0=LED;	//LED-OFF
	IODIR0|=BUZZER_PIN;
	IOSET0=BUZZER_PIN; //BUZZER-OFF
	can1_init();
	uart_init(9600);
	uart_tx_str("can and uart initi\r\n");
	timer1_init();
	while(1)
   	{
			if(flag==1)
			{          
				IOCLR0=LED;
				v2.id=0x6AB;
				v2.rtr=1;//remote-frame
				v2.dlc=4;
				can1_tx(v2);//send remote-frame
				
				can1_rx(&r1);//waiting for data frame
				val=r1.byteA;
					
					if(val==999)   //echo not working
					{
						uart_tx_str("Danger:sensor is not working\r\n");
						sensor_check++;
					}
					else
					{
						sensor_check=0;		
					}
				uart_tx_str("Distance : ");	
				uart_integer(val); 	
				uart_tx_str(" cm\r\n");
				if(sensor_check>=3)
				{
						IOSET0=BUZZER_PIN;//if sensor send invalid data for continues 3 times then turn off the buzzer					
				}
				else
				{
							update_buzzer(val); //valid data update the buzzer-frequency
				}
			}
			else
			{
				IOSET0=LED;	
				IOSET0=BUZZER_PIN;
			}    
		}
}
