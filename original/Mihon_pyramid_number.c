#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5;

int main(void){
    int n;
    puts("ピラミッドを作ります．");
    printf("何段ですか:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        for (int m = 0; m < 3; m++){
            for (int j = i; j > 1; j--){
                    printf(" ");
                }
            for (int k = i*2-1; k < n*2; k++){
                    printf("%d",i % 10);
                }
            for (int l = i; l > 1; l--){
                    printf(" ");
                }
        }
        putchar('\n'); // 改行
    }

    return 0;
}