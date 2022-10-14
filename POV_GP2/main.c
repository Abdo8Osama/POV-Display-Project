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

void PRINT_STRING(u8 data);

const u8 CHARACTER_MATRIX_NEW[27][7]={
		{0x7e,0x90,0x90,0x90,0x90,0x90,0x7e},   // A 0x41 65
		{0x7f,0x91,0x91,0x91,0x91,0x91,0x66},   // B 0x42 66
		{0x7e,0x81,0x81,0x81,0x81,0x81,0x00},   // C 0x43 67
		{0xff,0x81,0x81,0x81,0x81,0x42,0x3c},   // D 0x44 68
		{0xFf,0x89,0x89,0x89,0x81,0x81,0x81},   // E 0x45 69
		{0xFf,0x88,0x88,0x88,0x80,0x80,0x80},   // F 0x46 70
		{0x7e,0x81,0x81,0x89,0x8f,0x80,0x60},   // G 0x47 71
		{0xff,0x08,0x08,0x08,0x08,0x08,0xff},   // H 0x48 72
		{0x00,0x81,0x81,0xff,0x81,0x81,0x00},   // I 0x49 73
		{0x02,0x81,0x81,0xfe,0x80,0x80,0x00},   // J 0x4a 74
		{0xff,0x18,0x24,0x42,0x81,0x01,0x00},   // K 0x4b 75
		{0xff,0x01,0x01,0x01,0x01,0x00,0x00},   // L 0x4c 76
		{0xff,0x80,0x40,0x20,0x40,0x80,0xff},   // M 0x4d 77
		{0xfe,0x04,0x08,0x10,0x20,0x40,0xfe},   // N 0x4e 78
		{0x7e,0x81,0x81,0x81,0x81,0x81,0x7e},   // O 0x4f 79
		{0xff,0x90,0x90,0x90,0x90,0x90,0x60},   // P 0x50 80
		{0x7B,0x82,0x82,0x8A,0x86,0x82,0x7C},   // Q 0x51 81
		{0xff,0x90,0x98,0x94,0x92,0x91,0x61},   // R 0x52 82
		{0x42,0xA1,0x91,0x89,0x85,0x81,0x82},   // S 0x53 83
		{0x80,0x80,0x80,0xff,0x80,0x80,0x80},   // T 0x54 84
		{0xfe,0x01,0x01,0x01,0x01,0x01,0xfe},   // U 0x55 85
		{0x18,0x04,0x02,0x01,0x02,0x04,0x18},   // V 0x56 86
		{0xff,0x02,0x04,0x08,0x04,0x02,0xff},   // W 0x57 87
		{0x81,0x42,0x24,0x10,0x24,0x42,0x81},   // X 0x58 88
		{0x80,0x40,0x20,0x1f,0x20,0x40,0x80},   // Y 0x59 89
		{0x82,0x86,0x8A,0x92,0xA2,0xC2,0x82},   // Z 0x5a 90
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00},   // space  91
};
u8 Display_String[] = "ABDO";

u8 Display_String_nums_ABDO[] = {65 ,66 ,68 ,79 };	//ABDO
u8 Display_String_nums_OSAMA[] = {79 ,83 ,65 ,77 ,65};//OSAMA
u8 Display_String_nums_SHYMAA[] = {83 ,72 ,89 ,77 ,65 ,65};//SHYMAA
u8 Display_String_nums_ARWA[] = {65 ,82 ,87 ,65 };//ARWA
u8 Display_String_nums_ITI[] = {84 ,72 ,65 ,78 ,75 ,83 , 91,73 ,84 ,73 };//THANKS ITI
u8 Display_String_nums_OTHMAN[] = {65 ,91 ,79 ,84 ,72 ,77 ,65 ,78 };//A OTHMAN
u8 Display_String_nums_AMGAD[] = {65 ,77 ,71 ,65 ,68 };//AMGAD
u8 Display_String_nums_HESHAM[] = {72 ,69 ,83 ,72 ,65 ,77 };//HESHAM

u8 char_length = 7;
u8 i =0 ,j =0 ;

const u8 leds_number = 8;
const u8 max_cycle = 35 ;
const u16 resolution = 289 ;

volatile u16 TIMER0_Overflows =0 ;
volatile u8 cycles =0;
volatile u32 cycle_time =0;
volatile u32 resolution_time =350;

void EXTI0_ISR(void)
{
	cycles ++ ;
	if(cycles == max_cycle)
	{
		cycles = 0 ;
		cycle_time=(TCNT0_REG + (TIMER0_Overflows * 256))/(max_cycle);
		TCNT0_REG_LOAD(0);
		resolution_time = cycle_time/resolution;
	}
}

void TIMER0_ISR (void)
{
	TIMER0_Overflows ++ ;
}

int main ()
{
	u8 k =0 ;
	u32 time =0 ;
	DIO_voidSetportDirection(PORTA ,PORT_OUT);
	DIO_voidSetportValue(PORTA , 0);

	DIO_voidSetpinDirection(PORTD ,PIN2 ,IN );
	DIO_voidSetpinValue(PORTD,PIN2,HIGH);

	CALLback_EXT0(EXTI0_ISR);
	CALLback_TIMER0V(TIMER0_ISR);

	EXT_VoidInit(EXTI0 , FALLING_EDGE ,INTERRUPT);
	TIMER0_INIT(NORMAL , FCPU8 , INTERRUPTOV , 0 , 0 ,OCO0_DISABLE);

	while(1)
	{

/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<4;k++)
			{
				PRINT_STRING(Display_String_nums_ABDO[k]);
			}

			for (k=0;k<7;k++)
			{
				PRINT_STRING(91);
			}
		}

/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<5;k++)
			{
				PRINT_STRING(Display_String_nums_OSAMA[k]);
			}

			for (k=0;k<6;k++)
			{
				PRINT_STRING(91);
			}
		}

/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<6;k++)
			{
				PRINT_STRING(Display_String_nums_SHYMAA[k]);
			}

			for (k=0;k<5;k++)
			{
				PRINT_STRING(91);
			}
		}
/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<4;k++)
			{
				PRINT_STRING(Display_String_nums_ARWA[k]);
			}

			for (k=0;k<7;k++)
			{
				PRINT_STRING(91);
			}
		}

/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<5;k++)
			{
				PRINT_STRING(Display_String_nums_AMGAD[k]);
			}

			for (k=0;k<6;k++)
			{
				PRINT_STRING(91);
			}
		}

/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<6;k++)
			{
				PRINT_STRING(Display_String_nums_HESHAM[k]);
			}

			for (k=0;k<5;k++)
			{
				PRINT_STRING(91);
			}
		}

/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<8;k++)
			{
				PRINT_STRING(Display_String_nums_OTHMAN[k]);
			}

			for (k=0;k<3;k++)
			{
				PRINT_STRING(91);
			}
		}
/********************************************************************************/
		for (time=0;time<999999;time++)
		{
			for (k=0;k<10;k++)
			{
				PRINT_STRING(Display_String_nums_ITI[k]);
			}

			for (k=0;k<1;k++)
			{
				PRINT_STRING(91);
			}
		}

/********************************************************************************/




	}
	return 0 ;
}

void PRINT_STRING(u8 data)
{


	if (data < 65 || data > 91)
	{
		data = 91;
	}
	data -= 65;

	for (i=0;i<char_length; i++)
	{
		u8 temp_data = CHARACTER_MATRIX_NEW[data][i];

		DIO_voidSetportValue(PORTA ,temp_data) ;
		_delay_us(resolution_time * 2);
	}

	DIO_voidSetportValue(PORTA ,PORT_IN) ;
	_delay_us(resolution_time*6);

}
