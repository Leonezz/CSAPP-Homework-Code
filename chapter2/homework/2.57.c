#include <stdio.h>
#include <stdint.h>
void show_bytes(uint8_t *bytes, uint32_t len)
{
    for (uint32_t i = 0; i < len; ++i)
        printf(" %.2x", bytes[i]);
    printf("\n");
}

void show_short(short x)
{
    show_bytes((uint8_t*)&x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((uint8_t*)&x, sizeof(long));
}

void show_double(double x)
{
    show_bytes((uint8_t*)&x, sizeof(x));
}

int main(int argc, char*argv[])
{
    int a = 12345;
    show_bytes((uint8_t*)&a, sizeof(int));

    short a_s = (short)a;
    short b_s = *(short*)&a;
    show_short(a_s);
    show_short(b_s);

    // 越界访问
    long a_l = (long)a;
    long b_l = *(long*)&a;
    show_long(a_l);
    show_long(b_l);

    // 越界访问
    double a_d = (double)a;
    double b_d = *(double*)&a;
    show_double(a_d);
    show_double(b_d);
    return 0;
}