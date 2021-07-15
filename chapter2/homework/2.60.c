#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    int mask_clear = ~((int)0xff << (i << 3));
    x &= mask_clear;
    int mask = (int)b << (i << 3);
    return x | mask;
    // return (x&~((int)0xff << (i << 3))) | ((int)b << (i << 3));
}

int main(int argc, char* argv[])
{
    printf("%x\n", replace_byte(0x12345678, 2, 0xab));
    printf("%x\n", replace_byte(0x12345678, 0, 0xab));
}