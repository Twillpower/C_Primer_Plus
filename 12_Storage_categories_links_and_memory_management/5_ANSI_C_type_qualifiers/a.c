#include <stdio.h>
#include "const.h"

extern void loop(void);

int main(int argc, char const *argv[])
{
    printf("%f\n", PI);
    loop();

    return 0;
}
