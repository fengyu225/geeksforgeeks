#include "header.h"

/*http://www.geeksforgeeks.org/find-subarray-with-given-sum/
 * !!! array of non-negative integers
 */

void find_subarr(int arr[], int size, int sum){
    int start = 0, curr_sum = arr[0];
    for(int i=1; i<=size; i++){
        while(curr_sum>sum && start<i-1){
            curr_sum -= arr[start];
            start++;
        }
        if(curr_sum == sum)
            cout<<"start: "<<start<<" end "<<i-1<<endl;
        if(i<size)
            curr_sum += arr[i];
    }
}

int main(){
    int arr[] = {1, 4, 20, 3, 10, 5};
    find_subarr(arr,sizeof(arr)/sizeof(arr[0]), 23);
    return 0;
}
