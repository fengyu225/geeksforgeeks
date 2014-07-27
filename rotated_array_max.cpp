#include "header.h"

int find_max(int arr[], int size){
    if(size == 0) return -1;
    if(size == 1) return 0;
    int l=0,r=size-1;
    while(l<=r){
        int m = (l+r)/2;
        if(m<size-1 && arr[m]>arr[m+1] || m==size-1 && arr[m]>arr[0]) return m;
        if(arr[m]>arr[0] || m==0) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(){
    //int arr[] = {4, 5, 6, 1, 2, 3};
    int arr[] = {5, 4};
    cout<<find_max(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
