/* scanf()的*修饰符
 * scanf()中*的用法与此不同(printf)。把*放在%和转换字符之间时，会使得
 * scanf()跳过相应的输出项
*/
/* skiptwo.c -- 跳过输入中的前两个整数 */ 
#include <stdio.h> 

int main(void) 
{ 
    int n; 

    printf("Please enter three integers:\n"); 
    // 跳过两个整数，把第3个整数拷贝给n
    scanf("%*d %*d %d", &n); 
    printf("The last integer was %d\n", n); 

    return 0; 
}