#include "header.h"

vector<vector<int> > subsetsWithDup(vector<int> &S) {
}

int main(){
    int s_arr[] = {1, 2, 2};
    /*
     * [
          [2],
          [1],
          [1,2,2],
          [2,2],
          [1,2],
          []
        ]
     */
    vector<int> S(s_arr,s_arr+sizeof(s_arr)/sizeof(s_arr[0]));
    vector<vector<int> > res = subsetsWithDup(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
