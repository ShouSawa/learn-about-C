#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int num, num2;
    puts("二つの実数を入力せよ．");
    printf("整数a:");
    scanf("%d", &num);
    printf("整数b:");
    scanf("%d", &num2);

    if (abs(num - num2) <= 10)
    {
        puts("それらの差は10以下です．");
    }
    else
    {
        puts("それらの差は11以上です．");
    }

    return 0;
}