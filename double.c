#include<stdio.h>
#include<stdlib.h>
void twice(int list[],int tmp){
    for (int i = 0; i < tmp; i++) {
        list[i] = list[i] * 2;
    }
}
int main( int argc, char** argv )
{
    int tmp = 0;
    int arr[100];
    char list[100];
    FILE *f = fopen(argv[1],"r");
    if( f == NULL ){
    	printf("ファイルが開けません。");
    } else {
    	// ファイルの読み込み処理
        while( fgets(list,1000,f) != NULL){
            arr[tmp] = atoi(list);
            tmp++;
        }
    }
    fclose(f);
    for (int i = 0; i < tmp; i++) {
        printf("%d\n", arr[i]);
    }
    twice(arr,tmp);
    for (int i = 0; i < tmp; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}