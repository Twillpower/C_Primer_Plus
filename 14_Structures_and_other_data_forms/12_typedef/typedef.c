#include <stdio.h>

typedef unsigned char type;
typedef char * STRING;
typedef char (*FRPTC())[5];
// char p[5] : p是由5个char元素构成的数组
// char (*pt)[5] : pt是一个指针，指向由5个char元素构成的数组
// char (*pt())[5] : pt是一函数，函数返回值是一个指向5个char类型元素数组的指针
// char (*FRPTC())[5] : 同上
// typedef (*FRPTC())[5]

int main(int argc, char const *argv[])
{
    unsigned char byte = 1;
    type i = 1;
    STRING name, sign;
    name = &byte;
    sign = &i;

    printf("%d, %d\n", byte, i);
    printf("%p, %p\n", name, sign);

    return 0;
}
