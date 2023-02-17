/* printf()的*修饰符
 * 不想预先指定字段宽度，希望通过程序来指定, 那么可以用*修饰符代替字段宽度
 * 如果转换说明是%*d，那么参数列表中应包含*和 d对应的值
*/
/* varwid.c -- 使用变宽输出字段 */ 
#include <stdio.h> 
int main(void) 
{ 
    unsigned width, precision; 
    int number = 256;
    double weight = 242.5; 

    printf("Enter a field width:\n"); 
    scanf("%d", &width); 
    printf("The number is :%*d:\n", width, number); 
    printf("Now enter a width and a precision:\n"); 
    scanf("%d %d", &width, &precision); 
    printf("Weight = %*.*f\n", width, precision, weight); 
    printf("Done!\n"); 

    return 0; 
}