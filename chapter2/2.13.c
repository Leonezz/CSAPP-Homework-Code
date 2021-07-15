/*
2.13 使用bis(位设置)和bic(位清除)实现布尔运算
*/
#include <stdio.h>
#include <time.h>
/*
x: the input data
m: the input mask
use the mask m to opearte the data x, 
set the bits of x to 1 where the bits of mask m is 1
return the result
*/
int bis(int x, int m)
{
    return x | m;
}

/*
x: the input data
m: the input mask
use the mask m to operate the data x,
set the bits of x to 0 where the bits of mask m is 1
*/
int bic(int x, int m)
{
    return x & (~m);
}

// compute x|y using only calls to functions bis and bic
int bool_or(int x, int y)
{
    return bis(x, y);
}

// compute x^y using only calls to functions bis and bic
int bool_xor(int x, int y)
{
    /*
    int high_bits = bic(x, ~y);          // 获取x和y中都为1的位
    int low_bits = ~bis(x, y);           // 获取x和y中都为0的位
    int high = bis(high_bits, low_bits); // 取以上两种情况的并集
    int result = bic(x, high);           // 符合以上两种情况的位设置为0
    int low = ~high;                     // 获取以上情况的补集
    result = bis(result, low);           // 设置为1
    return result;
    */

    // Note: x ^ y = (x & ~y) | (y & ~x)
    return bis(bic(x, y), bic(y, x));
}

int test(int x, int y)
{
    printf("%x | %x = %x, is %s.\n",
           x, y, bool_or(x, y), (const char *[]){"not right", "right"}[(x | y) == bool_or(x, y)]);
    printf("%x ^ %x = %x, is %s.\n",
           x, y, bool_xor(x, y), (const char *[]){"not right", "right"}[(x ^ y) == bool_xor(x, y)]);
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 200; ++i)
    {
        test(rand(), rand());
    }
    return 0;
}
