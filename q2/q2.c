#include <reg51.h>

sbit SW = P2^0;

void delay(void)
{
    unsigned int i;
    for(i=0; i<50000; i++);
}

void main(void)
{
    P3 = 0xFF;

    while(1)
    {
        if(SW == 0)
        {
            P3 = 0x00;
            delay();

            P3 = 0xFF;
            delay();
        }
        else
        {
            P3 = 0xFF;
        }
    }
}
