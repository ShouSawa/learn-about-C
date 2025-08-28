#include<stdio.h>
int spr(int x){
    //2乗を返す関数
    return x*x;
}
int pow4(int x){
    //2乗を返す関数を使って4乗を返す
    return spr(x)*spr(x);
}
int main( int argc, char** argv )
{
    int a = 3;
    printf("4乗は%d\n",pow4(a));
    return 0;
}