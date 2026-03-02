.include "m328pdef.inc"

.org 0x0000
rjmp main

main:
    ; PD2, PD3, PD4 as input
    ldi r16, 0b00000000
    out DDRD, r16

    ; Enable pull-up resistors on PD2, PD3, PD4
    ldi r16, 0b00011100
    out PORTD, r16

    ; PB0–PB3 as output (to 7447 A,B,C,D)
    ldi r16, 0b00001111
    out DDRB, r16

loop:
    in r16, PIND

    ; Extract P (PD2)
    mov r17, r16
    andi r17, 0b00000100
    lsr r17
    lsr r17

    ; Extract Q (PD3)
    mov r18, r16
    andi r18, 0b00001000
    lsr r18
    lsr r18
    lsr r18

    ; Extract R (PD4)
    mov r19, r16
    andi r19, 0b00010000
    lsr r19
    lsr r19
    lsr r19
    lsr r19

    ; Compute PQ
    mov r20, r17
    and r20, r18

    ; Compute Q R̄
    ldi r21, 1
    mov r22, r19
    eor r22, r21
    mov r23, r18
    and r23, r22

    ; Compute P̄ R
    mov r24, r17
    eor r24, r21
    mov r25, r19
    and r25, r24

    ; F = OR all
    or r20, r23
    or r20, r25

    ; Output to PORTB
    out PORTB, r20

    rjmp loop

