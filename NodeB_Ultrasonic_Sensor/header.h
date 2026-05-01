// header.h
 #include<lpc21xx.h>

typedef unsigned int u32;

typedef signed int s32;

typedef unsigned short int u16;

typedef signed short int s16;

typedef unsigned char u8;

typedef signed char s8;


extern void delay_sec(unsigned int  sec);

extern void delay_ms(unsigned int ms);




extern void lcd_data(unsigned char data);

extern void lcd_cmd(unsigned char cmd);

extern void lcd_init(void);

extern void lcd_string(char *ptr);





extern void config_eint0(void);

extern void config_vic_for_eint0(void);

extern void config_eint(void);

extern void config_vic_for_eint1(void);

extern void config_vic_for_uart0(void);


extern void config_timer1_intr(void);

extern void config_vic_for_timer1(void);

extern void uart_integer(int num);

extern void uart_tx_str(char *ptr);

extern unsigned char uart_rx(void);

extern void uart0_tx(unsigned char data);

extern void uart_init(unsigned int baud);

extern void uart0_float(float n);


extern u16 mcp3204_adc_read(u8 ch_num);

extern u8 spi0(u8 data);

extern void spi0_init(void);


extern void config_vic_for_uart0(void);


extern void i2c_init(void);

extern void i2c_send(u8 sa, u8 mr, u8 data);

extern u8 i2c_receive(u8 sa, u8 mr);


typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u8 rtr;

	u8 dlc;

  u8 ff;	

}CAN1;


extern void can1_tx(CAN1 v);

extern void can1_init(void);

extern void can1_rx(CAN1 *ptr);

extern void config_vic_for_rx_can1(void);
extern unsigned int dis(void);
extern void delay_us(u32 us);



