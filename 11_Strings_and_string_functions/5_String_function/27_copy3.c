/* copy3.c -- 使用strncpy() */
#include <stdio.h> 
#include <string.h> /* 提供strncpy()的函数原型*/ 

#define SIZE 40 
#define TARGSIZE 7 
#define LIM 5 

char * s_gets(char * st, int n); 

int main(void) 
{ 
    char qwords[LIM][TARGSIZE]; 
    char temp[SIZE];
    int i = 0;

    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {
            strncpy(qwords[i], temp, TARGSIZE - 1);
            // strncpy()拷贝字符串的长度不 会超过n，如果拷贝到第n个字符时还未拷贝完整个源字符串，
            // 就不会拷贝空 字符。所以，拷贝的副本中不一定有空字符。鉴于此，该程序把 n 设置为比 
            // 目标数组大小少1（TARGSIZE-1），然后把数组最后一个元素设置为空字符：
            qwords[i][TARGSIZE - 1] = '\0';
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++)
        puts(qwords[i]);

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