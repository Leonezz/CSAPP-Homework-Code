// 不能使用 == 和 != 测试
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
int A(int x)
{
    return !~x;
}

int B(int x)
{
    return !x;
}

int C(int x)
{
    return !(~(char)x);
}

int D(int x)
{
    return !(x >> ((sizeof(int) - 1) << 3));
}

int main(int argc, char *argv[])
{
    assert(A(~0));
    assert(!A(~0-0x01));
    assert(B(0));
    assert(!B(1));
    assert(C(0xff));
    assert(!C(0xfe));
    assert(D(INT32_MAX >> 8));
    assert(!D(INT32_MAX));

    assert(A(-1));
    assert(!A(0x12345));
    assert(!B(0x12345));
    assert(!C(0x12345));
    assert(D(0x12345));
    return 0;
}