/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: EXTERNAL INTERRUPT DRIVER                            */
/* DATE		: 10/2/2020                                 */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXT_INTERRUPT_int.h"
#include"EXT_INTERRUPT_register.h"

/* POINTERS TO FUNCTION  */

void (* PF_EXT0) (void);
void (* PF_EXT1) (void);
void (* PF_EXT2) (void);

/*************************ISR FUNCTIONS********************************/
/**********************************************************************/


void __vector_1 (void) __attribute__ ((signal , used));

void __vector_1 (void)
{
	PF_EXT0();
}

/**********************************************************************/


void __vector_2 (void) __attribute__ ((signal , used));

void __vector_2 (void)
{
	PF_EXT1();

}


/**********************************************************************/


void __vector_3 (void) __attribute__ ((signal , used));

void __vector_3 (void)
{
	PF_EXT2();

}


/***********************CALLBACK FUNCTIONS *****************************/
/**********************************************************************/

void CALLback_EXT0 (void (* ptr) (void))
{
	PF_EXT0 = ptr ;
}

/**********************************************************************/

void CALLback_EXT1 (void (* ptr) (void))
{
	PF_EXT1 = ptr ;
}

/**********************************************************************/

void CALLback_EXT2 (void (* ptr) (void))
{
	PF_EXT2 = ptr ;
}


/****************INIT FUNCTION ****************************************/
/**********************************************************************/

void EXT_VoidInit(u8 EXTIu8_NUM , u8 EXTIu8_Mode , u8 INTERRUPT_POLLING)
{
	switch(EXTIu8_NUM)
		{
			case EXTI0  :
				switch(EXTIu8_Mode)
				{
					case FALLING_EDGE:
						CLR(MCUCR_REG,ISC00_PIN);
						SET(MCUCR_REG,ISC01_PIN);
						break ;
					case RISING_EDGE:
						SET(MCUCR_REG,ISC00_PIN);
						SET(MCUCR_REG,ISC01_PIN);
						break ;
					case ON_CHANGE_EDGE:
						SET(MCUCR_REG,ISC00_PIN);
						CLR(MCUCR_REG,ISC01_PIN);
						break ;
					case LOW_LEVEL_EDGE:
						CLR(MCUCR_REG,ISC00_PIN);
						CLR(MCUCR_REG,ISC01_PIN);
						break ;
				}		
				break ;
			case EXTI1  :
				switch(EXTIu8_Mode)
				{
					case FALLING_EDGE:
						CLR(MCUCR_REG,ISC10_PIN);
						SET(MCUCR_REG,ISC11_PIN);
						break ;
					case RISING_EDGE:
						SET(MCUCR_REG,ISC10_PIN);
						SET(MCUCR_REG,ISC11_PIN);
						break ;
					case ON_CHANGE_EDGE:
						SET(MCUCR_REG,ISC10_PIN);
						CLR(MCUCR_REG,ISC11_PIN);
						break ;
					case LOW_LEVEL_EDGE:
						CLR(MCUCR_REG,ISC10_PIN);
						CLR(MCUCR_REG,ISC11_PIN);
						break ;
				}				
				break ;
			case EXTI2  :
				switch(EXTIu8_Mode)
				{
					case FALLING_EDGE:
						CLR(MCUCSR_REG,ISC2_PIN);
						break ;
					case RISING_EDGE:
						SET(MCUCSR_REG,ISC2_PIN);									
						break ;
				}		
				break ;

		}
		
	switch(INTERRUPT_POLLING)
	{
		case POLLING:	
			CLR(GICR_REG,INT0E);
			CLR(GICR_REG,INT0E);
			CLR(GICR_REG,INT0E);

			break ;
				
		case INTERRUPT  :
			switch(EXTIu8_NUM)
			{
				case EXTI0  :
					SET(GICR_REG,INT0E);
					break ;
				case EXTI1  :
					SET(GICR_REG,INT1E);
					break ;
				case EXTI2  :
					SET(GICR_REG,INT2E);
					break ;
			}
			SET(SREG_REG,GIE_PIN);
			break ;				
	}
}


/******************DISABLE INTERRUPT****************************************************/

void EXT_INTvoidDisable (u8 EXTIu8_NUM )
{
	switch(EXTIu8_NUM)
		{
			case EXTI0  :
				CLR(GICR_REG,INT0E);
				break ;
			case EXTI1  :
				CLR(GICR_REG,INT1E);
				break ;
			case EXTI2  :
				CLR(GICR_REG,INT2E);
				break ;
		}
}

/************************READ FLAG**********************************************/

u8 EXT_INT_u8_ReadFlag (u8 EXTIu8_NUM )
{
	u8 flag_value ;
	switch(EXTIu8_NUM)
			{
				case EXTI0  :
					flag_value = GET(GIFR_REG,6);
					break ;
				case EXTI1  :
					flag_value = GET(GIFR_REG,7);
					break ;
				case EXTI2  :
					flag_value = GET(GIFR_REG,5);
					break ;
			}
	return flag_value;
}



/************************CLEAR FLAG**********************************************/

void EXT_INT_void_ClearFlag (u8 EXTIu8_NUM )
{
	switch(EXTIu8_NUM)
	{
		case EXTI0  :
			SET(GIFR_REG,6);
			break ;
		case EXTI1  :
			SET(GIFR_REG,7);
			break ;
		case EXTI2  :
			SET(GIFR_REG,5);
			break ;
	}
}
