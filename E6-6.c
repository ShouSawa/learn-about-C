#include<stdio.h>
int alert(int n){
    //警報をn回連続して発する関数
    for(int i = 0;i<n;i++){
        printf("alert\n");
    }
}
int main( int argc, char** argv )
{
    int a;
    printf("警報を何回ならす？：");
    scanf("%d",&a);
    alert(a);
    return 0;
}