#include <reg51.h>

sbit RS = P1^3;
sbit EN = P1^2;

void delay(void)
{
    unsigned int i;
    for(i=0; i<500; i++);
}

void pulse(void)
{
    EN = 1;
    EN = 0;
}

void cmd(unsigned char x)
{
    RS = 0;

    P1 = (P1 & 0x0F) | (x & 0xF0);
    pulse();

    P1 = (P1 & 0x0F) | ((x << 4) & 0xF0);
    pulse();

    delay();
}

void data(unsigned char x)
{
    RS = 1;

    P1 = (P1 & 0x0F) | (x & 0xF0);
    pulse();

    P1 = (P1 & 0x0F) | ((x << 4) & 0xF0);
    pulse();

    delay();
}

void lcd_init(void)
{
    RS = 0;
    EN = 0;

    P1 = (P1 & 0x0F) | 0x20;
    pulse();

    cmd(0x28);
    cmd(0x0C);
    cmd(0x06);
    cmd(0x01);
}

void main(void)
{
    lcd_init();

    cmd(0x80);

    data('A');
    data('L');
    data('I');
    data('G');
    data('A');
    data('R');
    data('H');

    cmd(0xC0);

    data('M');
    data('U');
    data('S');
    data('L');
    data('I');
    data('M');

    while(1);
}
