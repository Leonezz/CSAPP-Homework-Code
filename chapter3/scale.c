#include <stdint.h>
int64_t scale(int64_t x, int64_t y, int64_t z)
{
    int64_t t = x + 4 * y + 12 * z;
    return t;
}