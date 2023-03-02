/* order.c -- 指针运算中的优先级 */
#include <stdio.h>

int data[2] = { 100, 200 };
int moredata[2] = { 300, 400 };

int main(int argc, char const *argv[])
{
    /* code */
    int * p1, *p2, *p3;
    p1 = p2 = data;
    p3 = moredata;

    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n",*p1, *p2, *p3);
    // *p1++ : 先p1++，在*p1，但因为是后++，所以先执行*p1, 然后p1++
    // *(p1++) : 同上
    // *++p2 : 先p2++，在*p2，但因为是前++，所以先执行p2++, 然后*p2
    // *(++p2) : 同上
    // (*p3)++ : 先*p3, 在让*p3这个值++, 指针没有移动
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n",*p1++, *++p2, (*p3)++);
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n",*p1, *p2, *p3);

    return 0;
}
