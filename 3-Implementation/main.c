#ifndef _AVR_ATmega328p_
   #define _AVR_ATmega328p_  
#endif
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>
#define LCD_Data_Dir DDRB				/* Define LCD data port direction */
#define LCD_Command_Dir DDRC			/* Define LCD command port direction register */
#define LCD_Data_Port PORTB				/* Define LCD data port */
#define LCD_Command_Port PORTC			/* Define LCD data port */
#define RS PC0							/* Define Register Select (data reg./command reg.) signal pin */
#define RW PC1							/* Define Read/Write signal pin */
#define EN PC2				

#include"distance.h"
#define  Trigger_pin	PD0	/* Trigger pin */
#define BAUD_RATE_230400_BPS  2 // 230.4kps

int TimerOverflow = 0;

ISR (TIMER1_OVF_vect)
{  
	
	TimerOverflow++;		/* Increment Timer Overflow count */
	

}

int main(void)
{



   
 	
	char string[10];
	long count;
	double distance;
	
	DDRD= 0x01;			/* Make trigger pin as output */
	PORTD = 0xFF;			/* Turn on Pull-up */
	
	 lcd_Init();
	LCD_String_xy(1, 0, "Ultrasonic");

	
	sei();					/* Enable global interrupt */
	TIMSK0 = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;				/* Set all bit to zero Normal operation */

	while(1)
	{

		PORTD |= (1 << Trigger_pin);/* Give 10us trigger pulse on trig. pin to HC-SR04 */
		_delay_us(10);
		PORTD &= (~(1 << Trigger_pin));
		
		TCNT1 = 0;			/* Clear Timer counter */
		TCCR1B = 0x41;		/* Setting for capture rising edge, No pre-scaler*/
		TIFR0 = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */
		TIFR0 = 1<<TOV1;		/* Clear Timer Overflow flag */

		/*Calculate width of Echo by Input Capture (ICP) on PortD PD6 */
		
		while ((TIFR0 & (1 << ICF1)) == 0);	/* Wait for rising edge */
		TCNT1 = 0;			/* Clear Timer counter */
		TCCR1B = 0x01;		/* Setting for capture falling edge, No pre-scaler */
		TIFR0 = 1<<ICF1;		/* Clear ICP flag (Input Capture flag) */
		TIFR0 = 1<<TOV1;		/* Clear Timer Overflow flag */
		TimerOverflow = 0;	/* Clear Timer overflow count */

		while ((TIFR0 & (1 << ICF1)) == 0); /* Wait for falling edge */
		count = ICR1 + (65535 * TimerOverflow);	/* Take value of capture register */
		/* 8MHz Timer freq, sound speed =343 m/s, calculation mentioned in doc. */
		distance = (double)count / 466.47;

		dtostrf(distance, 2, 2, string);/* Convert distance into string */
		strcat(string, " cm   ");
		LCD_String_xy(2, 0, "Dist = ");
		LCD_String_xy(2, 7, string);	/* Print distance on LDC16x2 */
		_delay_ms(200);
		 int i = 0;
    unsigned int ubrr = BAUD_RATE_230400_BPS;
    unsigned char data[] = "Distance in cm  ";
 
    /* Set Baudrate  */
    UBRR0H = (ubrr>>8);
    UBRR0L = (ubrr);
 
    UCSR0C = 0x06;       /* Set frame format: 8data, 1stop bit  */
    UCSR0B = (1<<TXEN0); /* Enable  transmitter                 */
 
    while(1) /* Loop the messsage continously */
    { 
        i = 0;
        while(data[i] != 0) /* print the String  "Hello from ATmega328p" */
        {
          while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer*/
          UDR0 = data[i];            /* Put data into buffer, sends the data */
          i++;                             /* increment counter           */
        }
      }

	}
}
