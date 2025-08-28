#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#define NUMBER 5

//文字列sを反転して表示する関数
void gyaku_puts(const char s[]){
    for(int i = strlen(s);i>-1;i--){
        printf("%c",s[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int i;
    for ( i = 1; i < argc; i++ ){
	if(argc >= 100){
	    puts("引数が多過ぎます。");
	    break;
	}
	gyaku_puts(argv[i]);
    }

    
    
    return 0;
}
