#include <avr/io.h>
#include <util/delay.h>
#define LED_PIN 5

void
blink(){
    //! Делать что-то
}

int
main(void){
    DDRB |= 1 << LED_PIN;
    PORTB |= 1 << LED_PIN;
    _delay_ms(1000);
    PORTB &= ~(1 << LED_PIN);
    blink();
    return 0;
}