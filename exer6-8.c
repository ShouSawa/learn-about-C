#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUMBER 5

//--- 要素数nの配列vの最小値を返す ---//
int min_of(int v[], int n)
{
    int min = v[0];

    for(int i = 1; i < n; i++)
	if (v[i] < min)
	    min = v[i];

    return min;
}

int main(int argc, char **argv)
{
    FILE *fp;
    int n;

    if (( fp = fopen( argv[1], "r" ) ) == NULL) {
	perror( argv[1] );
	exit( 1 );
    }

    int count = 0;
    int num[99];
    while ( fscanf( fp, "%d", &n ) != EOF ) {
	num[count] = n;
	printf("%d\n",num[count]);
	count++;
    }

    int a = min_of(num, count);
    printf("最小値は%d\n",a);                  
    return 0;
}
    
