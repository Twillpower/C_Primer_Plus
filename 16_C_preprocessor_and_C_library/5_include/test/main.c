#include "main.h"
#include "up.h"

int count = 0;

int main(int argc, char const *argv[])
{
    while (1)
    {
        up();
        printf("count = %d\n", count);
        sleep(1);
    }
    

    return 0;
}
