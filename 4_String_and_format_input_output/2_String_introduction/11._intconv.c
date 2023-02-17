/* intconv.c -- 一些不匹配的整型转换 */ 
#include <stdio.h> 
#define PAGES 336 
#define WORDS 65618 

int main(void) 
{ 
    short num = PAGES; 
    short mnum = -PAGES; 

    printf("num as short and unsigned short: %hd %hu\n", num,num); 
    // 有符号short int的大小是2字节,系统使用二进制补码来表示有符号整数
    // 数字0～32767代 表它们本身，而数字32768～65535则表示负数。
    // 其中，65535表示-1，65534 表示-2，以此类推。因此，-336表示为65200（即， 65536-336）
    // 所以被解释成有符号int时，65200代表-336；而被解释成无符号int时，65200则代表 65200
    printf("-num as short and unsigned short: %hd %hu\n", mnum,mnum); 
    // short int是2字节，char是1字节。当printf()使用%c打印336时，它只会查看储存336的2字节中的后1字节
    // 这种截断（见图4.8）相当于用一 个整数除以256，只保留其余数。
    // 在这种情况下，余数是80，对应的ASCII值是字符P
    printf("num as int and char: %d %c\n", num, num); 
    printf("WORDS as int, short, and char: %d %hd %c\n",WORDS,WORDS, WORDS); 

    return 0; 
}