/* convert.c -- 自动类型转换 */ 
#include <stdio.h> 

int main(void) 
{ 
    char ch; 
    int i;
    float fl; 
    fl = i = ch = 'C';  /* 第9行 */
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); 
    ch = ch + 1;   // ch == 'D'; 'D' == char(68)
    i = fl + 2 * ch;   // 67.00 + 2*68 = 203.00 ; int(203.00) == 203
    fl = 2.0 * ch + i;  // 2.0 * 68 + 203.00 = 339.00; 
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl); 
    ch = 1107;   // 1107二进制低八位为ASCII码为'S',下同
    printf("Now ch = %c\n", ch); 
    ch = 80.89; 
    printf("Now ch = %c\n", ch);
    return 0; 
}