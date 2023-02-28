// cypher2.c -- 替换输入的字母，非字母字符保持不变
#include <stdio.h> 
#include <ctype.h>  // 包含isalpha()的函数原型

#define SPACE ' '   // SPACE表示单引号-空格-单引号

int main(void) 
{ 
    char ch; 
    
    while ((ch = getchar()) != '\n')   // 当一行未结束时
    { 
        if (isalpha(ch))    // 如果是一个字符，
            putchar(ch + 1);     // 显示该字符的下一个字符
        else 
            putchar(ch);    // 原样显示
    }   

    putchar(ch);    // 打印换行符

    return 0; 
}

