/* names2.c -- 传递并返回结构 */
#include <stdio.h> 
#include <string.h>

#define NLEN 30 

struct namect { 
    char fname[NLEN]; 
    char lname[NLEN]; 
    int letters; 
}; 

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);
char *s_gets(char * st, int n); 

int main(void) { 

    struct namect person; 

    person = getinfo(); 
    person = makeinfo(person); 
    showinfo(person);

    return 0; 
} 

struct namect getinfo(void) {
    struct namect temp; 

    printf("Please enter your first name.\n"); 
    s_gets(temp.fname, NLEN); 
    printf("Please enter your last name.\n"); 
    s_gets(temp.lname, NLEN); 
    
    return temp;
} 

struct namect makeinfo(struct namect info) { 
    info.letters = strlen(info.fname) + strlen(info.lname);
    return info;
} 

void showinfo(struct namect info) { 
    printf("%s %s, your name contains %d letters.\n", info.fname, info.lname, info.letters);
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