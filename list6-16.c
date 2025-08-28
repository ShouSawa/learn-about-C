#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5

//４行3列の行列aとbの和を行列cに格納する
void mat_add(const int a[4][3], const int b[4][3], int c[4][3]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

//4行3列の行列mを表示
void mat_print(const int m[4][3]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            printf("%4d ",m[i][j]);
        }
	    printf("\n");
    }
}

int main(void)
{
    int a[4][3] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
    int b[4][3] = { {1,2,3},{5,6,7},{9,10,11},{12,13,14} };
    int c[4][3];

    mat_add(a, b, c);
    
    puts("aの配列"); mat_print(a);
    puts("bの配列"); mat_print(b);
    puts("cの配列"); mat_print(c);
    
    return 0;
}