// designate.c -- 使用指定初始化器
#include <stdio.h>

#define MONTHS 12

int main(int argc, char const *argv[])
{
    // C99规定，可以在初始化列表中使用带方括号的下标指明待初始化的元素：
    int days[MONTHS] = { 31, 28, [4] = 31, 30, 31, [1] = 29 };
    int i;
    for (i = 0; i < MONTHS; i++)
        printf("%2d %d\n", i, days[i]);

    return 0;
}
