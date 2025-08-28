#include<stdio.h>
#define len 5
int search_idx(const int v[],int idx[],int key,int n){
    //配列v内のkeyと等しい数字の数をcountに格納し，returnする．
    //その時に配列idxにkeyと等しい要素のindexを格納していく．
    int count = 0;
    for(int i = 0;i<n;i++){
        if(v[i] == key){
            idx[count] = i;
            count++;
        }
    }
    return count;
}
int main( int argc, char** argv )
{
    int idx[len] = {0*len};
    int arr[len] = {33,12,33,55,77};
    printf("%d\n",search_idx(arr,idx,12,len));
    for(int i = 0;i<len;i++){
        if(idx[i] == 0)break;
        printf("%d\n",idx[i]);
    }
    return 0;
}