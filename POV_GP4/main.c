/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Abdo2
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"DIO_register.h"
#include"TIMER0_int.h"
#include"TIMER0_register.h"
#include"EXT_INTERRUPT_int.h"
#include"util/delay.h"

void PRINT_STRING(u8 data);
void PRINT_NUMBERS(u8 data);

void PRINT_CLOCK(void) ;
void PRINT_ABDO(void) ;
void PRINT_OSAMA(void) ;
void PRINT_SHYMAA(void) ;
void PRINT_ARWA(void) ;
void PRINT_THANKS_ITI(void) ;
void PRINT_A_OTHMAN(void) ;
void PRINT_AMGAD(void) ;
void PRINT_HESHAM(void) ;
void PRINT_A_ATTIA(void);
void PRINT_THANKS(void);
void PRINT_WELCOME(void);
void PRINT_EVERY_ONE(void);
void PRINT_TO(void);
void PRINT_POV_DISPLAY(void);
void PRINT_PROJECT(void);
void PRINT_BY(void);
void PRINT_AND(void);


const u8 NUMBERS_MATRIX[11][9]={
		{0x00,0xff,0x81,0x81,0x81,0x81,0x81,0xff,0x00},   // 0 0x30 92
		{0x00,0x00,0x41,0x41,0xff,0x01,0x01,0x00,0x00},   // 1 0x31 93
		{0x00,0x00,0x01,0x43,0x85,0x89,0x91,0x61,0x00},   // 2 0x32 94
		{0x00,0x00,0x00,0x02,0x91,0x91,0x92,0x6C,0x00},   // 3 0x33 95
		{0x00,0x08,0x18,0x28,0x48,0xff,0x08,0x00,0x00},   // 4 0x34 96
		{0x01,0xf1,0x91,0x91,0x91,0x9f,0x80,0x80,0x00},   // 5 0x35 97
		{0x00,0xff,0x91,0x91,0x91,0x9f,0x00,0x00,0x00},   // 6 0x36 98
		{0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x7f,0x00},   // 7 0x37 99
		{0x00,0xff,0x91,0x91,0x91,0x91,0x91,0xff,0x00},   // 8 0x38 100
		{0x00,0xff,0x81,0x81,0x81,0x81,0x81,0xff,0x00},   // 9 0x39 101
		{0x00,0x00,0x00,0xe7,0xe7,0xe7,0x00,0x00,0x00},   // : 0x3a 102

};
const u8 CHARACTER_MATRIX[27][9]={
		{0x00,0x7e,0x90,0x90,0x90,0x90,0x90,0x7e,0x00},   // A 0x41 65
		{0x00,0x7f,0x91,0x91,0x91,0x91,0x91,0x66,0x00},   // B 0x42 66
		{0x00,0x7e,0x81,0x81,0x81,0x81,0x81,0x00,0x00},   // C 0x43 67
		{0x00,0xff,0x81,0x81,0x81,0x81,0x42,0x3c,0x00},   // D 0x44 68
		{0x00,0xFf,0x89,0x89,0x89,0x81,0x81,0x81,0x00},   // E 0x45 69
		{0x00,0xFf,0x88,0x88,0x88,0x80,0x80,0x80,0x00},   // F 0x46 70
		{0x00,0x7e,0x81,0x81,0x89,0x8f,0x80,0x60,0x00},   // G 0x47 71
		{0x00,0xff,0x08,0x08,0x08,0x08,0x08,0xff,0x00},   // H 0x48 72
		{0x00,0x00,0x81,0x81,0xff,0x81,0x81,0x00,0x00},   // I 0x49 73
		{0x00,0x02,0x81,0x81,0xfe,0x80,0x80,0x00,0x00},   // J 0x4a 74
		{0x00,0xff,0x18,0x24,0x42,0x81,0x01,0x00,0x00},   // K 0x4b 75
		{0x00,0xff,0x01,0x01,0x01,0x01,0x00,0x00,0x00},   // L 0x4c 76
		{0x00,0xff,0x80,0x40,0x20,0x40,0x80,0xff,0x00},   // M 0x4d 77
		{0x00,0xfe,0x04,0x08,0x10,0x20,0x40,0xfe,0x00},   // N 0x4e 78
		{0x00,0x7e,0x81,0x81,0x81,0x81,0x81,0x7e,0x00},   // O 0x4f 79
		{0x00,0xff,0x90,0x90,0x90,0x90,0x90,0x60,0x00},   // P 0x50 80
		{0x00,0x7B,0x82,0x82,0x8A,0x86,0x82,0x7C,0x00},   // Q 0x51 81
		{0x00,0xff,0x90,0x98,0x94,0x92,0x91,0x61,0x00},   // R 0x52 82
		{0x00,0x42,0xA1,0x91,0x89,0x85,0x81,0x82,0x00},   // S 0x53 83
		{0x00,0x80,0x80,0x80,0xff,0x80,0x80,0x80,0x00},   // T 0x54 84
		{0x00,0xfe,0x01,0x01,0x01,0x01,0x01,0xfe,0x00},   // U 0x55 85
		{0x00,0x18,0x04,0x02,0x01,0x02,0x04,0x18,0x00},   // V 0x56 86
		{0x00,0xff,0x02,0x04,0x08,0x04,0x02,0xff,0x00},   // W 0x57 87
		{0x00,0x81,0x42,0x24,0x10,0x24,0x42,0x81,0x00},   // X 0x58 88
		{0x00,0x80,0x40,0x20,0x1f,0x20,0x40,0x80,0x00},   // Y 0x59 89
		{0x00,0x82,0x86,0x8A,0x92,0xA2,0xC2,0x82,0x00},   // Z 0x5a 90
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},   // space  91


};

u8 char_length = 9;
u8 i =0 ,j =0 ;
u8 val;
//static u8 flag = 0 ;

const u8 leds_number = 8;
const u8 max_cycle = 35 ;
const u32 resolution = 360 ;

volatile u32 TIMER0_Overflows =0 ;
volatile u32 cycles =0;
volatile u32 cycle_time =0;
volatile u32 resolution_time =30;

volatile u8 hours = 12;    // set hours
volatile u8 minutes = 15;  // set minutes
volatile u8 seconds = 00;  // set seconds



void EXTI0_ISR(void)
{
	cycles ++ ;
}


void TIMER0_ISR (void)
{
	TIMER0_Overflows ++ ;
	if(TIMER0_Overflows == 3907)
	{

		cycle_time=(u32)(((u32)1000000)/((u32)cycles));
		resolution_time = (u32)((u32)cycle_time/(u32)resolution);
		cycles = 0 ;
		TIMER0_Overflows =0;
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
	u8 k =0 ;
	//u32 time =0 ;
	DIO_voidSetportDirection(PORTA ,PORT_OUT);
	DIO_voidSetportValue(PORTA , 0);

	DIO_voidSetpinDirection(PORTD ,PIN2 ,IN );
	DIO_voidSetpinValue(PORTD,PIN2,HIGH);

	CALLback_EXT0(EXTI0_ISR);
	CALLback_TIMER0V(TIMER0_ISR);

	EXT_VoidInit(EXTI0 , FALLING_EDGE ,INTERRUPT);
	TIMER0_INIT(NORMAL , FCPU8 , INTERRUPTOV , 192 , 0 ,OCO0_DISABLE);

	if (hours == 12)
	{
		hours = 0;
	}

	_delay_ms(1000);

	while(1)
	{

		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_CLOCK();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_WELCOME();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_EVERY_ONE();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_TO();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_POV_DISPLAY();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_PROJECT();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_BY();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_ABDO();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_OSAMA();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_AND();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_SHYMAA();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_AND();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_ARWA();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_CLOCK();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_THANKS();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_TO();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_A_OTHMAN();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_AND();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_A_ATTIA();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_AND();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_AMGAD();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_AND();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_HESHAM();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_THANKS_ITI();
		}
		_delay_ms(1000);
		/********************************************************************************/
		for (k=0;k<32;k++)
		{
			PRINT_CLOCK();
		}
		_delay_ms(1000);
		/********************************************************************************/


	}
	return 0 ;
}


void PRINT_STRING(u8 data)
{

	u8 temp_data;

	if (data < 65 || data > 102)
	{
		data = 91;
	}
	data -= 65;

	for (i=0;i<char_length; i++)
	{
		temp_data = CHARACTER_MATRIX[data][i];
		DIO_voidSetportValue(PORTA ,temp_data) ;
		_delay_us(resolution_time);
		//		_delay_us(240);
	}

	DIO_voidSetportValue(PORTA ,PORT_IN) ;
	_delay_us(resolution_time*2);
	//	_delay_us(1600);

}

void PRINT_NUMBERS(u8 data)
{
	u8 temp_data ;
	for (i=0;i<char_length; i++)
	{
		temp_data = NUMBERS_MATRIX[data][i];
		DIO_voidSetportValue(PORTA ,temp_data) ;
		_delay_us(resolution_time);
		//		_delay_us(240);     // for LED pixel width   (change the value according to motor speed. Increase for low speed, decrease for high speed motor)

	}

	DIO_voidSetportValue(PORTA ,PORT_IN) ;
	_delay_us(resolution_time*2);
	//	_delay_us(1600);     // for LED pixel width   (change the value according to motor speed. Increase for low speed, decrease for high speed motor)

}


void PRINT_CLOCK(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/************************************************/
	PRINT_NUMBERS((hours/10));
	PRINT_NUMBERS((hours%10));
	PRINT_NUMBERS((10));
	PRINT_NUMBERS((minutes/10));
	PRINT_NUMBERS((minutes%10));
	PRINT_NUMBERS((10));
	PRINT_NUMBERS((seconds/10));
	PRINT_NUMBERS((seconds%10));
	/*************************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_ABDO(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/************************************************/
	PRINT_STRING(65);
	PRINT_STRING(66);
	PRINT_STRING(68);
	PRINT_STRING(79);
	/***********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_OSAMA(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/******************************************/
	PRINT_STRING(79);
	PRINT_STRING(83);
	PRINT_STRING(65);
	PRINT_STRING(77);
	PRINT_STRING(65);
	/********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_SHYMAA(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/************************************/
	PRINT_STRING(83);
	PRINT_STRING(72);
	PRINT_STRING(89);
	PRINT_STRING(77);
	PRINT_STRING(65);
	PRINT_STRING(65);

	/***************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}


}

void PRINT_ARWA(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/********************************************/
	PRINT_STRING(65);
	PRINT_STRING(82);
	PRINT_STRING(87);
	PRINT_STRING(65);
	/*********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_THANKS_ITI(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/*******************************************/
	PRINT_STRING(84);
	PRINT_STRING(72);
	PRINT_STRING(65);
	PRINT_STRING(78);
	PRINT_STRING(75);
	PRINT_STRING(83);
	PRINT_STRING(91);
	PRINT_STRING(73);
	PRINT_STRING(84);
	PRINT_STRING(73);
	/*********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}
void PRINT_THANKS(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/*************************************/
	PRINT_STRING(84);
	PRINT_STRING(72);
	PRINT_STRING(65);
	PRINT_STRING(78);
	PRINT_STRING(75);
	PRINT_STRING(83);
	/**************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_A_OTHMAN(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/*****************************************/
	PRINT_STRING(68);
	PRINT_STRING(91);

	PRINT_STRING(65);
	PRINT_STRING(72);
	PRINT_STRING(77);
	PRINT_STRING(65);
	PRINT_STRING(68);

	PRINT_STRING(91);
	PRINT_STRING(79);
	PRINT_STRING(84);
	PRINT_STRING(72);
	PRINT_STRING(77);
	PRINT_STRING(65);
	PRINT_STRING(78);
	/********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}


}

void PRINT_A_ATTIA(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/***************************************/
	PRINT_STRING(65);
	PRINT_STRING(91);

	PRINT_STRING(65);
	PRINT_STRING(84);
	PRINT_STRING(84);
	PRINT_STRING(73);
	PRINT_STRING(65);
	/**************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_AMGAD(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/******************************************/
	PRINT_STRING(65);
	PRINT_STRING(77);
	PRINT_STRING(71);
	PRINT_STRING(65);
	PRINT_STRING(68);
	/***********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}


}


void PRINT_HESHAM(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/****************************************/
	PRINT_STRING(72);
	PRINT_STRING(69);
	PRINT_STRING(83);
	PRINT_STRING(72);
	PRINT_STRING(65);
	PRINT_STRING(77);
	/*************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}


}
void PRINT_WELCOME(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/**********************************************/
	PRINT_STRING(87);
	PRINT_STRING(69);
	PRINT_STRING(76);
	PRINT_STRING(67);
	PRINT_STRING(79);
	PRINT_STRING(77);
	PRINT_STRING(69);
	/***********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}
void PRINT_EVERY_ONE(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/***********************************************/
	PRINT_STRING(69);
	PRINT_STRING(86);
	PRINT_STRING(69);
	PRINT_STRING(82);
	PRINT_STRING(89);
	PRINT_STRING(91);
	PRINT_STRING(79);
	PRINT_STRING(78);
	PRINT_STRING(69);
	/*************************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}


}
void PRINT_TO(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/*********************************************/
	PRINT_STRING(84);
	PRINT_STRING(79);
	/******************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_POV_DISPLAY(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/*****************************************/
	PRINT_STRING(80);
	PRINT_STRING(79);
	PRINT_STRING(86);
	PRINT_STRING(91);

	PRINT_STRING(68);
	PRINT_STRING(73);
	PRINT_STRING(83);
	PRINT_STRING(80);
	PRINT_STRING(76);
	PRINT_STRING(65);
	PRINT_STRING(89);
	/**********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}
void PRINT_PROJECT(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/******************************************/
	PRINT_STRING(80);
	PRINT_STRING(82);
	PRINT_STRING(79);
	PRINT_STRING(74);
	PRINT_STRING(69);
	PRINT_STRING(67);
	PRINT_STRING(84);
	/******************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}
void PRINT_BY(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/***********************************************/
	PRINT_STRING(66);
	PRINT_STRING(89);
	/************************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}

void PRINT_AND(void)
{
	val =  GET(PIND_REG , PIN2);
	while (val == LOW)
	{
		val =  GET(PIND_REG , PIN2);
	}
	/*********************************************/
	PRINT_STRING(65);
	PRINT_STRING(78);
	PRINT_STRING(68);
	/********************************************/
	val =  GET(PIND_REG , PIN2);
	while (val == HIGH)
	{
		val =  GET(PIND_REG , PIN2);
	}

}
