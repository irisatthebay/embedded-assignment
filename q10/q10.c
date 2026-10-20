#include <reg51.h>

sbit RS = P1^3;
sbit E  = P1^2;

void delay(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

void nibble(unsigned char n) {
    P1 = (P1 & 0x0F) | (n & 0xF0);
    E = 1;
    E = 0;
}

void lcd_cmd(unsigned char c) {
    RS = 0;
    nibble(c);
    nibble(c << 4);
    delay(2);
}

void lcd_data(unsigned char c) {
    RS = 1;
    nibble(c);
    nibble(c << 4);
    delay(2);
}

void lcd_print(char *s) {
    while (*s) lcd_data(*s++);
}

void main() {
    RS = 0;
    P1 = 0x20;
    E = 1; E = 0;
    delay(2);
    lcd_cmd(0x28);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);

    lcd_cmd(0x80);
    lcd_print("GN2904");
    lcd_cmd(0xC0);
    lcd_print("24ELBEA184");

    while (1);
}
