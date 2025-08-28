#include<stdio.h>
int main( int argc, char** argv )
{
    //文字列strを空文字列にするには要素を\0で書き換えればよい(最初の要素を\0に書き換えた時点で出力は""になる)
    char str[] = "ABC";
    printf("文字列strは\"%s\"です．\n",str);
    for(int i = 0;i<3;i++){
        str[i] = '\0';
        printf("文字列strは\"%s\"です．\n",str);
    }
    printf("文字列strは\"%s\"です．\n",str);
    return 0;
}