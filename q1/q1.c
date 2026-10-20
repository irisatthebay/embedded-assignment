#include <reg51.h>

void delay(void)
{
    unsigned int i;
    for(i=0; i<50000; i++);
}

void main(void)
{
    while(1)
    {
        P1 = 0xAA;
        delay();

        P1 = 0x55;
        delay();
    }
}
