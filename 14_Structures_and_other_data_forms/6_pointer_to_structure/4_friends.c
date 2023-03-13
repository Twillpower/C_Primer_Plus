/* friends.c -- 使用指向结构的指针 */
#include <stdio.h> 

#define LEN 20

struct names {  // 第1个结构
    char first[LEN]; 
    char last[LEN];
};

struct guy          // 第2个结构
{
    struct names handle;    // 嵌套结构
    char favfood[LEN]; 
    char job[LEN]; 
    float income;
};

int main(int argc, char const *argv[])
{
    struct guy fellow[2] = {   // 初始化一个结构变量
        { { "Ewen", "Villard" } ,
        "grilled salmon", 
        "personality coach", 
        68112.00
        },
        { { "Rodney", "Swillbelly" }, 
        "tripe", 
        "tabloid editor", 
        432400.00
        }
    };
    
    struct guy *him;   /* 这是一个指向结构的指针 */
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    // 和数组不同的是，结构名并不是结构的地址，因此要在结构名前面加上&运算符
    him = &fellow[0];       /* 告诉编译器该指针指向何处 */

    printf("pointer #1: %p #2: %p\n", him, him + 1); 
    printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);

    him++;      /* 指向下一个结构 */
    printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);  

    return 0;
}
