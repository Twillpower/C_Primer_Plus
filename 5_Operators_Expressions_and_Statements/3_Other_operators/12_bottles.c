#include <stdio.h> 

#define MAX 100 

int main(void)
{ 
    int count = MAX + 1; 
    int num = 20;

    while (--count > 0) 
    { 
        printf("%d bottles of spring water on the wall, " "%d bottles of spring water!\n", count, count); 
        printf("Take one down and pass it around,\n"); 
        printf("%d bottles of spring water!\n\n", count - 1); 
    }

    //当 printf()获取待打印的值时，可能先对最后一个参数（ ） 求值，这样在获取其他参数的值之前就递增了num。
    while (num < 21) { printf("%10d %10d\n", num, num*num++); }

    return 0; 
}