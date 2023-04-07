/* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>     /* Defines pins, ports, etc */
#include <util/delay.h> /* Functions to waste time */

int main(void)
{

  // -------- Inits --------- //
  DDRB |= 0b00000001; /* Data Direction Register B:
                        writing a one to the bit
                        enables output. */
  DDRD |= 0b11000000;

  // ------ Event loop ------ //
  while (1)
  {

    PORTD = 0b01000000;
    PORTB = 0b00000001;
    _delay_ms(50);

    PORTD = 0b11000000;
    PORTB = 0b00000000;
    _delay_ms(50);

    PORTD = 0b01000000;
    PORTB = 0b00000001;
    _delay_ms(500);

    PORTD = 0b10000000;
    PORTB = 0b00000000;
    _delay_ms(50);

    PORTD = 0b00000000;
    PORTB = 0b00000001;
    _delay_ms(50);

    PORTB = 0b00000000;
    PORTD = 0b10000000;
    _delay_ms(500);
  }
  return 0;
}
