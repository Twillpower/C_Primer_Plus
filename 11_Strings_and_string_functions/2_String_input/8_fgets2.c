/* fputs()函数返回指向 char的指针
 * 如果一切进行顺利，该函数返回的地
 * 址与传入的第 1 个参数相同。但是，如果函数读到文件结尾，
 * 它将返回一个 特殊的指针：空指针（null pointer）。
 * 该指针保证不会指向有效的数据，所以可用于标识这种特殊情况
*/
/* fgets2.c -- 使用 fgets() 和 fputs() */
#include <stdio.h>

#define STLEN 10

int main(int argc, char const *argv[])
{
    char words[STLEN];

    puts("Enter strings (empty line to quit):");

    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    
    puts("Done.");

    return 0;
}
/* 输入By the way, the gets() function
 * 程序中的fgets()一次读入 STLEN - 1 个字符（该例中为 9 个字符）。
 * 所以，一开始它只读入了“By the wa”，并储存为By the wa\0；接着 fputs()打印该字符串，
 * 而且并未换行。然后while循环进入下一轮迭代， fgets()继续从剩余的输入中读入数据，
 * 即读入“y, the ge”并储存为y, the ge\0； 
 * 接着fputs()在刚才打印字符串的这一行接着打印第 2 次读入的字符串。然后 while 进入下一轮迭代，
 * fgets()继续读取输入、fputs()打印字符串，这一过程 循环进行，直到读入最后的“tion\n”。
 * fgets()将其储存为tion\n\0， fputs()打印 该字符串，由于字符串中的\n，光标被移至下一行开始处。
 *
*/