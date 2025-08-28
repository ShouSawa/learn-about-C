#include<stdio.h>
void put_stringn(const char s[],int n){
    //文字列sをn回表示する関数
    for(int i = 0;i < n;i++){
        printf("%s",s);
    }
    printf("\n");
}
int main( int argc, char** argv )
{
    char s[] = "ABC";
    int n = 3;
    put_stringn(s,n);
    return 0;
}