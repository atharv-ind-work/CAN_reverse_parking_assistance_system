#include "header.h"

void uart_init(u32 baud)
{
	int pclk,result=0;
	int arr[]={15,60,30};
	pclk=arr[VPBDIV]*1000000;
	result=pclk/(16*baud);	
	PINSEL0|=0X05;
	U0LCR=0X83;
	U0DLL=result&0xff;
	U0DLM=(result>>8)&0xff;
	U0LCR=0X03;
}

#define THRE ((U0LSR>>5)&1)
void uart_tx(u8 data)
{
	U0THR=data;
	while(THRE==0);	
}

#define RDR (U0LSR&1)
u8 uart_rx(void)
{
	 while(RDR==0);
	 return U0RBR;
}



void uart_tx_str(char *str)
{
	while(*str!=0)
	{
		uart_tx(*str++);
	}
}



void uart_float(double num)
{
	int arr[10],i=0,mul=1000000;
	long long int temp=0;
	if(num==0)
	{
		uart_tx_str("0.000000");
		return;
	}
	if(num<0)
	{
		uart_tx('-');
		num=-num;
	}
	if(num>0&&num<1)
	{
		uart_tx_str("0.");
	}
	if(num>0)
	{
		temp=num*mul;
		while(temp)
		{
			arr[i++]=temp%10+48;
			temp/=10;
		}
		for(i=i-1;i>=0;i--)
		{
			uart_tx(arr[i]);
			if(i==6)
			uart_tx('.');
		}
	}
}



void uart_integer(int num)
{
	int arr[10],i=0;

	if(num==0)
	{
		uart_tx('0');
		return;
	}
	if(num<0)
	{
		uart_tx('-');
		num=-num;
	}

		while(num)
		{
			arr[i++]=num%10+48;
			num/=10;
		}
		for(i=i-1;i>=0;i--)
		{
			uart_tx(arr[i]);
		}
}
