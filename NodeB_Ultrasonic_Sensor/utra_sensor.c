#include"header.h"

unsigned int dis(void)
{
	unsigned int t,timeout=100000;
	T1PR=60-1;
	T1TC=T1PC=0;
	T1TCR=0x02;
	IOCLR0=1<<11;
	delay_us(2);
	IOSET0=1<<11;
	delay_us(10);  
	IOCLR0=1<<11;
	while(!(IOPIN0&1<<10)&&timeout--);
	if(timeout==0)
	return 999;
	T1TCR=0x01;
	timeout=100000;
	while((IOPIN0&1<<10)&&timeout--);
	T1TCR=0;
	t=T1TC;
	return (t*0.0343)/2;
}
