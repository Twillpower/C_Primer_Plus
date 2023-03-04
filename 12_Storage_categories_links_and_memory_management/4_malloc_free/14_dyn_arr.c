/* dyn_arr.c -- 动态分配数组 */
/*  EXIT_SUCCESS（或者，相当于 0）表示普通的程序结束， EXIT_FAILURE 表示程序异常中止
 */
#include <stdio.h>
#include <stdlib.h> /* 为 malloc()、free()提供原型 */

int main(int argc, char const *argv[])
{
	int max;
	double  *ptd;
	int i = 0;
	int num;

	puts("What is the maximum number of type double entries?");
	scanf("%d", &max);
	ptd = (double *)malloc(max * sizeof(double));
	
	if(ptd == NULL)
	{
		puts("Memory allocation failed, Goodbye.");
		exit(EXIT_FAILURE);
	}
    /* ptd 现在指向有max个元素的数组 */
	puts("Enter the values (q to quit):");
	while(i < max && scanf("%lf", &ptd[i]) == 1)
		i++;
	printf("Here are your %d entries.\n", num = i);
	for(i = 0; i < num; i++)
	{
		printf("%7.2f", ptd[i]);
		if(i % 7 == 6)
			putchar('\n');
	}
	if(i % 7 != 0)
		putchar('\n');

	puts("Done");
	
	free(ptd);

	return 0;
}
