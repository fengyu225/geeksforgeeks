/*
 * Dynamic programming problem: Coin change problem:
 * Find the minimum number of coins required to make change for a given sum
 * (given unlimited cumber of N different denominations coin)
 *
 */

#include "header.h"

int min_number_of_coins(int coins[], int size, int sum){
    int min_c[sum+1];
    memset(min_c,0,sizeof(min_c));
    for(int i=1; i<sum+1; i++){
        int temp = INT_MAX;
        for(int j=0;j<size;j++){
            if(coins[j]<=i){
                temp = min_c[i-coins[j]]+1<temp?min_c[i-coins[j]]+1:temp;
            }
        }
        if(temp != INT_MAX)
            min_c[i] = temp;
    }
    return min_c[sum];
}

int main(){
    int coins[] = {25, 10, 5, 1};
    cout<<min_number_of_coins(coins,sizeof(coins)/sizeof(coins[0]),37)<<endl;
    return 0;
}
