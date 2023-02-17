#include <stdio.h>
#define PRAISE "You are an extraordinary being."

/* scanf()
 * 在遇到第1个空白（空格、制表符或换行符）时就不再读取输入
*/

int main(int argc, char const *argv[])
{   
    /* code */
    char name[40];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);

    return 0;
}
