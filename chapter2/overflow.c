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
    char s[5][32] = {0};
    for(int i = 0; i < 32; ++i){
        int y = 1;
        y <<= i;
        printf("|`");
        for(int j = 31; j > -1; --j){
            printf("%d", (y >> j)&0x1);
            if(!j) printf("`");
            else if(!((32 - j)%4))
                printf("` `");
        }
        for(int k = 4;k>-1;--k){
            if((i >> k)&0x1)s[k][i] = 1;
            printf("|`%d`", (i >> k)&0x1);
        }
        printf("|\n");
    }
    for(int i = 0; i < 5;++i){
        printf("X_%d: ",i);
        for(int j = 0; j < 32; ++j){
            if(s[i][j])printf(" Y_{%d} +", j);
        }
        printf("\b\n");
    }
}