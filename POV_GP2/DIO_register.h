
/*************** GUARD TO PROTECT MY FILE *************/
#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

/***************PORTA REGITERS*****************/
#define		PORTA_REG 		*((volatile u8*)0X3B)
#define		DDRA_REG 		*((volatile u8*)0X3A)
#define		PINA_REG 		*((volatile u8*)0X39)

/*******************PORTB REGITERS*************/
#define		PORTB_REG 		*((volatile u8*)0X38)
#define		DDRB_REG 		*((volatile u8*)0X37)
#define		PINB_REG 		*((volatile u8*)0X36)

/****************PORTC REGITERS****************/
#define		PORTC_REG 		*((volatile u8*)0X35)
#define		DDRC_REG 		*((volatile u8*)0X34)
#define		PINC_REG 		*((volatile u8*)0X33)

/************* PORTD REGITERS******************/
#define		PORTD_REG 		*((volatile u8*)0X32)
#define		DDRD_REG 		*((volatile u8*)0X31)
#define		PIND_REG 		*((volatile u8*)0X30)


#endif
