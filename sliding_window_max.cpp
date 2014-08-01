/*

    A long array A[] is given to you. There is a sliding window of size w which is moving from the very left of the array to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by one position. Following is an example:
    The array is [1 3 -1 -3 5 3 6 7], and w is 3.

    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7

    Input: A long array A[], and a window width w
    Output: An array B[], B[i] is the maximum value of from A[i] to A[i+w-1]
    Requirement: Find a good optimal way to get B[i]
*/

#include "header.h"

vector<int> sliding_window_max(int arr[], int size, int k){
    vector<int> res;
    int max = INT_MIN;
    int start = 0, end = k-1;
    for(int i=start; i<=end && i<size; i++){
        max = std::max(arr[i], max);
        mp[arr[i]]++;
    }
    res.push_back(max);
    unordered_map<int,int> mp;
    if(k>size)
        return res;
    while(end<size){
        mp[arr[end]]++;
        
    return res;
}

int main(){
    int arr[] = {1, 3, -1,-3, 5, 3, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> res = sliding_window_max(arr, int size, 3);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
