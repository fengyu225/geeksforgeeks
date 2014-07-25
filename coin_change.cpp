#include "header.h"

/* Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
 */


int count(int S[], int n, int sum){
    int table[sum+1][n];
    for(int i=0; i<n; i++) table[0][i] = 1;
    for(int i=1;i<sum+1;i++)
        for(int j=0;j<n;j++){
            table[i][j] = 
                (i-S[j]>=0)?table[i-S[j]][j]:0+
                (j >= 1)?table[i][j-1]:0;
        }
    return table[sum][n-1];
}

int main(){
    int S[] = {3, 2, 1};
    cout<<count(S, sizeof(S)/sizeof(S[0]), 4)<<endl;
    return 0;
}
