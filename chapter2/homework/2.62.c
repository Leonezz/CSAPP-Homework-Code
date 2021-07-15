#include <stdio.h>

int int_shifts_are_arithmetic()
{
    return -(-1 >> 1);
}

int main(int argc, char* argv[])
{
    printf("int shifts %s arithmetic on this meachine.\n",
        (char*[]){"are not", "are"}[int_shifts_are_arithmetic()]);
}