/* copy2.c -- 使用 strcpy() 
 * 
 * 第一，strcpy()的返回类型是 char *，
 * 该函数返回的是第 1个参数的值，即一个字符的地址。
 * 
 * 第二，第 1 个参数不必指向数组的开始。
*/
#include <stdio.h> 
#include <string.h> // 提供strcpy()的函数原型

#define WORDS "beast" 
#define SIZE 40 

int main(void)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;
    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);

    return 0;
}