/* mod_str.c -- 修改字符串 */
/* 利用toupper()函数处理字符串中的每个字符，把整个字符 串转换成大写；
 * 利用 ispunct()统计字符串中的标 点符号个数
 * 使用strchr()处理fgets()读入字符串的换行符
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIMIT 81

void ToUpper(char *);
int PunctCount(const char *);

int main(void)
{
    char line[LIMIT]; 
    char * find; 

    puts("Please enter a line:"); 
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n'); // 查找换行符
    if (find)   // 如果地址不是 NULL，
        *find = '\0';   // 用空字符替换
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));

    return 0;
}

void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

int PunctCount(const char * str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str)) // 若为标点符号，则返回true
            ct++; 
        str++;
    }
    return ct;
}