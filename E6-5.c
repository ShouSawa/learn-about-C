#include<stdio.h>
int sumup(int n){
    //1からnまでの総和を返す
    int tmp = 0;
    for(int i = 1;i<n+1;i++){
        tmp += i;
    }
    return tmp;
}
int main( int argc, char** argv )
{
    int a;
    printf("nを入力：");
    scanf("%d",&a);
    printf("1から%dの総和は%d",a,sumup(a));
    return 0;
}