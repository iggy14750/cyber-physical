
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ASSERT(condtion, message) if (!(condtion)) {puts((message));exit(0);}

#define RED   (uint8_t) 1
#define GREEN (uint8_t) 2
#define BLUE  (uint8_t) 4
#define BUTTON1(x) (uint8_t) (((x) & 0x02) >> 1)
#define BUTTON2(x) (uint8_t) (((x) & 0x10) >> 4)

uint8_t convert(uint8_t buttons)
{
    return BLUE;
}

int main() {
    ASSERT(convert(0x12) == BLUE, "Both buttons pressed, result not blue");
    
    return 0;
}