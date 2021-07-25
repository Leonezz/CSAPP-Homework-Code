int bad_int_size_is_32(){
    // Set most significant bit (msb) of 32-bit machine
    int set_msb = 1 << 31;
    // Shift past msb of 32-bit word
    int beyond_msb = 1 << 32;
    // set_msb is nonzero when word size >= 32
    // beyond_msb is zero when word size <= 32
    return set_msb && !beyond_msb;
}

/*

A: 代码在那个方面没有遵守 C 语言标准
int beyond_msb = 1 << 32; 移动了超过字长的位数
B: 修改代码，使代码在 int 至少为 32 位的任何机器上都能正确运行
int set_msb = 1 << 31;
set_msb >>= 31;
return !(set_msb + 1);
C: 修改代码，使代码在 int 至少为 16 位的任何机器上都能正确运行
int set_msb = 1 << 15 << 15 << 1;
int beyond_msb = set_msb << 1;
return set_msb && !beyond_msb;

*/