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

    int big = (num > num2) ? num : num2;
    int small = (num > num2) ? num2 : num;

    int sum = 0;
    int count = small;
    do
    {
        sum += count;
        count++;
    } while (count <= big);

    printf("%d以上%d以下の全整数の和は%dです．\n", num, num2, sum);

    return 0;
}