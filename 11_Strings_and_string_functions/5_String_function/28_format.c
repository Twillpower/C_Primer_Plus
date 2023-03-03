/* format.c -- 格式化字符串 
 * 
 * sprintf()把数据写入字符串，而不是打印在显示器上
 * sprintf()的第1个参数是目标字符串的地址。其余参数和printf()相同，即格式字符串和待写入项的列表
*/
#include <stdio.h>

#define MAX 20

char * s_gets(char * st, int n);

int main(void) 
{ 
    char first[MAX]; 
    char last[MAX]; 
    char formal[2 * MAX + 10]; 
    double prize; 
    
    puts("Enter your first name:"); fgrsg
    s_gets(first, MAX); 
    puts("Enter your last name:");
    s_gets(last, MAX); 
    puts("Enter your prize money:"); 
    scanf("%lf", &prize); 
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts(formal); 
    
    return 0; 
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}