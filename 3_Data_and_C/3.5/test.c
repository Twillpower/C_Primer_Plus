#include <stdio.h>

int main(void)
{
    // C编译器把浮点数转换成整数时，会直接丢弃（截断）小数部分
    int cost = 12.99;
    float pi = 3.1415926;

    printf("cost is %d\n", cost);
    printf("pi is %f\n", pi);

    return 0;
}