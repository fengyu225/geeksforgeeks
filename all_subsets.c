#include<stdio.h>

void print_all_subset(int* arr, int size, int curr, int* x, int curr_x){
    if(size == 0)
        return;
    if(curr==size){
        for(int i=0; i<curr_x; i++)
            printf("%d ",x[i]);
        printf("\n");
        return;
    }
    x[curr_x] = arr[curr];
    print_all_subset(arr, size, curr+1, x, curr_x+1);
    print_all_subset(arr, size, curr+1, x, curr_x);
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x[10];
    print_all_subset(arr, sizeof(arr)/sizeof(int), 0, x, 0);
    return 0;
}
