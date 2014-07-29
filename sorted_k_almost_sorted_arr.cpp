#include "header.h"

void swap(int arr[], int a, int b){
    int x = arr[a];
    arr[a] = arr[b];
    arr[b] = x;
}

void insert_heap(int heap[], int curr_end){
    if(curr_end == 0) return;
    int p = (curr_end-1)/2;
    while(curr_end>0){
        p = (curr_end-1)/2;
        if(heap[p]>heap[curr_end]){
            swap(heap,p,curr_end);
            curr_end = p;
        }
        else
            break;
    }
}

void sort_k_heap(int arr[], int size, int k){
    int heap[k];
    for(int i=0; i<size && i<k+1; i++){
        heap[i] = arr[i];
        insert(heap,i);
    }

}

int main(){
    int arr[] = {2, 6, 3, 12, 56, 8};
    int k = 3;
    sort_k_heap(arr,sizeof(arr)/sizeof(arr[0]),k);
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
