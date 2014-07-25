/*
 * Dynamic programming problem: Coin change problem:
 * Find the minimum number of coins required to make change for a given sum
 * (given unlimited cumber of N different denominations coin)
 *
 */

#include "header.h"

vector<vector<int> > min_number_of_coins(int coins[], int size, int sum){
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
    vector<vector<int> > res = min_number_of_coins(coins,sizeof(coins)/sizeof(coins[0]),37);
    for(int i=0; i<res.size(); i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
