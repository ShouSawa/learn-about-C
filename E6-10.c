#include<stdio.h>
#define len 5
void intary_rcpy(int v1[],const int v2[],int n){
    //v1にv2を反転させてコピーする関数
    for(int i = 0;i<n;i++){
        v1[i] = v2[(n-1)-i];
    }
}
int main( int argc, char** argv )
{
    int arr1[len];
    int arr2[len] = {33,12,33,55,77};
    intary_rcpy(arr1,arr2,len);
    for(int i = 0;i<len;i++){
        printf("%d\n",arr1[i]);
    }
    return 0;
}