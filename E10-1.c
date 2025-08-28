#include<stdio.h>
//100より大きいなら100に，0より小さいなら0に
void adjust_point(int *n){
    int tmp = *n < 0 ? 0 : *n;
    tmp = tmp > 100 ? 100 : tmp;
    *n = tmp;
}
int main( int argc, char** argv )
{
    int x;
    scanf("%d",&x);
    adjust_point(&x);
    printf("%d\n",x);
    return 0;
}