#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    const double ANSWER = 3.14159;
    double response;

    printf("What is the value of pi?\n");
    scanf("%lf", &response);

    while (fabs(response - ANSWER) > 0.0001)  //fabs()：绝对值
    {
        /* code */
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");

    return 0;
}
