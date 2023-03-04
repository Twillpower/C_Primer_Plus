/* hello.c -- 把命令行参数转换为数字 */
/* atoi()函数（用于把字母数字转换成整数）
 * 该函数接受一个字符串作为参数，返回相应的整数值
 * 
 * atoi函数在遇到非整数部分之前一直转换字符
 * 如果命令行参数不是数字，atoi()函数 返回0
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, times;

    if (argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usage: %s positive-number\n", argv[0]);
    else 
        for (i = 0; i < times; i++)
            puts("Hello, good looking!");

    return 0;
}
