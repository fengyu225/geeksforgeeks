#include "header.h"

int search(int A[], int n, int target) {
    if(n == 0) return -1;
    int l = 0, r=n-1;
    while(l<r){
        int m = (l+r)/2;
        if(A[m] == target) return m;
        if(A[m]<A[0]){
            if(target<A[m] || target>A[m] && target>A[0])
                r = m-1;
            else
                l = m+1;
        }
        else{
            if(target>A[m] || target<A[m] && target<A[0])
                l = m+1;
            else
                r = m-1;
        }
    }
    return l==r && A[l] == target?l:-1;
}

int main(){
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 5));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 2));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 4));
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 3));
    return 0;
}
