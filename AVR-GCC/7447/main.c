#include <avr/io.h>

int main(void)
{
    // Set P, Q, R as input (PD2, PD3, PD4)
    DDRD &= ~(1<<PD2);
    DDRD &= ~(1<<PD3);
    DDRD &= ~(1<<PD4);

    // Enable internal pull-up resistors
    PORTD |= (1<<PD2);
    PORTD |= (1<<PD3);
    PORTD |= (1<<PD4);

    // Set BCD output pins as output (PB0-PB3)
    DDRB |= (1<<PB0);   // A
    DDRB |= (1<<PB1);   // B
    DDRB |= (1<<PB2);   // C
    DDRB |= (1<<PB3);   // D

    while(1)
    {
        // Read inputs (active LOW because pullup used)
        uint8_t P = !(PIND & (1<<PD2));
        uint8_t Q = !(PIND & (1<<PD3));
        uint8_t R = !(PIND & (1<<PD4));

        // XOR logic
        uint8_t f = P ^ Q ^ R;

        // Send BCD to 7447
        if(f == 0)
        {
            PORTB &= ~(1<<PB0);  // A=0
            PORTB &= ~(1<<PB1);  // B=0
            PORTB &= ~(1<<PB2);  // C=0
            PORTB &= ~(1<<PB3);  // D=0
        }
        else
        {
            PORTB |= (1<<PB0);   // A=1
            PORTB &= ~(1<<PB1);
            PORTB &= ~(1<<PB2);
            PORTB &= ~(1<<PB3);
        }
    }
}

