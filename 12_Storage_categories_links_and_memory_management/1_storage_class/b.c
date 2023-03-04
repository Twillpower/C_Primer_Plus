#include <stdio.h>
#include "b.h"

extern int times;

void loop(void)
{
    int i = 0;
    for(i = 0; i < times; i++)
        printf("%d ", i);
}