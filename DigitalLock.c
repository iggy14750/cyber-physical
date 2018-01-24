#include <stdint.h>
#include "msp432p401r.h"

#define P1_BTIS 0x12    /* Bit1 = Button2, Bit4 = Button1 */
#define P2_BITS 0x7     /* Bit0 = RED, Bit1 = GREEN, Bit2 = BLUE */

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
    return 0;
}