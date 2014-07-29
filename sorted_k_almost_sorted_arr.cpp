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

void siftdown(int heap[], int heap_end){
    int p = 0;
    int c = -1;
    while(1){
        c = 2*p+2<=heap_end && heap[2*p+2]<heap[2*p+1]?2*p+2:2*p+1;
        if(c>heap_end || c<0 || heap[c]>heap[p]) break;
        swap(heap,c,p);
        p = c;
    }
}

void sort_k_heap(int arr[], int size, int k){
    int heap[k];
    int curr = 0, curr_sorted=-1;
    while(curr<size && curr<k+1){
        heap[curr] = arr[curr];
        insert_heap(heap,curr);
        curr++;
    }
    int heap_end = k;
    curr = k+1;
    while(1){
        arr[++curr_sorted] = heap[0];
        if(curr<size){
            heap[0] = arr[curr];
            curr++;
        }
        else{
            if(heap_end == 0) break;
            heap[0] = heap[heap_end--];
        }
        siftdown(heap,heap_end);
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
