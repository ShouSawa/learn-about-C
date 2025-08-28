#include<stdio.h>
#include<string.h>
#define num 100
#define len 128
void arr_reader(const char s[][len]){
    for(int i = 0;i<num;i++){
        if(strcmp(s[i],"$$$$")==0)break;
        printf("s[%d]=%s\n",i,s[i]);
    }
}
int main(void)
{
    char s[num][len];
    printf("$$$$が入力されると終了\n");
    for(int i = 0;i<len;i++){
        printf("文字列を入力：");
        scanf("%s",s[i]);
        if(strcmp(s[i],"$$$$")==0)break;
    }
    arr_reader(s);
    return 0;
}