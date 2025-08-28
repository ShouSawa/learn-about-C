#include<stdio.h>
#define len 5
void rev_intary(int v[],int n){
    //反転用配列
    int tmp[len];
    for(int i = 0;i<n;i++){
        //配列を反転させてコピー
        tmp[i] = v[(n-1)-i];
    }
    for(int i = 0;i<n;i++){
        //元の配列を反転
        v[i] = tmp[i];
    }
}
int main( int argc, char** argv )
{
    int arr[len] = {33,12,33,55,77};
    rev_intary(arr,len);
    for(int i = 0;i<len;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}