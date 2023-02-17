#include <stdio.h>

int main(void)
{
    /* C99为类型大小提供%zd转换说明 */
    /* C99和C11提供%zd转换说明匹配sizeof的返回类型。
    一些不支持C99和C11的 编译器可用%u或%lu代替%zd */
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n", sizeof(long long));
    printf("Type double has a size of %zd bytes.\n", sizeof(double));
    printf("Type long double has a size of %zd bytes.\n", sizeof(long double));

    return 0;
}