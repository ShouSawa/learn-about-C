#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
int str_length(const char s[]){
    int len = 0;
    while(s[len])len++;
    return len;
}
int str_char(const char s[],int c){
    //cと一致する文字があればそのindexを返す，ないなら-1を返す．
    for(int i = 0;i<str_length(s);i++){
        if(s[i] == c)return i;
    }
    return -1;
}
int main( int argc, char** argv )
{
    char s[] = "ABCDE";
    int c = 65;//Aのこと
    printf("%d\n",str_char(s,c));
    return 0;
}