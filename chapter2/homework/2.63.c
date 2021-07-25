#include <stdio.h>
#include <stdint.h>
#include <assert.h>
unsigned srl(unsigned x, int k)
{
    // Perform shift arithmetically
    unsigned xsra = (int)x >> k;
    return xsra & (~((~0) << ((sizeof(int) << 3) - k - 1)));
}

int sra(int x, int k)
{
    // Perform shift logically
    int xsrl = (unsigned)x >> k;
    return (int[2]){xsrl, xsrl | ~((~0) << ((sizeof(int) << 3) - k - 1))}
        [(unsigned)(INT32_MAX | x) - (unsigned)INT32_MAX];
}

int main(int argc, char *argv[])
{
    int x = 0x12345678;
    unsigned ux = 0x12345678;
    for (int i = 0; i < 32; ++i)
    {
        //printf("%x shift %d arithmetically, result is %x, which is %s.\n",
        //   x, i, sra(x, i), (char *[]){"not right", "right"}[sra(x, i) == x >> i]);
        //printf("%x shift %u logically, result is %x, which is %s.\n",
        //     ux, i, srl(ux, i), (char *[]){"not right", "right"}[srl(ux, i) == ux >> i]);
        assert(sra(x, i) == x >> i);
        assert(srl(ux, i) == ux >> i);
    }
}