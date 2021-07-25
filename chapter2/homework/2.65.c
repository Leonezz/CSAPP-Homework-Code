#include <assert.h>

// Return 1 when x contains an odd number of 1s; 0 otherwise
// Assume w = 32
int odd_ones(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return !(x & 0x1);
}

int main(int argc, char* argv[])
{
    assert(odd_ones(0x00));
    assert(odd_ones(0x03));
    assert(odd_ones(0x05));
    assert(odd_ones(0x06));
    assert(odd_ones(0x09));
    assert(!odd_ones(0x01));
    assert(!odd_ones(0x02));
    assert(!odd_ones(0x07));
}