#include<stdio.h>
int count_char(const char s[100],int c){
    int len = 0;
    int count = 0;
    while(s[len]){
        if(s[len] == c)count++;
        len++;
    }
    return count;
}
int main( int argc, char** argv )
{
    char s[100];
    char c;
    printf("文字列を入力してください：");
    scanf("%s",s);
    int index = getchar();
    printf("どの文字を数えますか：");
    scanf("%c",&c);
    printf("%cは%d個あります\n",c,count_char(s,c));
}