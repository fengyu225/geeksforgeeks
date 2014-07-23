#include "header.h"

bool search(int A[], int n, int target) {
    if(n==0) return false;
    int l =0,r=n-1;
    if(n==1) return A[0] == target;
    while(l<r){
        int m = (l+r)/2;
        if(target == A[m]) return true;
        if(A[m]<A[0]){
            if(target<A[m] || target>A[m] && target>A[0])
                r=m-1;
            else
                l=m+1;
        }
        if(A[m]>A[0]){
            if(target>A[m] || target<A[m] && target<A[0])
                l = m+1;
            else
                r = m-1;
        }
        else
            return search(A+1, n-1, target);
    }
    return l==r && A[l] == target?true:false;
}

int main(){
    int A[] = {1, 1};
    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 0));
//    int A[] = {4, 4, 5, 5, 6, 7, 7, 0, 0, 1, 1, 2};
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 5));
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 2));
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 4));
//    printf("%d\n", search(A,sizeof(A)/sizeof(A[0]), 3));
    return 0;
}
