/* loc_stat.c -- 使用局部静态变量 */
#include <stdio.h>

void trystat(void);

int main(int argc, char const *argv[])
{
    int count;

    for (count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }

    return 0;
}

void trystat(void)
{
    // 每次调用trystat()都会初始化fade，但是stay只在编译 strstat()时被初始化一次。
    // 如果未显式初始化静态变量，它们会被初始化为 0。
    int fade = 1;
    static int stay = 1;

    printf("fade = %d and stay = %d\n", fade++, stay++);
}
