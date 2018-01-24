#include <stdint.h>
#include "msp432p401r.h"


void Initialize_Port1(void)
{
    
}

void Initialize_Port2(void)
{
    P2SEL0 = 0;     // Select to 0
    P2SEL1 = 0;     // Select to 0
    P2DIR = 0x12;   // Direction, bits 4 and 1 to OUT
    P2REN = 0x12;   // Resistor enable, same bits.
}


uint8_t Read_Port1(void)
{

}



void Write_Port2(uint8_t value)
{

}


int main(void)
{

}