/* put_out.c -- 使用 puts() */
// puts()函数只需把字符串的地址作为参数传递给它即可。
// 因为puts()在显示字符串时会自动在其末尾添加一个换行符
// 该函数在遇到空字符时就停止输出
#include <stdio.h>

#define DEF "I am a #defined string."

int main(int argc, char const *argv[])
{
    /* code */
    char str1[80] = "An array was initialized to me.";
    const char * str2 = "A pointer was initialized to me.";
    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2 + 4);

    return 0;
}
