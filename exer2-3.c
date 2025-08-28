/* 05input.c 入力 */
#include <stdio.h>

int main(void)
{
	double month;

	printf("実数を入力せよう: ");
	scanf("%lf", &month);

	printf("あなたは%fと入力しましたね\n", month);

	return 0;
}