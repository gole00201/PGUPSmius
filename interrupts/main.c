#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__ /*Потому что у меня только Arduino UNO*/
#endif

#include <avr/io.h>
#include <util/delay.h>
#define PIN 5

void
blink(){
    PORTB ^= 1 << PIN;
    _delay_ms(1000);
}

int
main(void){
    DDRB |= 1 << PIN;
    while (1)
    {
        blink();
    }
    return 0;
}