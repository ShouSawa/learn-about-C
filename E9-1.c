#include<stdio.h>
int main( int argc, char** argv )
{
    //文字列の途中で終端文字が含まれているのでそこで出力が終わる．
    char str[] = "ABC\0DEF";
    printf("文字列strは\"%s\"です．\n",str);
    return 0;
}