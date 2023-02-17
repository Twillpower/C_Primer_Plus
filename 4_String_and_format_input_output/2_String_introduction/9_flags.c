/* flags.c -- 演示一些格式标记 */ 
#include <stdio.h> 
int main(void) 
{ 
    // 具体说明查看readme.md
    printf("%x %X %#x\n", 31, 31, 31); 
    printf("**%d**% d**% d**\n", 42, 42, -42); 
    // 如果0标记和精度一起出现，0标记会被 忽略
    printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6); 

    return 0; 
}