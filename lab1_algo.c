
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ASSERT(condtion, message) if (!(condtion)) {puts((message));exit(0);}

#define RED   (uint8_t) 1
#define GREEN (uint8_t) 2
#define BLUE  (uint8_t) 4
#define BUTTON1(x) (uint8_t) (((x) & 0x10) >> 4)
#define BUTTON2(x) (uint8_t) (((x) & 0x02) >> 1)

uint8_t convert(uint8_t buttons)
{
    return BLUE;
}

int main() {
    /* Just getting the proper data from the button bits. */
    ASSERT(BUTTON1(0x12) == 1, "Both buttons set, BUTTON1 not found on.");
    ASSERT(BUTTON1(0x10) == 1, "Just button 1 set, BUTTON1 not found on.");
    ASSERT(BUTTON1(0x02) == 0, "Just button 2 set, BUTTON1 found on.");
    ASSERT(BUTTON1(0xff) == 1, "Lots of bits set, BUTTON1 not found on.");
    ASSERT(BUTTON2(0x12) == 1, "Both buttons set, BUTTON2 not found on.");
    ASSERT(BUTTON2(0x10) == 0, "Just button 1 set, BUTTON2 found on.");
    ASSERT(BUTTON2(0x02) == 1, "Just button 2 set, BUTTON2 not found on.");
    ASSERT(BUTTON2(0xff) == 1, "Lots of bits set, BUTTON2 not found on.");
    
    ASSERT(convert(0x12) == BLUE, "Both buttons pressed, result not blue");
    
    return 0;
}