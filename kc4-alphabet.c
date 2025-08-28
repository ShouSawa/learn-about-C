#include<stdio.h>
#include<string.h>

int main( int argc, char** argv )
{
    FILE *fp;
    int n;
    char s[100];
    if (( fp = fopen( argv[1], "r" ) ) == NULL) { //ファイルを開く
	perror( argv[1] );
	exit( 1 );
    }
    
    while ( fscanf( fp, "%d", &n ) != EOF ) {
        strcpy(s, n);
	
    int big = 0;
    int small = 0;
    int number = 0;
    int len = 0;
    while(s[len]){
        if((s[len] >= 'a') && (s[len] <= 'z')){ //小文字のとき
	    small += 1;
	}
	else if((s[len] >= 'A') && (s[len] <= 'Z')){ //大文字のとき
	    big += 1;
	}else if(s[len] >= '0' && s[len] <= '9'){
	    number += 1;
	}
        len++;
    }
    }
    printf("大文字:%d文字\n",big);
    printf("小文字:%d文字\n",big);
    printf("数字:%d文字\n",big);
    return 0;
}
