/*******************************************************/
/* AUTHOR 	: ABDULRAHMAN OSAMA MOHAMED                */
/* DEC		: DIO DRIVER                               */
/* DATE		: 28/1/2020                                */
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO_interface.h"
#include"DIO_register.h"

/****************PIN FUNCTIONS *******************************************************/
/************************************************************************************/

void  DIO_voidSetpinValue(u8 u8_port_copy , u8 u8_pin_copy , u8 u8_value_copy)
{
	if((u8_port_copy <= PORTD)&&(u8_pin_copy <=PIN7))
	{
		if(u8_value_copy == HIGH)
		{
			switch(u8_port_copy)
			{
				case PORTA : SET(PORTA_REG , u8_pin_copy);break;
				case PORTB : SET(PORTB_REG , u8_pin_copy);break;
				case PORTC : SET(PORTC_REG , u8_pin_copy);break;
				case PORTD : SET(PORTD_REG , u8_pin_copy);break;
				default    : break;
			}
		}
		else if(u8_value_copy == LOW)
		{
			switch(u8_port_copy)
			{
				case PORTA : CLR(PORTA_REG , u8_pin_copy);break;
				case PORTB : CLR(PORTB_REG , u8_pin_copy);break;
				case PORTC : CLR(PORTC_REG , u8_pin_copy);break;
				case PORTD : CLR(PORTD_REG , u8_pin_copy);break;
				default    : break;
			}
		}
		else
		{
			/*....................*/
		}
	}
	else
	{
		/*..................*/
	}
}


/****************************************************************************************/
/***************************************************************************************/

void  DIO_voidSetpinDirection(u8 u8_port_copy , u8 u8_pin_copy , u8 u8_direction_copy)
{
	if((u8_port_copy <= PORTD)&&(u8_pin_copy <=PIN7))
	{
		if(u8_direction_copy == OUT)
		{
			switch(u8_port_copy)
			{
				case PORTA : SET(DDRA_REG , u8_pin_copy);break;
				case PORTB : SET(DDRB_REG , u8_pin_copy);break;
				case PORTC : SET(DDRC_REG , u8_pin_copy);break;
				case PORTD : SET(DDRD_REG , u8_pin_copy);break;
				default    : break;
			}
		}
		else if(u8_direction_copy == IN)
		{
			switch(u8_port_copy)
			{
				case PORTA : CLR(DDRA_REG , u8_pin_copy);break;
				case PORTB : CLR(DDRB_REG , u8_pin_copy);break;
				case PORTC : CLR(DDRC_REG , u8_pin_copy);break;
				case PORTD : CLR(DDRD_REG , u8_pin_copy);break;
				default    : break;
			}
		}
		else
		{
			/*....................*/
		}
	}
	else
	{
		/*..................*/
	}
}

/********************************************************************************/
/********************************************************************************/

u8 DIO_u8GetpinValue(u8 u8_port_copy , u8 u8_pin_copy )
{
	u8 resultValue ;

	if((u8_port_copy <= PORTD)&&(u8_pin_copy <=PIN7))
	{
		switch(u8_port_copy)
			{
				case PORTA : resultValue = GET(PINA_REG , u8_pin_copy);break;
				case PORTB : resultValue = GET(PINB_REG , u8_pin_copy);break;
				case PORTC : resultValue = GET(PINC_REG , u8_pin_copy);break;
				case PORTD : resultValue = GET(PIND_REG , u8_pin_copy);break;
				default    : resultValue = 0xff; break;
			}
		
	}
	else
	{
		/* ERROR FOR OUT OF RANGE */
	}	 resultValue = 0xff ;

	return resultValue ;
}

/************************************PORT FUNCTIONS ************************/
/***************************************************************************/

void DIO_voidSetportDirection(u8 u8_port_copy , u8 u8_direction_copy)
{
	switch(u8_port_copy)
	{
		case PORTA : DDRA_REG = u8_direction_copy ;break;
		case PORTB : DDRB_REG = u8_direction_copy ;break;
		case PORTC : DDRC_REG = u8_direction_copy;break;
		case PORTD : DDRD_REG = u8_direction_copy;break;
		default : break;
	}
}

/****************************************************************************/
/****************************************************************************/

void DIO_voidSetportValue(u8 u8_port_copy , u8 u8_value_copy)
{
	switch(u8_port_copy)
	{
		case PORTA : PORTA_REG = u8_value_copy ;break;
		case PORTB : PORTB_REG = u8_value_copy ;break;
		case PORTC : PORTC_REG = u8_value_copy ;break;
		case PORTD : PORTD_REG = u8_value_copy ;break;
		default : break;
	}
}