#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5

void mat_mul(const int a[4][3], const int b[3][4], int c[4][4]){

    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
	    c[i][j] = 0;
            for (int k = 0; k < 3; k++){
               c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\ncの配列\n");
    for(int i = 0; i < 4; i++){
	for(int j = 0; j < 4; j++){
	    printf("%d ",c[i][j]);
	}
	printf("\n");
    }
    
}

int main(void)
{
    int a[4][3] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };
    int b[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    int c[4][4];

    printf("aの配列\n");
    for(int i = 0; i < 4; i++){
	for(int j = 0; j < 3; j++){
	    printf("%2d ",a[i][j]);
	}
	printf("\n");
    }

    printf("\n");
    printf("bの配列\n");
    for(int i = 0; i < 3; i++){
	for(int j = 0; j < 4; j++){
	    printf("%2d ",b[i][j]);
	}
	printf("\n");
    }

    mat_mul(a, b, c);
    
    return 0;
}
