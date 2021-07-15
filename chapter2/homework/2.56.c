#include <stdio.h>
#include <stdint.h>
void show_bytes(uint8_t *bytes, uint32_t len)
{
    for (uint32_t i = 0; i < len; ++i)
        printf(" %.2x", bytes[i]);
    printf("\n");
}
int main(int argc, char *argv[])
{
    int a = INT8_MAX;
    char b = INT8_MIN;
    int c = INT_FAST16_MIN;
    int d = INT_LEAST32_MAX;
    int64_t e = INT64_MAX;
    double f = (double)e;
    double g = *(double*)&e;
    show_bytes((uint8_t*)&a, sizeof(int));
    show_bytes((uint8_t*)&b, sizeof(char));
    show_bytes((uint8_t*)&c, sizeof(int));
    show_bytes((uint8_t*)&d, sizeof(int));
    show_bytes((uint8_t*)&e, sizeof(uint64_t));
    show_bytes((uint8_t*)&f, sizeof(double));
    show_bytes((uint8_t*)&g, sizeof(double));
}

/*
 7f 00 00 00
 80
 00 00 00 00
 ff ff ff 7f
 ff ff ff ff ff ff ff 7f
 00 00 00 00 00 00 e0 43
 ff ff ff ff ff ff ff 7f
*/