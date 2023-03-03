/* nono.c -- 千万不要模仿！ */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char side_a[] = "Side A";
    char dont[] = { 'W', 'O', 'W', '!' };
    char side_b[] = "Side B";
    // puts函数在遇到空字符时就停止输出
    puts(dont); /* dont 不是一个字符串 */

    return 0;
}
