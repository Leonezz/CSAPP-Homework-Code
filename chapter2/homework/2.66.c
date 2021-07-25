#include <assert.h>
/*
Generate mask indicating left most 1 in x. Assume w = 32.
For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
If x = 0, then return 0.
*/
int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x >> 1) + (x && 0x1);
}

int main(int argc, char* argv[])
{
    assert(leftmost_one(0xF) == 0x8);
    assert(leftmost_one(0x0F) == 0x08);
    assert(leftmost_one(0) == 0);
    assert(leftmost_one(0x6000) == 0x4000);
}