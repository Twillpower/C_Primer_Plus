/* width.c -- 字段宽度 */ 
#include <stdio.h>
#define PAGES 959 
int main(void) 
{ 
    printf("*%d*\n", PAGES); 
    // 其对应的输出结果应该是 2 字段宽度。因为待打印的整数有 3 位数字，所以字段宽度自动扩大以符 合整数的长度
    printf("*%2d*\n", PAGES); 
    // 其对应的输出结果有10个空格宽度，实际上在两个星号之间有7个空格和3位数字，并且数字位于字段的右侧
    printf("*%10d*\n", PAGES); 
    // 其对应的输出结果同样是 10 个空格宽度，-标记说明打印的数字位于字段的左侧
    printf("*%-10d*\n", PAGES); 

    return 0; 
}