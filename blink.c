#include <msp430.h>				


/**
 * blink.c
 */
void main(void)
 {
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer

	P1DIR |= 0x01;                  // configure P1.0 as output
	//P4DIR |= 0x80;                  // configure P4.7 as output

	P1OUT |= 0x01;               // Initialize P1.0 to 1
	//P4OUT |= 0x80;                // Initialize P4.7 to 1

	// P1OUT &=0xFE; //
	 P4OUT &=0x7F; //  Initialize P4.7 to 1

	volatile unsigned int i;		// volatile to prevent optimization


	while(1)
	{
	    P1OUT ^= 0x01;              // toggle P1.0
		P4OUT ^= 0x80;				// toggle P4.7

		for(i=50000; i>0; i--);     // delay
	}
}
