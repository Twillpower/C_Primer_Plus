/* strcnvt.c -- 使用 strtol() */
/* atol()函数把字符串转换成long类型的值。atof()和atol()的工作原理和atoi()类似，
 * 因此它们分别返回double类型 和long类型。
 * 
 * strtol()把字符串转换成long类型的值，
 * strtoul()把字符串转换成unsigned long类型的值，strtod()把字符串转换成 double类型的值
 * 
 * long strtol(const char * restrict nptr, char ** restrict endptr, int base);
 * nptr是指向待转换字符串的指针，endptr是一个指针的地址，该
 * 指针被设置为标识输入数字结束字符的地址，base表示以什么进制写入数字。
*/
#include <stdio.h> 
#include <stdlib.h> 

#define LIM 30 
char * s_gets(char * st, int n); 

int main()
{
    char number[LIM];
    char * end; 
    long value; 
    
    puts("Enter a number (empty line to quit):");
    while (s_gets(number, LIM) && number[0] != '\0')
    {
        value = strtol(number, &end, 10);  /* 十进制 */
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        value = strtol(number, &end, 16); /* 十六进制 */
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);
        puts("Next number:");
    }
    puts("Bye!\n");
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}