/* C11标准新增的gets_s()函数也可代替gets()。
 * 该函数与 gets()函数更接近，而且可以替换现有代码中的gets()。
 * 但是，它是stdio.h输入/输出函数系列中的可选扩展，所以支持C11的编译器也不一定支持它
 * 
 * fgets()函数通过第2个参数限制读入的字符数来解决溢出的问题。
 * 该函数专门设计用于处理文件输入，所以一般情况下可能不太好用
 * 
 * fgets()函数的第2个参数指明了读入字符的最大数量。如果该参数的值
 * 是n，那么fgets()将读入n-1个字符，或者读到遇到的第一个换行符为止
 * 
 * fgets()读到一个换行符，会把它储存在字符串中
 * 
 * fgets()函数的第3 个参数指明要读入的文件。如果读入从键盘输入的数据，
 * 则以stdin（标准输入）作为参数，该标识符定义在stdio.h中
 * 
 * fgets()函数把换行符放在字符串的末尾（假设输入行不溢出），
 * 通常要与 fputs()函数（和puts()类似）配对使用，除非该函数不在字符串末尾添加换行符。
 * 
 * fputs()函数的第2个参数指明它要写入的文件。
 * 如果要显示在计算机显示器上，应使用stdout（标准输出）作为该参数
 * 
 * puts()函数会在待输出字符串末尾添加一个换行符，而fputs()不会这样做
*/
/* fgets1.c -- 使用 fgets() 和 fputs() */
#include <stdio.h>

#define STLEN 14

int main(int argc, char const *argv[])
{
    char words[STLEN];

    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");

    return 0;
}
