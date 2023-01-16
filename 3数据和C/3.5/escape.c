#include <stdio.h>

int main(void)
{
    float salary;

    printf("\aEnter your desired monthly salary:");
    printf(" $_______\b\b\b\b\b\b\b");  // \b: 退格
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12.0);  // \t: 水平制表符
    printf("\rGee!\n");  // 以\r开始。这使得光标回到当前行的起始处

    return 0;
}