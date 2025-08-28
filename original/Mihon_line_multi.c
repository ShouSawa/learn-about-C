#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5

int main(void)
{
    int line1[4][3];
    int line2[3][4];
    int sum[4][4] = {0};

    FILE *fp1;
    if ( (fp1 = fopen("line1_sample.dat", "r") ) == NULL ){
        perror("line1_sample.dat");
        exit(1);
    }
    FILE *fp2;
    if ( (fp2 = fopen("line2_sample.dat", "r") ) == NULL ){
        perror("line2_sample.dat");
        exit(1);
    }

    //line1の読み込み
    puts("line1");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j< 3; j++){
            fscanf(fp1, "%d", &line1[i][j]);
            printf("%d ",line1[i][j]);
        }   
        putchar('\n'); //改行
    }

    putchar('\n'); //改行
    puts("line2");
    //line2の読み込み
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 4; j++){
            fscanf(fp2, "%d", &line2[i][j]);
            printf("%d ",line2[i][j]);
        }   
        putchar('\n'); //改行
    }

/*手動で入力
    //line1の読み込み
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            printf("line1, %d行%d列目:",i+1,j+1); scanf("%d", &line1[i][j]);
        }
    }

    //line2の読み込み
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("line2, %d行%d列目:",i+1,j+1); scanf("%d", &line2[i][j]);
        }
    }
*/

    //a*b行列　* c*d行列 = a*d行列
    //行列の計算
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 3; k++){
                sum[i][j] += line1[i][k] * line2[k][j];
            }       
        }
    }

    //結果の表示
    putchar('\n'); //改行
    puts("sum");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ",sum[i][j]);
        }
        putchar('\n'); //改行
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
