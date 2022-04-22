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
#define EN PC2							/* Define Enable signal pin */
void LCD_Cha (char char_data)						/* LCD data write function */
{
	LCD_Data_Port = char_data;						/* Write data to LCD data port */
	LCD_Command_Port &= ~(1<<RW);					/* Make RW LOW (Write) */
	LCD_Command_Port |= (1<<EN)|(1<<RS);			/* Make RS HIGH (data reg.) and High to Low transition on EN (Enable) */
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(1);									/* Wait little bit */
}