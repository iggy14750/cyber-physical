
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ASSERT(condtion, message) if (!(condtion)) {puts((message));exit(0);}

#define RED   (uint8_t) 1
#define GREEN (uint8_t) 2
#define BLUE  (uint8_t) 4
#define BUTTON1(x) (uint8_t) (((x) & 0x10) >> 4)
#define BUTTON2(x) (uint8_t) (((x) & 0x02) >> 1)
#define PACK(blue, green, red) (uint8_t) (((blue) << 2) | ((green) << 1) | (red))

uint8_t convert(uint8_t buttons)
{
    uint8_t one = BUTTON1(buttons);
    uint8_t two = BUTTON2(buttons);
    return PACK(
        one & two,      // BLUE = b1 and b2
        (one | two) ^ 1,// GREEN = not (b1 or b2)
        one ^ two       // RED = b1 xor b2
    );
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

    ASSERT(convert(0x12) == BLUE, "Neither button pressed, result not blue");
    ASSERT(convert(0x10) == RED, "Button 1 pressed, result not red");
    ASSERT(convert(0x02) == RED, "Button 2 pressed, result not red");
    ASSERT(convert(0x00) == GREEN, "Both buttons pressed, result not green.");

    return 0;
}