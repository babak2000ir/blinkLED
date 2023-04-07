                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  DDRB = 0xff;            /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */

  // ------ Event loop ------ //
  while (1) {
    int a=1000;                                        
    PORTB = 0b01010101;          
    _delay_ms(a); 
                                         
    PORTB = 0b10101010;          
    _delay_ms(a);
  }                                                  
  return 0;                     
}
