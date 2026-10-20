#include <reg51.h>

void main(void)
{
    TMOD = 0x20;
    TH1 = 0xFD;
    TL1 = 0xFD;

    SCON = 0x50;

    TR1 = 1;

    P1 = 0x00;

    while(1)
    {
        while(RI == 0);

        RI = 0;

        P1 = SBUF;
    }
}
