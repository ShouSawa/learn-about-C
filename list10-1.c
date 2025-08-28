#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#define NUMBER 5

void sum_diff(int n1, int n2, int *sum, int *diff)
{
    *sum = n1 + n2;
    *diff = n1 > n2 ? n1 - n2 : n2 - n1;
}
    
int main(void)
{
    int a, b;
    int wa = 0, sa = 0;

    puts("２つの実数を入力せよ。");
    printf("整数A:"); scanf("%d", &a);
    printf("整数B:"); scanf("%d", &b);

    sum_diff(a, b, &wa, &sa);

    printf("和は%dで差は%dです。\n",wa ,sa);

    return 0;
}
