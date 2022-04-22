#ifndef _AVR_ATmega328p_
   #define _AVR_ATmega328p_  
#endif
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include"distance.h"
#include <stdlib.h>
#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRC			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTC			/* Define LCD data port */
#define RS PC0							/* Define Register Select (data reg./command reg.) signal pin */
#define RW PC1							/* Define Read/Write signal pin */
#define EN PC2
void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
{
	if (row == 1)
		LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	else if (row == 2)
		LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	LCD_String(str);								/* Call LCD string function */
}