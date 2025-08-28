#include <stdio.h>
#include <string.h>

//受け取った文字列を後ろから逆に表示し改行する関数
void gyaku_puts(const char s[]){
    for(int i = strlen(s);i>-1;i--){
        printf("%c",s[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int i;
    for ( i = argc -1 ; i > 0; i--){ //逆の順番
	gyaku_puts(argv[i]);
    }
    return 0;
}
