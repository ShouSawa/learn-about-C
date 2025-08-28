#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMBER 120

int main(void)
{
    int n;
    int tensu[15]; // 15はNUMBERにしちゃだめかも？
    int bunpu[11] = {0};

    FILE *fp;

    if ((fp = fopen("sample.dat", "r")) == NULL){
        perror("sample.dat");
        exit(1);
    }

    printf("人数を入力せよ:");
    do{
        scanf("%d", &n);
        if (n < 1 || n > NUMBER){
            printf("0~%dの間で入力せよ:", NUMBER);
        }
    } while (n < 1 || n > NUMBER);

    for (int i = 0; i < n; i++){
        fscanf(fp, "%d", &tensu[i]);
        printf("%2d番の点数：%3d点\n",i+1,tensu[i]);
        bunpu[tensu[i] / 10]++;
    }

/*自分で入力するパターン
    printf("%d人の点数を入力せよ\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%2d番:", i + 1);
        do
        {
            scanf("%d", &tensu[i]);
            if (tensu[i] > 100 || tensu[i] < 0)
            {
                printf("0~100で入力せよ:");
            }
        } while (tensu[i] > 100 || tensu[i] < 0);
        bunpu[tensu[i] / 10]++;
    }
    putchar('\n'); // 改行
*/
    putchar('\n'); // 改行
    puts("---分布グラフ(縦)---");
    printf("      100 : ");
    for (int k = 0; k < bunpu[10]; k++){
        printf("*");
    }
    putchar('\n'); // 改行

    for (int j = 9; j >= 0; j--){
        printf("%3d ~ %3d : ", j * 10, j * 10 + 9);
        for (int k = 0; k < bunpu[j]; k++){
            printf("*");
        }
        putchar('\n'); // 改行
    }

    putchar('\n'); // 改行
    puts("---分布グラフ(横)---");

    int max = bunpu[0];
    for (int m = 1; m < 11; m++){
        if(bunpu[m] > max){
            max = bunpu[m];
        }
    }   

    for (int i = max; i > 0; i--){
        for (int j = 0; j < 11; j++){
            if(bunpu[j] >= i){
                printf(" * ");
            }else{
                printf("   ");
            }
        }
        putchar('\n'); // 改行
    }
    puts("----------------------------------");
    puts(" 0 10 20 30 40 50 60 70 80 90 100");

    fclose(fp);
    return 0;
}