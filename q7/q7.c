#include <reg51.h>

sbit UP = P2^0;
sbit DOWN = P2^1;

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

    P1 = seg[count];

    while(1)
    {
        if(UP == 0)
        {
            delay();

            if(UP == 0)
            {
                count++;

                if(count > 9)
                    count = 0;

                P1 = seg[count];

                while(UP == 0);
            }
        }

        if(DOWN == 0)
        {
            delay();

            if(DOWN == 0)
            {
                if(count == 0)
                    count = 9;
                else
                    count--;

                P1 = seg[count];

                while(DOWN == 0);
            }
        }
    }
}
