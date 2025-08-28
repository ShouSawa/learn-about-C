#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define NUMBER 5

int str_chunum(const char s[], int c){

    int len = 0;
    int count = 0;
    while(s[len] != '\0'){
	if(s[len] == c){
	    count++;
	} 
        len++;
    }
    return count;
}

int main(void)
{
    char str[100];
    printf("文字列を入力してください：");
    scanf("%s", str);
    
    char c;
    int enter = getchar();
    printf("何の文字を数えますか：");
    scanf("%c", &c);

    int count;
    count = str_chunum(str, c);

    printf("%cは%d個あります。\n",c,count);

    return 0;
}
