#include "header.h"

int find_start(int arr[], int size, int target){
    if(size == 0) return -1;
    int l=0,r=size-1;
    while(l<r){
        int m = (l+r)/2;
        if(arr[m] == target)
            r=m;
        else if(arr[m]<target)
            l=m+1;
        else
            r=m-1;
    }
    return (l>r || arr[l] != target)?-1:l;
}

int find_end(int arr[], int size, int target){
    if(size == 0) return -1;
    int l=0,r=size-1;
    while(l<r){
        int m=(l+r+1)/2;
        if(arr[m] == target)
            l=m;
        else if(arr[m]<target)
            l=m+1;
        else
            r=m-1;
    }
    return (l>r || arr[l] != target)?-1:l;
}

int main(){
    int arr[] = {5, 7, 7, 8, 8, 10};
    std::cout<<find_start(arr,sizeof(arr)/sizeof(arr[0]),6)<<std::endl;
    std::cout<<find_end(arr,sizeof(arr)/sizeof(arr[0]),6)<<std::endl;
    return 0;
}
