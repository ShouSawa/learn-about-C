#include<stdio.h>
int min3(int a,int b,int c){
    int tmp;
    //aとbの小さい方をtmp
    tmp = a<b ? a:b;
    //tmpとcの小さいほうをreturn
    return tmp < c ? tmp:c;
}
int main( int argc, char** argv )
{
    int in[3];
    printf("3つの数字を入力\n");
    for(int i = 0;i<3;i++){
        printf("%dつめ：",i+1);
        scanf("%d",&in[i]);
    }
    printf("一番小さいのは%d\n",min3(in[0],in[1],in[2]));

}