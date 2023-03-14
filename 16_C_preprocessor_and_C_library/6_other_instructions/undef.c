#include "undef.h"

int main(int argc, char const *argv[])
{
    int a = SIZE;
    printf("a = %d\n", a);

    #undef SIZE
    #define SIZE 20 
    a = SIZE;
    printf("a = %d\n", a);
        
    return 0;
}
