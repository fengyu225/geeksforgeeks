#include "header.h"

int max_subarr_sum(int arr[], int size){
     int max_sum[size];
     max_sum[0] = arr[0];
     int max_so_far = arr[0];
     for(int i=1; i<size; i++){
         max_sum[i] = std::max(max_sum[i-1]+arr[i], arr[i]);
         max_so_far = std::max(max_so_far,max_sum[i]);
     }
     return max_so_far;
}

int main(){
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout<<max_subarr_sum(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
