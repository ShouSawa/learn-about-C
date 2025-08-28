#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void kuku(int m[10][10]){
    for(int i = 0; i <= 9; i++){
	for(int j = 0; j <= 9; j++){
	    m[i][j] = i * j;
	}
    }
}
    
int main(void)
{
    int m[10][10];
    kuku(m);
    for(int i = 1; i <= 9; i++){
	for(int j = 1; j <= 9; j++){
	    printf("%2d ",m[i][j]);
	}
	printf("\n");
    }

    return 0;
}
