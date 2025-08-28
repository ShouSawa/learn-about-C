#include<stdio.h>
int min_of(const int v[],int n){
    //要素数nの配列vの最小値を返す
    int tmp = 10e5;
    for(int i = 0;i<n;i++){
        if(v[i]<tmp){
            tmp = v[i];
        }
    }
    return tmp;
}
int main( int argc, char** argv )
{
    int arr[5] = {33,12,33,55,6};
    printf("最も小さいのは%d\n",min_of(arr,5));

    return 0;
}