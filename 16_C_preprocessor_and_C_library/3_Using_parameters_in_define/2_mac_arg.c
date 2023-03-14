/* mac_arg.c -- 带参数的宏 */
#include <stdio.h> 

#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n", X)

int main(int argc, char const *argv[])
{
    int x = 5;
    int z;
    printf("x = %d\n", x); 
    z = SQUARE(x); 
    printf("Evaluating SQUARE(x): "); 
    PR(z); 
    z = SQUARE(2); 
    printf("Evaluating SQUARE(2): "); 
    PR(z); 
    printf("Evaluating SQUARE(x+2): "); 
    PR(SQUARE(x + 2));  // SQUARE(x+2) --> x+2*x+2 -> 5+2*5+2 = 17
    printf("Evaluating 100/SQUARE(2): "); 
    PR(100 / SQUARE(2));  // 100/SQUARE(2) -> 100/2*2 = 100
    printf("x is %d.\n", x); 
    printf("Evaluating SQUARE(++x): "); 
    PR(SQUARE(++x));  // 不要在宏中使用递增或递减运算符，结果不确定
    printf("After incrementing, x is %x.\n", x);

    return 0;
}
