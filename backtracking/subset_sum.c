/*
 Subset sum problem is to find subset of elements that are selected from a given set whose sum adds up to a given number K. We are considering the set contains non-negative values. It is assumed that the input set is unique (no duplicates are presented).
 *
 */

#include<stdio.h>

void ss(int* arr, int size, int curr, int* t, int t_curr, int curr_sum, int target){
    if(curr == size)
        return;
    if(curr_sum+arr[curr] == target){
        t[t_curr++] = arr[curr];
        for(int i=0; i<t_curr; i++)
            printf("%d ", t[i]);
        printf("\n");
    }
    if(curr_sum+arr[curr]<target){
        t[t_curr] = arr[curr];
        ss(arr, size, curr+1, t, t_curr+1, curr_sum+arr[curr], target);
    }
    ss(arr, size, curr+1, t, t_curr, curr_sum, target);
}

int main(){
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int t[7];
    ss(arr,size,0,t,0,0,35);
    return 0;
}
