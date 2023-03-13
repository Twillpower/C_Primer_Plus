#include <stdio.h>
#include <string.h>

char *s_gets(char *st, int n);

#define MAXTITL 41      /* 书名的最大长度 + 1 */
#define MAXAUTL 31      /* 作者姓名的最大长度 + 1*/

struct book     /* 结构模版：标记是 book */
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};      /* 结构模版结束 */

int main(int argc, char const *argv[])
{
    struct book library;    /* 把 library 声明为一个 book 类型的变量 */

    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);     /* 访问title部分*/ 
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);
    printf("%s by %s: &%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\"($%.2f)\n", library.author, library.title, library.value);
    printf("Done.\n");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    // st: 输入存放位置；n: 输入字符读取长度；
    ret_val = fgets(st, n, stdin);
    if (ret_val)    // 若输入读取成功
    {
        find = strchr(st, '\n');    // 查找换行符
        if(find)        // 如果地址不是NULL，
            *find = '\0';       //将\n替换为\0
        else
            while (getchar() != '\n')   //如果字符串中出现空字符，就丢弃该输入行的其余字符
            {
                continue;
            }      
    }
    return ret_val;
}
