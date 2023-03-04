/* r_drive1.c -- 测试 rand1() 和 srand1() */
/* 与 s_and_r.c 一起编译 */
/* time()函数返回系统时间
 * time()返回值的类型名是time_t
 * time()接受的参数是一个 time_t 类型对象的地址，
 * 而时间值就储存在传入的地址上。当然，也可以传入空指针（0）作为参数，
 * 这种情况下，只能通过返回值机制来提供值。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* 提供time()的ANSI原型*/

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
    int count; 
    printf("Please enter your choice for seed.\n"); 

    srand1((unsigned int) time(0)); /* 初始化种子 */
    for (count = 0; count < 5; count++)
        printf("%d\n", rand1());
    printf("Please enter next seed (q to quit):\n");

    printf("Done\n");
    return 0;
}