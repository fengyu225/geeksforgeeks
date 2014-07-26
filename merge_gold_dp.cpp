/*
 * We have n gold coins. We need to amalgamate all the n coins to create one single coin, we can merge two coins at once. The cost of merging two coins is equal to the value of those coins. How do we ensure that the cost of merging n coins in minimum.
 *
 *Ex: 5 ,8 , 4, 3, 9, 6
 We will merge 3 and 4, cost=7 {Remaining coins: 5,8,9, 6,7}
 Then we merge 5 and 6, cost=11 { Remaining coins: 11,8,9,7}
 Then we merge 7 and 8, cost=15 { Remaining coins: 11,15,9}
 Then we merge 9 and 11, cost=20 { Remaining coins: 20,15}
 Then we merge 20 and 15, cost=35 { Remaining coins: 35}
 Total cost: 7+11+15+20+35 = 88

 If we had merged the coin array {5, 8, 4, 3, 9, 6} in different fashion:
 Merging 5 and 8, cost=13 {Remaining coins: 13, 4, 3, 9, 6}
 Merging 13 and 4, cost=17 {Remaining coins: 17, 3, 9, 6}
 Merging 17 and 3, cost=20 {Remaining coins: 20, 9, 6}
 Merging 20 and 9, cost=29 {Remaining coins: 29, 6}
 Merging 29 and 6, cost=35 {Remaining coins: 35}
 Total cost: 114
 *
 */

#include "header.h"

class comp{
    public:
        bool operator() (int a, int b){
            return b<=a;
        }
};

int get_min_merge_cost(int coins[], int size){
    int res = 0;
    priority_queue<int,vector<int>,comp> q;
    for(int i=0; i<size; i++) q.push(coins[i]);
    while(!q.empty()){
        int a = q.top();
        q.pop();
        if(q.empty()) break;
        int b = q.top();
        q.pop();
        res += a+b;
        q.push(a+b);
    }
    return res;
}

int main(){
    int coins[] = {5 ,8 , 4, 3, 9, 6};
    cout<<get_min_merge_cost(coins, sizeof(coins)/sizeof(coins[0]))<<endl;
    return 0;
}
