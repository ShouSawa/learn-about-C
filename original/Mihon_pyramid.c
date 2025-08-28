#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int n;
    puts("ピラミッドを作ります．");
    printf("何段ですか:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        for (int m = 0; m < 3; m++){
            for (int j = i; j < n; j++){
                    printf(" ");
                }
            for (int k = 0; k < 2*i-1; k++){
                    printf("*");
                }
            for (int l = i; l < n; l++){
                    printf(" ");
                }
        }
        putchar('\n'); // 改行
    }

    return 0;
}