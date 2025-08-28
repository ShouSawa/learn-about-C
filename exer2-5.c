#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int num, num2;

    puts("二つの整数を入力せよ．");
    printf("整数a:", num);
    scanf("%d", &num); // intの入力
    printf("整数b:", num2);
    scanf("%d", &num2); // intの入力

    printf("aの値はbの値の%f％です．\n", (double)num / (double)num2 * 100);

    return 0;
}