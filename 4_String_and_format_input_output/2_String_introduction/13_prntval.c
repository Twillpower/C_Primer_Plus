/* prntval.c -- printf()的返回值 */ 
#include <stdio.h> 
int main(void) 
{ 
    int bph2o = 212; 
    int rv; 

    rv = printf("%d F is water's boiling point.\n", bph2o); 
    // printf()函数也有一个返回值，它返回打印字符的个数
    printf("The printf() function printed %d characters.\n", rv);
    return 0; 
}