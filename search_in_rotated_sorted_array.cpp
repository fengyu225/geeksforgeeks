#include "header.h"

int search(int arr[], int n, int target) {
    if(n==0) return -1;
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r+1)/2;
        if(arr[m] == target) return m;
        if(arr[m] < arr[0]){
            if(target<arr[m] || target>arr[0])
                r=m-1;
            else
                l = m+1;
        }
        if(arr[m] > arr[0]){
            if(target>arr[m] || target<arr[0])
                l = m+1;
            else
                r = m-1;
        }
    }
    return l==r && arr[l] == target?l:-1;
}

int main(){
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 5));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 2));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 4));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 3));
    return 0;
}
