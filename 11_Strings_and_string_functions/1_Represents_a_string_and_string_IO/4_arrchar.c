// arrchar.c -- 指针数组，字符串数组
#include <stdio.h>

#define SLEN 40
#define LIM 5

int main(int argc, char const *argv[])
{
    const char *mytalents[LIM] = { 
        "Adding numbers swiftly", 
        "Multiplying accurately", 
        "Stashing data", 
        "Following instructions to the letter", 
        "Understanding the C language" 
    };
    char yourtalents[LIM][SLEN] = { 
        "Walking in a straight line",
        "Sleeping", "Watching television", 
        "Mailing letters", "Reading email" 
    };

    int i;

    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");

    for (i = 0; i < LIM; i++)
        printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
    
    /* mytalents中的指针指向初始化时所用的字符串字面量的位置，这些字符 串字面量被储存在静态内存中；
    而 yourtalents 中的数组则储存着字符串字面 量的副本，所以每个字符串都被储存了两次 */
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));

    return 0;
}
