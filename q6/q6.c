#include <reg51.h>

sbit SW = P2^0;

unsigned char code seg[] =
{
    0x06,    /* 1 */
    0x5B,    /* 2 */
    0x4F,    /* 3 */
    0x66,    /* 4 */
    0x6D,    /* 5 */
    0x7D     /* 6 */
};

void delay(void)
{
    unsigned int i;
    for(i=0; i<300; i++);
}

void main(void)
{
    unsigned char n = 0;

    while(1)
    {
        if(SW == 0)
        {
            n++;

            if(n >= 6)
                n = 0;

            P1 = seg[n];

            delay();
        }
    }
}
