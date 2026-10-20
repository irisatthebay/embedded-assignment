#include <reg51.h>

void delay(void)
{
    unsigned int i;
    for(i=0; i<50000; i++);
}

void send(char c)
{
    SBUF = c;

    while(TI == 0);

    TI = 0;
}

void main(void)
{
    TMOD = 0x20;
    TH1 = 0xFD;
    TL1 = 0xFD;

    SCON = 0x50;

    TR1 = 1;

    while(1)
    {
        send('G');
        send('N');
        send('2');
        send('9');
        send('0');
        send('4');

        send('\r');
        send('\n');

        delay();
    }
}
