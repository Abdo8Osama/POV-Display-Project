/****************GUARD MY FILE********************/
#ifndef INTERRUPT_INTERFACE_H
#define INTERRUPT_INTERFACE_H

/* EXTERNAL INTERRUPT */
#define EXTI0	0		
#define EXTI1	1		
#define EXTI2	2	
	
/*  SENSING MODE */
#define FALLING_EDGE	0				
#define RISING_EDGE		1				
#define ON_CHANGE_EDGE	2				
#define LOW_LEVEL_EDGE	3	
			
/*  SENSING MODE */
#define INTERRUPT	0		
#define POLLING		1	

/* INTERUPT PORTS AND PINS */
#define INT0PORT		PORTD		//D PORT
#define INT1PORT		PORTD		//D PORT
#define INT2PORT		PORTB		//D PORT

#define INT0PIN		2		
#define INT1PIN		3		
#define INT2PIN		2		


/* INTERRUPT CONTROL PINS */
#define GIE_PIN		7		//SREG_REG

#define ISC00_PIN	0		//MCUCR_REG
#define ISC01_PIN	1
#define ISC10_PIN	2
#define ISC11_PIN	3
#define ISC2_PIN	5		//MCUCSR_REG

#define INT0E	6			//GICR_REG
#define INT1E	7
#define INT2E	5

#define INT0F	6			//GIFR_REG
#define INT1F	7
#define INT2F	5


/****************INTERRUPT FUNCTIONS *********************/

void EXT_VoidInit(u8 EXTIu8_NUM , u8 EXTIu8_Mode , u8 INTERRUPT_POLLING);
void CALLback_EXT0 (void (* ptr) (void));
void CALLback_EXT1 (void (* ptr) (void));
void CALLback_EXT2 (void (* ptr) (void));
void EXT_INTvoidDisable (u8 EXTIu8_NUM );
u8 EXT_INT_u8_ReadFlag (u8 EXTIu8_NUM );
void EXT_INT_void_ClearFlag (u8 EXTIu8_NUM );




#endif
