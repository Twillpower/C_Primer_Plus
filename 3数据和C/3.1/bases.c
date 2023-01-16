#include <stdio.h>

int main(void)
{
    int x = 100;
    //十进制；八进制；十六进制；
    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);  
    //如果要在八进制和十六进制值前显示0和0x前缀，要分别在转换 说明中加入#
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);  
    return 0;

}