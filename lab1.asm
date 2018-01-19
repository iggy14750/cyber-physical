
.thumb
.text
    .align 2

    .global main
    .thumbfunc main

main: .asmfunc
    mov  R1, #0x4C00    ; Address of Buttons, low 16 bits
    movt R1, #0x4000    ; Address of Buttons, top 16 bits

    ADD  R2, R1, #3     ; Address of LEDs

Top:                    ; Our read loop.

    LDRB R3, [R1]       ; Read the state of the buttons.
    LSR  R3, R3, #1     ; Set-up for next inst
    AND  R4, R3, #1     ; R4 is the state of button 2
    LSR  R3, R3, #3     ; R3 is the state of button 1

    ORR  R5, R3, R4     ; BLUE = not (b1 or b2), still need 'not'.
    EOR  R5, R5, #1     ; BLUE = not (b1 or b2), here we invert that bit.

    LSL  R5, R5, #1     ; Need to pack RED and GREEN in lower bits.
    AND  R6, R3, R4     ; GREEN = b1 and b2.
    ORR  R5, R5, R6     ; R5 = (BLUE << 1) | GREEN

    LSL  R5, R5, #1     ; Still need to pack RED
    EOR  R6, R3, R4     ; RED = b1 xor b2
    ORR  R5, R5, R6     ; R5 = (((BLUE << 1) | GREEN) << 1) | RED

    STRB R5, [R2]       ; Write our calculations to LEDs.

    B Top

.end