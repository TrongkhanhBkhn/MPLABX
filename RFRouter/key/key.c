#include "key.h"
uint8_t GetKey(void)
{
    if(!BUTTON1)
    {
        delay_ms(1);
        if(!BUTTON1)
        return KEY_1;
    }
    else if (!BUTTON2)
    {
        delay_ms(1);
        if(!BUTTON2)
        return KEY_2;
    }
    return NO_BUTTON;
}