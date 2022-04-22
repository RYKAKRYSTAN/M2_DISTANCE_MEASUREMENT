#ifndef _AVR_ATmega328p_
   #define _AVR_ATmega328p_  
#endif
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#include"distance.h"
#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRC			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTC			/* Define LCD data port */
#define RS PC0							/* Define Register Select (data reg./command reg.) signal pin */
#define RW PC1							/* Define Read/Write signal pin */
#define EN PC2
void LCD_Init (void)								/* LCD Initialize function */
{
	LCD_Command_Dir |= (1<<RS)|(1<<RW)|(1<<EN);		/* Make LCD command port direction as o/p */
	LCD_Data_Dir = 0xFF;							/* Make LCD data port direction as o/p */
	
	_delay_ms(20);									/* LCD power up time to get things ready, it should always >15ms */
	LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
	LCD_Command (0x06);								/* Auto Increment cursor */
	LCD_Command (0x01);								/* Clear LCD command */
	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
}