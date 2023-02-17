#include <stdio.h>

int main(void)
{
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;

	printf("un = %u and not %d\n", un, un);
    //%hd: short类型短整型(在给函数传递参数时，C编译器把short类型的值自动转换成int类型的值)
	printf("end = %hd and %d\n", end, end);
    //%ld: long类型整型(%hd：printf()只显示了储存在后16位的值)
	printf("big = %ld and not %hd\n", big, big);
    //%lld: long long类型整型(%ld：printf()只显示了储存在后32位的值)
	printf("verybig = %lld and not %ld\n", verybig, verybig);

	return 0;
}
