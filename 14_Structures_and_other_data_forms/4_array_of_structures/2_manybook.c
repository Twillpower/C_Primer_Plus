/* manybook.c -- 包含多本书的图书目录 */
#include <stdio.h>
#include <string.h>

char * s_gets(char * st, int n);

#define MAXTITL 40 
#define MAXAUTL 40
#define MAXBKS 100  /* 书籍的最大数量 */

struct book         /* 简历 book 模板 */
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(int argc, char const *argv[])
{
    struct book library[MAXBKS];    /* book 类型结构的数组 */
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0]!='\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;       /* 清理输入行*/
        if(count < MAXBKS)
            printf("Enter the next title.\n");
        if(count > 0)
        {
            printf("Here is the list of your books:\n");
            for (index = 0; index < count; index++)
                printf("%s by %s: $%.2f\n", library[index].title,library[index].author, library[index].value);
        }
        else
            printf("No books? Too bad.\n");
    }  

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