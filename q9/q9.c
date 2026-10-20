#include <reg51.h>

void main() {
    TMOD = 0x20;
    TH1  = 0xF3;
    PCON |= 0x80;
    SCON = 0x50;
    TR1  = 1;
    while (1) {
        while (!RI);
        P1 ^= SBUF;
        RI = 0;
    }
}
