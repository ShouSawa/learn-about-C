#include<stdio.h>
int str_length(const char s[]){
    int len = 0;
    while(s[len])len++;
    return len;
}
//文字列を反転する
void rev_string(char s[]){
    char tmp[100];
    for(int i = 0;i<str_length(s);i++){
        tmp[i] = s[str_length(s)-i-1];   
    }
    for (int i = 0; i< str_length(s); i++) {
        s[i] = tmp[i];
    }
}
int main( int argc, char** argv )
{
    char str[100];
    scanf("%s",str);
    rev_string(str);
    int count = 0;
    while(str[count]){
        printf("%c",str[count]);
        count++;
    }
    printf("\n");
    return 0;
}