#include "header.h"

void search(vector<int>& S, int curr, vector<int>& v, vector<vector<int> >& res){
    if(curr == S.size()){
        res.push_back(v);
        return;
    }
    search(S,curr+1,v,res);
    v.push_back(S[curr]);
    int i=curr+1;
    for(;i<S.size() && S[i] == S[i-1];i++) v.push_back(S[i]);
    search(S,i,v,res);
    i--;
    while(i>=curr){
        v.pop_back();
        i--;
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > res;
    vector<int> v;
    search(S,0,v,res);
    return res;
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
