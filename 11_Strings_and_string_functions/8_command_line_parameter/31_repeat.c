/* repeat.c -- 带参数的 main() */
/* 系统用空格表示一个字符串的结束和下一个字符串的开始 
 * 该程序把命令行字符串储存在内存中，并把每个字符串的地址 
 * 储存在指针数组中。而该数组的地址则被储存在 main()的第 2 个参数中
 * 
 * 把程序本身的名称赋给 argv[0]，然后把随后的第1个字符串赋给argv[1]
 * 
 * char **argv与char *argv[]等价。也就是说，argv是一个指向指针的指
 * 针，它所指向的指针指向 char
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int count;

    // 参数个数包含可执行程序名，所以 -1
    printf("The command line has %d arguments:\n", argc - 1);
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");

    return 0;
}
