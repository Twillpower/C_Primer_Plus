/* enum.c -- 使用枚举类型的值 */
#include <stdio.h>
#include <string.h> // 提供 strcmp()、strchr()函数的原型
#include <stdbool.h>    // C99 特性

char * s_gets(char * st, int n);

enum spectrum { red, orange, yellow, green, blue, violet };
const char *colors [] = { "red", "orange", "yellow", "green", "blue", "violet" };

#define LEN 30

int main(int argc, char const *argv[])
{
    char choice[LEN]; 
    enum spectrum color; 
    bool color_is_found = false; 
    puts("Enter a color (empty line to quit):"); 
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp(choice, colors[color]) == 0)
            {
                color_is_found = true; 
                break;
            }
        }
        if (color_is_found)
            switch (color)
            {
            case red:puts("Roses are red.");
                break;
            case orange: puts("Poppies are orange.");
                break;
            case yellow: puts("Sunflowers are yellow.");
                break;
            case green: puts("Grass is green.");
                break;
            case blue: puts("Bluebells are blue.");
                break;
            case violet: puts("Violets are violet.");
                break;
            default:
                break;
            }
        else
            printf("I don't know about the color %s.\n", choice);
        color_is_found = false;
        puts("Next color, please (empty line to quit):");
    }
    puts("Goodbye!");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    // st: 输入存放位置；n: 输入字符读取长度；
    ret_val = fgets(st, n, stdin);
    if (ret_val)    // 若输入读取成功
    {
        find = strchr(st, '\n');    // 查找换行符
        if(find)        // 如果地址不是NULL，
            *find = '\0';       //将\n替换为\0
        else
            while (getchar() != '\n')   //如果字符串中出现空字符，就丢弃该输入行的其余字符
            {
                continue;
            }      
    }
    return ret_val;
}