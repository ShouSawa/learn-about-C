#include<stdio.h>
//文字列の長さを取得
int str_length(const char s[]){
    int len = 0;
    while(s[len])len++;
    return len;
}
//文字列を空文字列に
void null_string(char s[]){
    int len = str_length(s);
    for(int i = 0;i<len;i++){
        s[i] = '\0';
    }
}
int main( int argc, char** argv )
{
    char s[] = "ABCDE";
    for(int i = 0;i<str_length(s);i++){
        printf("%c",s[i]);
    }
    printf("\n");
    null_string(s);
    for(int i = 0;i<str_length(s);i++){
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}