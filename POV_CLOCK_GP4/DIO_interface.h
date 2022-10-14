/****************GUARD MY FILE********************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/****************PORTS DEFINITIONS****************/
#define	PORTA	0
#define	PORTB	1
#define	PORTC	2
#define	PORTD	3	

/***************PINS DEFINITIONS******************/
#define	PIN0	0
#define	PIN1	1
#define	PIN2	2
#define	PIN3	3	
#define	PIN4	4
#define	PIN5	5
#define	PIN6	6
#define	PIN7	7

/****************DIRECTION DEFINITIONS*************/
#define	PORT_OUT	0xff
#define	PORT_IN		0x00 
#define	OUT			1
#define	IN			0 

/****************VALUES DEFINITIONS****************/
#define HIGH 1
#define LOW	0


/****************PIN FUNCTIONS *********************/

void  DIO_voidSetpinValue(u8 u8_port_copy , u8 u8_pin_copy , u8 u8_value_copy);
void  DIO_voidSetpinDirection(u8 u8_port_copy , u8 u8_pin_copy , u8 u8_direction_copy);
u8    DIO_u8GetpinValue(u8 u8_port_copy , u8 u8_pin_copy );

/***************PORT FUNCTIONS ************************/

void DIO_voidSetportDirection(u8 u8_port_copy , u8 u8_direction_copy);
void DIO_voidSetportValue(u8 u8_port_copy , u8 u8_value_copy);

#endif