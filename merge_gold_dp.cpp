/*
 * We have n gold coins. We need to amalgamate all the n coins to create one single coin, we can merge two coins at once. The cost of merging two coins is equal to the value of those coins. How do we ensure that the cost of merging n coins in minimum.
 */

#include "header.h"

int get_min_merge_cost(int coins[], int size){
    int res = 0;
    for(int i=0; i<size; i++)
        res += coins[i];
    return res;
}

    
//int get_min_merge_cost(int coins[], int size){
//    int arr[size][size+1];
//    memset(arr,0,sizeof(arr));
//    for(int i=0; i<size; i++) arr[i][1] = coins[i];
//    for(int i=2; i<=size; i++){
//        for(int j=0; j+i<=size;j++){
//            int x = INT_MAX;
//            for(int k=1;k<i;k++){
//                int m = arr[j][k]+arr[j+k][i-k];
//                x = std::min(m,x);
//            }
//            arr[j][i] = x;
//        }
//    }
//    return arr[0][size];
//}

int main(){
    int coins[] = {5 ,8 , 4, 3, 9, 6};
    cout<<get_min_merge_cost(coins, sizeof(coins)/sizeof(coins[0]))<<endl;
    return 0;
}
