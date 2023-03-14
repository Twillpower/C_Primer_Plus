#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    const int a = 10;

    printf(" a = %d\n", a);

    for (i = 0; i < 10; i++)
    {
        const int a = 20;
        printf(" a = %d\n", a);
    }
    printf(" a = %d\n", a);
    

    return 0;
}
