#include <stdio.h>

// 声明的联合只能储存一个类型的值
// 编译器分配足够的空间以便它能储存联合声明中占用最大字节的类型
// a, b, c共用同一块存储单元
union hold
{
    int a;
    int b;
    int c;
};


int main(int argc, char const *argv[])
{
    union hold value;
    value.a = 100;

    // 点运算符表示正在使用哪种数据类型, ，用指针访问联合时也要使用->运算符
    printf("%d.\n", value.b); 
    printf("%d.\n", value.c); 
    value.b = 200;
    printf("%d\n", value.a);

    return 0;
}
