#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#define NUMBER 5

double ave(const int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
	sum += a[i];
    }
    printf("%d",sum);
    double ave = (double)sum / (double)(n-1);
    return ave;
}

int main(int argc, char **argv)
{
    int i;
    int a[100] = {0};
    for ( i = 0; i < argc; i++ ){
	if(argc >= 100){
	    puts("引数が多過ぎます。");
	    break;
	}
	a[i] = atoi(argv[i]);
    }
    
    printf("平均値は%.2fです。\n", ave(a, argc));
    
    return 0;
}
