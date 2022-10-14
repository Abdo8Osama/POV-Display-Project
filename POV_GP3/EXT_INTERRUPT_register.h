/****************GUARD MY FILE********************/

#ifndef INTERRUPT_REGISTER_H
#define INTERRUPT_REGISTER_H


/* REGITER DEFINITIONS */
#define MCUCR_REG	*((volatile u8 *)0x55)
#define MCUCSR_REG	*((volatile u8 *)0x54)
#define SREG_REG	*((volatile u8 *)0x5F)
#define GICR_REG	*((volatile u8 *)0x5B)
#define GIFR_REG	*((volatile u8 *)0x5A)




#endif	/* EXTERNAL_INTERRUPT _REG_H */
