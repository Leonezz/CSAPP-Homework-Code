#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x)
{
    return 0x55555555 & x;
}

int main(int argc, char* argv[])
{
    const unsigned x[] = {0x2, 0x8, 0xA};
    const unsigned y[] = {0x1, 0x4, 0x5};
    for(int i = 0;i < 3; ++i){
        assert(any_odd_one(y[i]));
        assert(!any_odd_one(x[i]));
    }
}