#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #define NUMBER 5

int main(void)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        int r = rand();
        printf("%d\n", r);
    }

    return 0;
    /*
    //srandomdev();
    int num;

    num = rand();
    printf("%d",num);

    return 0;
    */
}
