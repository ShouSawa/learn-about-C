#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n;
    printf("実数を入力せよ．:");
    scanf("%d", &n);

    int count = 1;
    while (count <= n)
    {

        if ((count & (count - 1)) == 0)
        {
            printf("%d\n", count);
        }
        count++;
    }
    
    return 0;
}