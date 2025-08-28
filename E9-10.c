#include<stdio.h>
int str_length(const char s[]){
    int len = 0;
    while(s[len])len++;
    return len;
}
//文字列内の数字を削除
void del_digit(char s[]){
    char tmp[100];
    int idx = 0;
    int count = 0;
    while(s[count]){
        if(s[count] < '0' || s[count] > '9'){
            tmp[idx] = s[count];
            idx++;
        }
        count++;
    }
    for (int i = 0; i< str_length(s); i++) {
        s[i] = tmp[i];
    }
}
int main( int argc, char** argv )
{
char str[100];
    scanf("%s",str);
    del_digit(str);
    int count = 0;
    while(str[count]){
        printf("%c",str[count]);
        count++;
    }
    printf("\n");
    return 0;
}