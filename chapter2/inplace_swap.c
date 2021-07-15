/*
2.10 
*/

#include <stdio.h>
#include <time.h>
void inplace_swap(int *a, int *b)
{
    *b = *a ^ *b; // a = a, b = a ^ b
    *a = *a ^ *b; // a = a ^ (a ^ b) = 0 ^ b = b, b = a ^ b
    *b = *a ^ *b; // a = b, b = b ^ (a ^ b) = a
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void bench(int *a, int *b, int cnt, void (*fun)(int *, int *))
{
    for (int i = 0; i < cnt; ++i)
        fun(a, b);
}

int main(int argc, char *argv[])
{
    int a = 1;
    int b = -1;
    clock_t start = clock();
    bench(&a, &b, 0xfffffff, inplace_swap);
    clock_t stop = clock();
    printf("inplace swap costs: %f sencods.\n", (stop - start) * 1.0 / CLOCKS_PER_SEC);
    start = clock();
    bench(&a, &b, 0xfffffff, swap);
    stop = clock();
    printf("normal swap costs: %f sencods.\n", (stop - start) * 1.0 / CLOCKS_PER_SEC);

    return 0;
}