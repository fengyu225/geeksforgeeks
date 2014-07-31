#include "header.h"

class cmp{
    public:
        bool operator() (int a, int b){
            return a>b;
        }
};

int get_k_largest_sorting(int arr[], int size, int k){
    std::sort(arr,arr+size,cmp());
    return arr[k-1];
}

void swap(int arr[], int a, int b){
    int x = arr[a];
    arr[a] = arr[b];
    arr[b] = x;
}

void heap_insert(int arr[], int last_idx){
    int c = last_idx;
    while(c>0){
        int p = (last_idx-1)/2;
        if(arr[p]<=arr[c]) break;
        swap(arr,p,c);
        c = p;
    }
}

void siftdown(int arr[], int last_idx){
    int p = 0;
    while(2*p+1<=last_idx){
        int c = 2*p+2<=last_idx && arr[2*p+2]<arr[2*p+1]?2*p+2:2*p+1;
        if(arr[c]>=arr[p]) break;
        swap(arr,c,p);
        p = c;
    }
}

int get_k_largest_min_heap(int arr[], int size, int k){
    if(k<=0 || k>size) return INT_MIN;
    //min heap with size-k+1 elements
    int heap[k];
    int curr_idx = 0;
    for(int i=0; i<k; i++){
        heap[i] = arr[i];
        heap_insert(heap,i);
    }
    for(int i=k; i<size; i++){
        if(arr[i]<=heap[0]) continue;
        heap[0] = arr[i];
        siftdown(heap,k-1);
    }
    return heap[0];
}

class heap_comp{
    public:
        bool operator() (int a, int b){
            return a<b;
        }
};

int get_k_largest_max_heap(int arr[], int size, int k){
    if(k<=0 || k>size) return INT_MIN;
    priority_queue<int,vector<int>,heap_comp> q (arr,arr+size);
    for(int i=0; i<k-1; i++)
        q.pop();
    int x = q.top();
    return x;
}

int get_k_largest_oder_stat(int arr[], int size, int k){
    int left = 0, right = size-1, curr = 0;
    while(left<right){
        curr = left;
        for(int i=left+1; i<=right; i++){
            if(arr[i]<arr[left])
                swap(arr,i,++curr);
        }
        if(curr-left+1 == k) return arr[left];
        if(k>curr-left+1){
            k -= curr-left+1;
            left = curr+1;
        }
        else{
            left++;
            right = curr;
        }
    }
    return left==right && k==1?arr[left]:INT_MIN;
}

int main(){
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 1)<<endl;
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 2)<<endl;
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 3)<<endl;
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 4)<<endl;
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 5)<<endl;
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 6)<<endl;
    cout<<get_k_largest_oder_stat(arr, sizeof(arr)/sizeof(arr[0]), 7)<<endl;
    return 0;
}
