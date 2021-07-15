#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    // Perform shift arithmetically
    unsigned xsra = (int)x >> k;
}

int sra(int x, int k)
{
    // Perform shift logically
    int xsrl = (unsigned)x >> k;
}