#include "header.h"

vector<int> get_k_largest(int arr[], int size, int k){
    vector<int> res;
    return res;
}

int main(){
    int arr[] = {1, 23, 12, 9, 30, 2, 50};
    vector<int> res;
    res = get_k_largest(arr, sizeof(arr)/sizeof(arr[0]), 3);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
