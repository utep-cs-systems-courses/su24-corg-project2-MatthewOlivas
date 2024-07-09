//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);		/* CPU off, GIE on */
}


char green_state = 0;

int counter = 0;



void __interrupt_vec(WDT_VECTOR) WDT() { /* 250 interrupts/sec */

  counter++;

  switch(green_state) {

  case 0:

    if (counter >= 1) {

      green_state = 1;

      P1OUT &= ~LED_GREEN;

      counter = 0;

    }

    break;

  case 1:

    if (counter >= 7) {

      green_state = 0;

      P1OUT |= LED_GREEN;

      counter = 0;

    }

    break;

  }

}

