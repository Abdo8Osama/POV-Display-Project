
/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: TIMER0 DRIVER                          	   */
/* DATE		: 16/2/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include "TIMER0_int.h"
#include "TIMER0_register.h"


/*************************TIMER FUNCTIONS********************************/
/**********************************************************************/

void (* PF_TIMER0V) (void);
void (* PF_TIMER0C) (void);

void __vector_11 (void) __attribute__ ((signal , used));

void __vector_11 (void)
{
	PF_TIMER0V();
}

void __vector_10 (void) __attribute__ ((signal , used));

void __vector_10 (void)
{
	PF_TIMER0C();
}

/**********************************************************************/

void CALLback_TIMER0V (void (* ptr) (void))
{
	PF_TIMER0V = (void (*) (void))ptr ;
}


void CALLback_TIMER0C (void (* ptr) (void))
{
	PF_TIMER0C = (void (*) (void))ptr ;
}

/**********************************************************************/

void TIMER0V_INT_Disable (void )
{
	CLR(TIMSK_REG , TOIE0);
}

/**********************************************************************/

void TIMER0C_INT_Disable (void )
{
	CLR(TIMSK_REG , OCIE0);
}

/**********************************************************************/

void TOV0_Flag_Clear(void)
{
	SET(TIFR_REG , TOV0);

}

/**********************************************************************/

void OCF0_Flag_Clear(void)
{
	SET(TIFR_REG , OCF0);

}

/**********************************************************************/

u8 TOV0_Flag_Read(void)
{
	u8 read ;
	read = GET(TIFR_REG , TOV0);
	return read;
}

/**********************************************************************/

u8 OCF0_Flag_Read(void)
{
	u8 read ;
	read = GET(TIFR_REG , OCF0);
	return read;
}

/**********************************************************************/
void TIMER0_INIT(u8 TIMER_MODE , u8 CLOCK_SOURCE , u8 INTERRUPT_POLLING ,u8 TCNT_PRELOAD ,u8 OCR_PRELOAD , u8 OCO_INVERTING_NONINVERTING)
{
	CLR(TCCR0_REG , FOC0);

	if(OCO_INVERTING_NONINVERTING == OCO0_DISABLE)
	{
		CLR(TCCR0_REG , COM00);
		CLR(TCCR0_REG , COM01);
	}
	else if(OCO_INVERTING_NONINVERTING == NONINVERTING)
	{
		CLR(TCCR0_REG , COM00);
		SET(TCCR0_REG , COM01);

	}else if(OCO_INVERTING_NONINVERTING == INVERTING)
	{
		SET(TCCR0_REG , COM00);
		SET(TCCR0_REG , COM01);
	}


	if(TIMER_MODE == NORMAL)
	{
		CLR(TCCR0_REG , WGM01);
		CLR(TCCR0_REG , WGM00);
		if(OCO_INVERTING_NONINVERTING == OCO0_TOGGLE)
		{
			SET(TCCR0_REG , COM00);
			CLR(TCCR0_REG , COM01);
		}
	}
	else if(TIMER_MODE == PWM_C_PH)
	{
		CLR(TCCR0_REG , WGM01);
		SET(TCCR0_REG , WGM00);
		//DIO_voidSetpinDirection(PORTB,PIN0,OUT);
	}
	else if(TIMER_MODE == CTC)
	{
		SET(TCCR0_REG , WGM01);
		CLR(TCCR0_REG , WGM00);
		if(OCO_INVERTING_NONINVERTING == OCO0_TOGGLE)
		{
			SET(TCCR0_REG , COM00);
			CLR(TCCR0_REG , COM01);
		}
	}
	else if(TIMER_MODE == FAST_PWM)
	{
		SET(TCCR0_REG , WGM01);
		SET(TCCR0_REG , WGM00);
		//DIO_voidSetpinDirection(PORTB,PIN0,OUT);
	}


	if(CLOCK_SOURCE == OFF)
	{
		CLR(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU)
	{
		SET(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU8)
	{
		CLR(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU64)
	{
		SET(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		CLR(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU256)
	{
		CLR(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FCPU1024)
	{
		SET(TCCR0_REG , CS00);
		CLR(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
	}
	else if(CLOCK_SOURCE == FALLING_EDGE_COUNTER)
	{
		CLR(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
		DIO_voidSetpinDirection(PORTB,PIN0,IN);
		DIO_voidSetpinValue(PORTB,PIN0,HIGH);
	}
	else if(CLOCK_SOURCE == RISING_EDGE_COUNTER)
	{
		SET(TCCR0_REG , CS00);
		SET(TCCR0_REG , CS01);
		SET(TCCR0_REG , CS02);
		DIO_voidSetpinDirection(PORTB,PIN0,IN);
		DIO_voidSetpinValue(PORTB,PIN0,LOW);

	}


	if(INTERRUPT_POLLING == INTERRUPTOV)
	{
		SET(TIMSK_REG , TOIE0);
		SET(SREG_REG,GIE_PIN);
	}
	else if(INTERRUPT_POLLING == INTERRUPTOC)
	{
		SET(TIMSK_REG , OCIE0);
		SET(SREG_REG,GIE_PIN);
	}
	else if(INTERRUPT_POLLING == POLLING)
	{
		CLR(TIMSK_REG , TOIE0);
		CLR(TIMSK_REG , OCIE0);
	}


	TCNT0_REG =  TCNT_PRELOAD;
	OCR0_REG =   OCR_PRELOAD ;
}
/**********************************************************************/
void TCNT0_REG_LOAD(u8 TCNT0_VALUE)
{
	TCNT0_REG =  TCNT0_VALUE;
}
/**********************************************************************/
void OCR0_REG_LOAD(u8 OCR0_VALUE)
{
	OCR0_REG =  OCR0_VALUE;
}
