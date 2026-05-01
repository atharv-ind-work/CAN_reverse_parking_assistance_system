// header.h
#include<lpc21xx.h>

typedef unsigned int u32;

typedef signed int s32;

typedef unsigned short int u16;

typedef signed short int s16;

typedef unsigned char u8;

typedef signed char s8;

//delay functions
extern void delay_sec(u32 sec);
extern void delay_ms(u32 ms);
extern void delay_us(u32 us);

//can variables
typedef struct CAN1_MSG
{

	u32 id;

	u32 byteA;

	u8 rtr;

	u8 dlc;

  u8 ff;	

}CAN1;


//CAN functions
extern void can1_tx(CAN1 v);
extern void can1_init(void);
extern void can1_rx(CAN1 *ptr);

//buxzzer pin
#define BUZZER_PIN (1<<21)

//timer interrupt
extern void update_buzzer(int distance);
extern void timer1_init(void);
extern void config_eint0(void);
//-------------------------------------------------------------
extern void config_vic_for_eint0(void);

extern void config_eint(void);

extern void config_vic_for_eint1(void);

extern void config_vic_for_uart0(void);


extern void config_timer1_intr(void);

extern void config_vic_for_timer1(void);

extern void uart_integer(int num);
extern void uart_float(double num);

extern void uart_tx_str(char *ptr);

extern unsigned char uart_rx(void);

extern void uart_tx(unsigned char data);

extern void uart_init(unsigned int baud);

extern void config_vic_for_uart0(void);





