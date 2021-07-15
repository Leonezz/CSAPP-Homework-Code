#include <stdio.h>
#include <stdint.h>
int is_little_endian()
{
    uint16_t x = 0x0001;
    return (x << 8)>>8;
}

int main(int argc, char *argv[])
{
    printf("This is a %s meachine.\n",
           (char *[]){"big endian", "little endian"}[is_little_endian()]);
}

/*
On windows 11 and Ubuntu-20.04(WSL), the result is little endian
And on Ubuntu-20.10(Arm64), the result is the same
*/