#include <stdio.h>
#include <string.h> /* 提供strlen()函数的原型 */

#define PRAISE "You are an extraordinary being." 
// const关键字，用于限定一个变量为只读
const int MONTH = 12;

int main(void) 
{ 
    char name[40]; 

    printf("What's your name? \n"); 
    scanf("%s", name); 
    printf("Hello, %s.%s\n", name, PRAISE); 
    printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof name); 
    printf("The phrase of praise has %zd letters ", strlen(PRAISE)); 
    printf("and occupies %zd memory cells.\n", sizeof PRAISE); 

    return 0; 
}