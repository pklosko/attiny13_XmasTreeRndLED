/**
 * ATTiny13 - Simple Xmas tree LED flasher
 * 
 * Arduino IDE settings:
 *   ATtiny13
 *   1.2MHz internal
 *   LTO disabled
 *   BOD none
 *   
 * (c) 2019 Petr KLOSKO
 * https://www.klosko.net/
 * 
*/

#include <avr/io.h>
#include <util/delay.h>


#define DELAY_HI    (100)   //LED Flash time
#define DELAY_LO    (1000)  //Base LED delay time
#define DELAY_N     (200)   //LED delay additional time, multiplied by RAND
#define LED_PIN0    PB0
#define LED_PIN1    PB1
#define LED_PIN2    PB2
#define LED_PIN3    PB3
#define LED_PIN4    PB4

int main () {
  uint8_t rnd;
 
 /* setup */
  DIDR0 = 0x1F;    // disable input pins buffer
  DDRB  = 0x1F;    // set all LED pins as OUTPUT
  PORTB = 0;       // set all pins to LOW , not neccesary, set by first step of FOR loop
   
  /* Intializes random number generator */
  srand(DELAY_HI);

  /* loop */
  while (1) {
    rnd = rand() % 9;
    if (rnd == 0  || rnd == 9) { PORTB ^= _BV(LED_PIN0); }
    if (rnd == 2  || rnd == 7) { PORTB ^= _BV(LED_PIN1); }
    if (rnd == 4  || rnd == 5) { PORTB ^= _BV(LED_PIN2); }      
    if (rnd == 6  || rnd == 3) { PORTB ^= _BV(LED_PIN3); }       
    if (rnd == 8  || rnd == 1) { PORTB ^= _BV(LED_PIN4); }
    _delay_ms(DELAY_HI);
    PORTB = 0;
//    _delay_ms(DELAY_300LO);
    delay((rnd * DELAY_N) + DELAY_LO);
 }

}
