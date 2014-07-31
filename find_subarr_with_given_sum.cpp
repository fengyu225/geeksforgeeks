#include "header.h"

/*http://www.geeksforgeeks.org/find-subarray-with-given-sum/
 */

void find_subarr(int arr[], int size, int sum){
    int start = 0, res = arr[0];
    for(int i=1; i<=size; i++){
        while(res>sum && start<i-1){
            res -= arr[start];
            start++;
        }
        if(res == sum)
            cout<<"start: "<<start<<" end "<<i-1<<endl;
        if(i<size)
            res += arr[i];
    }
}

int main(){
    int arr[] = {1, 4, 20, 3, 10, 5};
    find_subarr(arr,sizeof(arr)/sizeof(arr[0]), 23);
    return 0;
}
