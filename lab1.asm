
.thumb
.text
    .align 2

    .global main
    .thumbfunc main

main: .asmfunc
    mov  R1, #0x4C00    ; Address of Buttons, low 16 bits
    movt R1, #0x4000    ; Address of Buttons, top 16 bits

    mov  R0, #0
    strb R0, [R1, #0xA] ; P1SEL0
    strb R0, [R1, #0xB] ; P2SEL0
    strb R0, [R1, #0xC] ; P1SEL1
    strb R0, [R1, #0xD] ; P2SEL1

    mov  R2, #0x12      ; Pins 4 and 1 for the switches.
    strb R2, [R1, #6]   ; Resistor enable for switches.

    mov  R2, #7  		; Pins 0,1,2 for the LEDs.
    strb R2, [R1, #5]   ; Direction for LEDs.
    strb R2, [R1, #7]   ; Resistor enable for LEDs.

Top:                    ; Our read loop.

    LDRB R3, [R1]       ; Read the state of the buttons.
    LSR  R3, R3, #1     ; Set-up for next inst
    AND  R4, R3, #1     ; R4 is the state of button 2
    LSR  R3, R3, #3     ; Get the bit we need in last position.
    AND  R3, R3, #1     ; R3 is the state of button 1

    AND  R5, R3, R4     ; BLUE = b1 and b2.

    LSL  R5, R5, #1     ; Need to pack RED and GREEN in lower bits.
    ORR  R6, R3, R4     ; GREEN = not (b1 or b2), still need to invert.
    EOR  R6, R6, #1     ; GREEN = not (b1 or B2), now inverted.
    ORR  R5, R5, R6     ; R5 = (BLUE << 1) | GREEN

    LSL  R5, R5, #1     ; Still need to pack RED
    EOR  R6, R3, R4     ; RED = b1 xor b2
    ORR  R5, R5, R6     ; R5 = (((BLUE << 1) | GREEN) << 1) | RED

    STRB R5, [R1, #3]   ; Write our calculations to LEDs.

    B Top

.end
