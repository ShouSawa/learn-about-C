#include<stdio.h>
#include<string.h>
#define len 100
int main(void)
{
    char s[len][128];
    printf("$$$$が入力されると終了\n");
    for(int i = 0;i<len;i++){
        printf("文字列を入力：");
        scanf("%s",s[i]);
        if(strcmp(s[i],"$$$$")==0)break;
    }
    for(int i = 0;i<len;i++){
        if(strcmp(s[i],"$$$$")==0)break;
        printf("s[%d]=%s\n",i,s[i]);
    }
    return 0;
}