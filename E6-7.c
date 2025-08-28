#include<stdio.h>
void hello(void){
    //引数を受け取らない関数
    printf("Hello\n");
}
int main( int argc, char** argv )
{
    hello();
    return 0;
}