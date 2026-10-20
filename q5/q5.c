#include <reg51.h>

sbit DIG1 = P2^0;
sbit DIG2 = P2^1;

unsigned char code seg[] =
{
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
    0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void delay(void)
{
    unsigned int i;
    for(i=0; i<100; i++);
}

void display(unsigned char n)
{
    unsigned char tens;
    unsigned char ones;
    unsigned char i;

    tens = n / 10;
    ones = n % 10;

    for(i=0; i<100; i++)
    {
        DIG1 = 0;
        DIG2 = 1;
        P1 = seg[tens];
        delay();

        DIG2 = 0;
        DIG1 = 1;
        P1 = seg[ones];
        delay();
    }
}

void main(void)
{
    unsigned char count;

    while(1)
    {
        for(count=0; count<100; count++)
        {
            display(count);
        }
    }
}
