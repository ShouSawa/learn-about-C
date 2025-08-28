#include<stdio.h>
int min2(int a,int b){
    //aとbの小さいほうを返す
    return a<b ? a:b;
}
int main( int argc, char** argv )
{
    int a,b;
    printf("aを入力");
    scanf("%d",&a);
    printf("bを入力");
    scanf("%d",&b);
    printf("小さい値は%d\n",min2(a,b));
    return 0;
}