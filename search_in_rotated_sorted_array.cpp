#include "header.h"

int search(int A[], int n, int target) {
    if(n==0) return -1;
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r+1)/2;
        if(arr[m] == target) return m;
        if(arr[m] < arr[0]){
            if(target
}

int main(){
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 5));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 2));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 4));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 3));
    return 0;
}
