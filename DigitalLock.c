#include <stdint.h>
#include "msp432p401r.h"

#define P1_BTIS 0x12    /* Bit1 = Button2, Bit4 = Button1 */
#define P2_BITS 0x7     /* Bit0 = RED, Bit1 = GREEN, Bit2 = BLUE */
#define BUTTON1(x) (uint8_t) (((x) & 0x10) >> 4)
#define BUTTON2(x) (uint8_t) (((x) & 0x02) >> 1)
#define PACK(blue, green, red) (uint8_t) (((blue) << 2) | ((green) << 1) | (red))

uint8_t convert_button_to_LED(uint8_t buttons)
{
    uint8_t one = BUTTON1(buttons);
    uint8_t two = BUTTON2(buttons);
    return PACK(
        one & two,      // BLUE = b1 and b2
        (one | two) ^ 1,// GREEN = not (b1 or b2)
        one ^ two       // RED = b1 xor b2
    );
}

void Initialize_Port1(void)
{
    P1SEL0 = 0;
    P1SEL1 = 0;
    P1REN  = P1_BTIS;
}

void Initialize_Port2(void)
{
    P2SEL0 = 0;
    P2SEL1 = 0;
    P2DIR  = P2_BITS;
    P2REN  = P2_BITS;
}

uint8_t Read_Port1(void)
{
    return P1IN;
}

void Write_Port2(uint8_t value)
{
    P2OUT = value;
}

int main(void)
{
    Initialize_Port1();
    Initialize_Port2();
    while (1)
    {
        Write_Port2(convert_button_to_LED(Read_Port1()));
    }
    return 0;
}