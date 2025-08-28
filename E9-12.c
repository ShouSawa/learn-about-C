#include<stdio.h>
int str_length(const char s[]){
    int len = 0;
    while(s[len])len++;
    return len;
}
void rev_strings(char s[][128],int n){
    char tmp[5][128];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<str_length(s[i]);j++){
            tmp[i][j] = s[i][str_length(s[i])-j-1];
        }
    }
    for(int i = 0;i<5;i++){
        for(int j = 0;j<str_length(s[i]);j++){
            s[i][j] = tmp[i][j];
        }
    }
}
int main( int argc, char** argv )
{
    char s[5][128];
    for(int i = 0;i<5;i++){
        printf("文字列を入力：");
        scanf("%s",s[i]);
    }
    rev_strings(s,5);
    for(int i = 0;i<5;i++){
        printf("%s\n",s[i]);
    }
}