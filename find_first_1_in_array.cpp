#include "header.h"

int get_first_1(int arr[], int l, int r, int size){
    while(l<r){
        int m = (l+r)/2;
        if(arr[m] == 1)
            r=m;
        else
            l=m+1;
    }
    return l==r && arr[l]==1?l:-1;
}

int main(){
    int arr[] = {0, 0, 0, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<get_first_1(arr,0,size-1,size)<<endl;
    return 0;
}
