#include "header.h"
void delay_ms(u32 ms) //mili second delay
{
	T0PC=T0TC=0;
	T0PR=60000-1;
	T0TCR=1;
	while(T0TC<ms);
	T0TCR=0;
}

void delay_sec(u32 sec)  //second delay
{
	T0PC=T0TC=0;
	T0PR=60000000-1;
	T0TCR=1;
	while(T0TC<sec);
	T0TCR=0;
}

void delay_us(u32 us)	 //micro second delay
{
T0PR=60-1;
T0TC=T0PC=0;
T0TCR=1;
while(T0TC<us);
T0TCR=0;
}
