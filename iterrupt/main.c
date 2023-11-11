#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define PIN 5

void
init_timer_and_interrupt(){
}

void
blink(){
    PORTB ^= 1 << PIN;
    _delay_ms(1000);
}

int
main(void){
    sei();
    DDRB |= 1 << PIN;
    while (1)
    {
        blink();
    }
    return 0;
}