#include <stdio.h>
#include <stdint.h>

int uadd_ok(uint8_t x, uint8_t y)
{
    uint8_t z = x + y;
    return (z >= x) && (z >= y);
}

int tadd_ok(int8_t x, int8_t y)
{
    int8_t z = x + y;
    if (x > 0 && y > 0 && z <= 0)
        return 0;
    if (x < 0 && y < 0 && z >= 0)
        return 0;
    return 1;
}

int tsub_ok(int8_t x, int8_t y)
{
    return tadd_ok(x, -y);
}

void test_uadd(uint8_t x, uint8_t y)
{
    printf("%u + %u = %u", x, y, (uint8_t)(x + y));
    printf((const char *[]){" wo\n", " ok\n"}[uadd_ok(x, y)]);
}

void test_tadd(int8_t x, int8_t y)
{
    printf("%d + %d = %d", x, y, x + y);
    printf((const char *[]){" wo\n", " ok\n"}[tadd_ok(x, y)]);
}

void test_tsub(int8_t x, int8_t y)
{
    printf("%d - %d = %d", x, y, x - y);
    printf((const char *[]){" wo\n", " ok\n"}[tsub_ok(x, y)]);
}

int main(int argc, char *argv[])
{


}