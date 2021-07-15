#include <stdio.h>
#include <stdint.h>
#include <time.h>
int32_t div16(int32_t x)
{
    uint32_t mask = 0;
    mask |= x;
    int32_t v[2] = {x, x + 15};
    return v[mask >> 31] >> 4;
}

int32_t div16_op(int32_t x)
{
    uint32_t bias = (x >> 31) & 0xf;
    return (x + bias) >> 4;
}

void test(int32_t x)
{
    printf("div16(%d) = %d, %s\n", x, div16(x), (const char *[]){"Wrong", "Right"}[div16(x) == x / 16]);
}

int main(int argc, char *argv[])
{
    int x;
    clock_t c1 = clock();
    for(int32_t i = INT16_MIN*10000; i < INT16_MAX*10000; ++i){
        x = div16(i);
    }
    clock_t c2 = clock();
    printf("div16 costs %f secs.\n", (c2 - c1)*1.0/CLOCKS_PER_SEC);
    for(int32_t i = INT16_MIN*10000; i < INT16_MAX*10000; ++i){
        x = div16_op(i);
    }
    clock_t c3 = clock();
    printf("div16_op costs %f secs.\n", (c3 - c2)*1.0/CLOCKS_PER_SEC);
}