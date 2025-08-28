#include<stdio.h>
int str_length(const char s[]){
    int len = 0;
    while(s[len])len++;
    return len;
}
//文字列を反転して表示する
void put_stringr(const char s[]){
    for(int i = str_length(s);i>-1;i--){
        printf("%c",s[i]);
    }
    printf("\n");
}
int main( int argc, char** argv )
{
    char str[100];
    scanf("%s",str);
    put_stringr(str);
    return 0;
}