#include<stdio.h>
int cube(int x){
    //xの3乗を返す
    return x*x*x;
}
int main( int argc, char** argv )
{
    int a;
    printf("3乗にしたい数字を入力：");
    scanf("%d",&a);
    printf("3乗は%d\n",cube(a));
    return 0;
}