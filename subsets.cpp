#include "header.h"

void search(vector<int>& S, int curr, vector<int>& v, vector<vector<int> >& res){
    if(curr == S.size()){
        res.push_back(v);
        return;
    }
    search(S,curr+1,v,res);
    v.push_back(S[curr]);
    search(S,curr+1,v,res);
    v.pop_back();
}

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > res;
    if(S.size() == 0) return res;
    vector<int> v;
    search(S,0,v,res);
    return res;
}

int main(){
    int arr[] = {1, 2, 3};
    vector<int> S(arr,arr+sizeof(arr)/sizeof(arr[0]));
    vector<vector<int> > res = subsets(S);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
