/* names1.c -- 使用指向结构的指针 */
#include <stdio.h> 
#include <string.h>

#define NLEN 30 

struct namect { 
    char fname[NLEN]; 
    char lname[NLEN]; 
    int letters; 
}; 

void getinfo(struct namect *); 
void makeinfo(struct namect *); 
void showinfo(const struct namect *); 
char *s_gets(char * st, int n); 

int main(void) { 
    struct namect person; 

    getinfo(&person); 
    makeinfo(&person); 
    showinfo(&person);

    return 0; 
} 

void getinfo(struct namect * pst) { 
    printf("Please enter your first name.\n"); 
    s_gets(pst->fname, NLEN); 
    printf("Please enter your last name.\n"); 
    s_gets(pst->lname, NLEN); 
} 

void makeinfo(struct namect * pst) { 
    pst->letters = strlen(pst->fname) +strlen(pst->lname); 
} 

void showinfo(const struct namect * pst) { 
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters); 
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