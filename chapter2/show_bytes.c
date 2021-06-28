#include <stdio.h>
#include <stdint.h>

void show_bytes(uint8_t *bytes, uint32_t len)
{
    for (uint32_t i = 0; i < len; ++i)
        printf(" %.2x", bytes[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((uint8_t *)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((uint8_t *)&x, sizeof(float));
}

void show_ptr(void *x)
{
    show_bytes((uint8_t *)&x, sizeof(void *));
}

void show_str(const char* s, uint32_t len){
    show_bytes((uint8_t*)s, len);
}

void test_int(int val){
    show_int(val);
    show_float((float)val);
    show_ptr(&val);
}

int main(int argc, char* argv[]){
    test_int(12345);
    show_str("abcdef", 7);
}

/*

In Linux64:
    39 30 00 00
    00 e4 40 46
    2c 2b 65 df fc 7f 00 00
In Windows:
    39 30 00 00
    00 e4 40 46
    00 fe 61 00 00 00 00 00
Turns out that both the two os use litter ending.
*/
