/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdo2
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"TIMER0_int.h"
#include"TIMER0_register.h"
#include"EXT_INTERRUPT_int.h"
#include"util/delay.h"


void displayClear();
void drawMinuteMarker();
void drawHourMarker();
void drawQuarterMarker();
void drawHoursHand();
void drawMinutesHand();
void drawSecondsHand();
void drawInner_Circle();

u8  n, ADCvalue, propeller_posn;
u8 val;

//u32 previousTime = 0;

volatile u8 hours = 12;    // set hours
volatile u8 minutes = 15;  // set minutes
volatile u8 seconds = 00;  // set seconds

volatile u32 count =0;

void TIMER0_ISR (void)
{
	count++;
	if(count == 3907)
	{
		count =0;
		TCNT0_REG_LOAD(192);

		seconds = seconds+1;
		if (seconds == 60)
		{
			seconds = 0;
			minutes = minutes+1;
		}
		if (minutes == 60)
		{
			minutes = 0;
			hours = hours+1;
		}
		if (hours == 12)
		{
			hours = 0;
		}

	}
}

int main ()
{
	DIO_voidSetportDirection(PORTA ,PORT_OUT);
	DIO_voidSetportDirection(PORTC ,PORT_OUT);

	DIO_voidSetportValue(PORTA , 0x00);
	DIO_voidSetportValue(PORTC , 0x00);

	DIO_voidSetpinDirection(PORTD ,PIN2 ,IN);
	DIO_voidSetpinValue(PORTD ,PIN2 ,HIGH);

	if(hours == 12)
	{
		hours = 0;
	}

	CALLback_TIMER0V(TIMER0_ISR);
	TIMER0_INIT(NORMAL , FCPU8 , INTERRUPTOV , 192 , 0 ,OCO0_DISABLE);

	while(1)
	{
		val = DIO_u8GetpinValue(PORTD , PIN2);
		while (val == LOW)
		{
			val = DIO_u8GetpinValue(PORTD , PIN2);
		}

		propeller_posn=30;
		n=0;

		while(n < 60)
		{

			drawMinuteMarker();

			if ((propeller_posn==0) || (propeller_posn==5) || (propeller_posn==10) || (propeller_posn==15) || (propeller_posn==20) || (propeller_posn==25) || (propeller_posn==30) || (propeller_posn==35) || (propeller_posn==40) || (propeller_posn==45) || (propeller_posn==50) || (propeller_posn==55))
			{
				drawHourMarker();
			}

			if ((propeller_posn==0) || (propeller_posn==15) || (propeller_posn==30) || (propeller_posn==45))
			{
				drawQuarterMarker();
			}

			if((propeller_posn == hours*5) || (( propeller_posn == 0 ) && (hours == 0)))
			{
				drawHoursHand();
			}

			if(propeller_posn == minutes)
			{
				drawMinutesHand();
			}

			if(propeller_posn == seconds)
			{
				drawSecondsHand();
			}

			_delay_us(240);     // for LED pixel width   (change the value according to motor speed. Increase for low speed, decrease for high speed motor)

			displayClear();
			drawInner_Circle();

			_delay_us(1600);   // for the gap between LED pixels/minutes markers  (change the value according to motor speed. Increase for low speed, decrease for high speed motor)

			n++;
			propeller_posn++;
			if(propeller_posn == 60)
			{
				propeller_posn=0;
			}
		}

		val = DIO_u8GetpinValue(PORTD , PIN2);

		while (val == HIGH)
		{
			val = DIO_u8GetpinValue(PORTD , PIN2);
		}


	}
	return 0 ;
}


void displayClear()
{
	DIO_voidSetportValue(PORTA , 0x00);
	DIO_voidSetportValue(PORTC , 0x00);
}

void drawMinuteMarker()
{
	DIO_voidSetpinValue(PORTC,PIN1,HIGH);
}

void drawHourMarker()
{
	DIO_voidSetpinValue(PORTC,PIN2,HIGH);
	DIO_voidSetpinValue(PORTC,PIN3,HIGH);
}

void drawQuarterMarker()
{
	DIO_voidSetpinValue(PORTC,PIN4,HIGH);
	DIO_voidSetpinValue(PORTC,PIN5,HIGH);
}

void drawHoursHand()
{
	DIO_voidSetpinValue(PORTA,PIN0,HIGH);
	DIO_voidSetpinValue(PORTA,PIN1,HIGH);
	DIO_voidSetpinValue(PORTA,PIN2,HIGH);
	DIO_voidSetpinValue(PORTA,PIN3,HIGH);
	DIO_voidSetpinValue(PORTA,PIN4,HIGH);
	DIO_voidSetpinValue(PORTA,PIN5,HIGH);
}

void drawMinutesHand()
{
	DIO_voidSetpinValue(PORTA,PIN0,HIGH);
	DIO_voidSetpinValue(PORTA,PIN1,HIGH);
	DIO_voidSetpinValue(PORTA,PIN2,HIGH);
	DIO_voidSetpinValue(PORTA,PIN3,HIGH);
	DIO_voidSetpinValue(PORTA,PIN4,HIGH);
	DIO_voidSetpinValue(PORTA,PIN5,HIGH);
	DIO_voidSetpinValue(PORTA,PIN6,HIGH);
	DIO_voidSetpinValue(PORTA,PIN7,HIGH);
}

void drawSecondsHand()
{
	DIO_voidSetpinValue(PORTA,PIN0,HIGH);
	DIO_voidSetpinValue(PORTA,PIN1,HIGH);
	DIO_voidSetpinValue(PORTA,PIN2,HIGH);
	DIO_voidSetpinValue(PORTA,PIN3,HIGH);
	DIO_voidSetpinValue(PORTA,PIN4,HIGH);
	DIO_voidSetpinValue(PORTA,PIN5,HIGH);
	DIO_voidSetpinValue(PORTA,PIN6,HIGH);
	DIO_voidSetpinValue(PORTA,PIN7,HIGH);

	DIO_voidSetpinValue(PORTC,PIN7,HIGH);
	DIO_voidSetpinValue(PORTC,PIN6,HIGH);
}

void drawInner_Circle()
{
	DIO_voidSetpinValue(PORTA,PIN0,HIGH);
	_delay_us(30);
	DIO_voidSetpinValue(PORTA,PIN0,LOW);
}

