#include <reg51.h>

sbit SW = P2^0;

unsigned char code seg[] =
{
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void delay(void)
{
    unsigned int i;
    for(i=0; i<50000; i++);
}

void main(void)
{
    unsigned char count = 0;

    while(1)
    {
        if(SW == 0)
        {
            delay();

            if(SW == 0)
            {
                count++;

                if(count > 9)
                    count = 0;

                P1 = seg[count];

                while(SW == 0);
            }
        }
    }
}
