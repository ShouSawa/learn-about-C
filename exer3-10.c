//最初にコピー
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int num, num2, num3;

    puts("三つの実数を入力せよ．");
    printf("整数a:"); scanf("%d", &num);
    printf("整数b:"); scanf("%d", &num2);
    printf("整数c:"); scanf("%d", &num3);

    if(num == num2){
        if(num == num3){
            puts("三つの値が等しいです．");
        }else{
            puts("二つの値が等しいです．");
        }
    }else if(num == num3){
        if(num == num2){
            puts("三つの値が等しいです．");
        }else{
            puts("二つの値が等しいです．");
        }
    }else if(num2 == num3){
        if(num == num2){
            puts("三つの値が等しいです．");
        }else{
            puts("二つの値が等しいです．");
        }
    }else{
        puts("三つの値は異なります．");
    }

    return 0;
}
