#include <stdio.h>
#include <stdint.h>

int rebuild_word(int x, int y)
{
    int mask_x = 0xff;
    int mask_y = ((~0)>>8)<<8;
    return (x & mask_x) | (y & mask_y);
}

int main(int argc, char* argv[])
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    printf("%x\n", rebuild_word(x, y));
}