#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#define NUMBER 5

int main(int argc, char **argv)
{
    char s1[100];
    char s2[100];
    char s3[100];
    printf("文字列1を入力してください：");
    scanf("%s", s1); //&を置かない
    printf("文字列2を入力してください：");
    scanf("%s", s2); //&を置かない
    printf("文字列3を入力してください：");
    scanf("%s", s3); //&を置かない

    // 文字列を大きい順にソート
    char r[100];
    if (strcmp(s1, s2) < 0) {
	strcpy(r, s1);
        strcpy(s1, s2);
	strcpy(s2, r);
    }
    if (strcmp(s1, s3) < 0) {
	strcpy(r, s1);
        strcpy(s1, s3);
	strcpy(s3, r);
    }
    if (strcmp(s2, s3) < 0) {
	strcpy(r, s2);
        strcpy(s2, s3);
	strcpy(s3, s2);
    }
    printf("中央の値は\"%s\"です。\n",s2);
    
    
    return 0;
}
