
/****************GUARD MY FILE********************/

#ifndef TIMER0_REGISTER_H
#define TIMER0_REGISTER_H

/* REGITER DEFINITIONS */

#define		TCCR0_REG 		*((volatile u8*)0X53)
#define		TCNT0_REG 		*((volatile u8*)0X52)
#define		OCR0_REG 		*((volatile u8*)0X5C)
#define		TIMSK_REG 		*((volatile u8*)0X59)
#define		TIFR_REG 		*((volatile u8*)0X58)

#define 	SREG_REG		*((volatile u8 *)0x5F)


#endif	


