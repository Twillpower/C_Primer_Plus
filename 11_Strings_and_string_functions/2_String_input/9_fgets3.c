/* fgets3.c -- 使用 fgets() */
#include <stdio.h>

#define STLEN 10

int main(int argc, char const *argv[])
{
    char words[STLEN];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0') // 遍历字符串，直至遇到换行符或空字符
            i++;

        // 如果先遇到换行符，下面的if语句就将其替换成空字符
        if (words[i] == '\n')  // 在已储存的字符串中查找换行符，并将其替换成空字符
            words[i] = '\0';
        else // 如果word[i] == '\0'则执行这部分代码
            // 如果目标数组装不下一整行输入，就丢弃那些多出的字符
            // 读取但不储存输入，包括\n
            // 如果先遇到空字符，else部分便丢弃输入行的剩余字符
            while (getchar() != '\n')
                continue;

        puts(words);
    }
    puts("done");

    return 0;
}

/* 空字符（或'\0'）是用于标记C字符串末尾的字符，其对应字符编码是
 * 0。由于其他字符的编码不可能是 0，所以不可能是字符串的一部分。
 * 
 * 空指针（或NULL）有一个值，该值不会与任何数据的有效地址对应。
*/