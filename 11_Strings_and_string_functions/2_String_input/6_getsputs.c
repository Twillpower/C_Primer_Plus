/* getsputs.c -- 使用 gets() 和 puts() 
 * 
 * gets()函数简单易用，它读取整行输入，直至遇到换行符，然后丢弃换行符，
 * 储存其余字符，并在这些字符的末尾添加一个空字符使其成为一个 C 字符串。
 * 它经常和 puts()函数配对使用，该函数用于显示字符串，并在末尾添加换行符。
 * 
 * gets()唯一的参数是 words，它无法检查数组是否装得下输入行
 * 数组名会被转换成该数组首元素的地址，因此，gets()函数只知道数组的开始处，并不知道数组中有多少个元素。
 * 如果输入的字符串过长，会导致缓冲区溢出（buffer overflow），
 * 即多余的字符超出了指定的目标空间。如果这些多余的字符只是占用了尚未使用 的内存，
 * 就不会立即出现问题；如果它们擦写掉程序中的其他数据，会导致程序异常中止
 */
#include <stdio.h>

#define STLEN 81

int main(int argc, char const *argv[])
{
    char words[STLEN];
    puts("Enter a string, please.");
    gets(words);    // 典型用法
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

    return 0;
}
