#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5

//４行3列2の行列aとbの和を行列cに格納する
void mat_add(const int a[2][4][3], int c[4][3]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = a[0][i][j] + a[1][i][j];
        }
    }
}

//4行3列2の行列mを表示
void mat_print2(const int m[2][4][3]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            printf("%4d ",m[0][i][j]);
        }
	    printf("\n");
    }
    printf("\n");

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            printf("%4d ",m[1][i][j]);
        }
	    printf("\n");
    }
}

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
    int a[2][4][3] = {{ {1,2,3},{4,5,6},{7,8,9},{10,11,12} },
                      { {1,2,3},{5,6,7},{9,10,11},{12,13,14} }};
    int c[4][3];

    mat_add(a, c);
    
    puts("aの配列"); mat_print2(a);
    puts("cの配列"); mat_print(c);
    
    return 0;
}