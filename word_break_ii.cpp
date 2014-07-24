#include "header.h"

void dfs(string& s, int curr, vector<int>& end_idx, vector<string>& res, unordered_set<string>& dict, vector<vector<bool> >& mp){
    printf("%d\n", curr);
    if(curr>=s.size()){
        string x = s;
        for(int i=0; i<end_idx.size()-1; i++){
            x.insert(end_idx[i]+i, " ");
        }
        res.push_back(x);
        return;
    }
    for(int i=0; i<mp[curr].size(); i++){
        if(mp[curr][i] == true){
            end_idx.push_back(i+1);
            dfs(s,i+1,end_idx,res,dict,mp);
            end_idx.pop_back();
        }
    }
}

//vector<string> wordBreak(string s, unordered_set<string> &dict) {
//    vector<string> res;
//    vector<vector<bool> > mp(s.size(), vector<bool>(s.size(), false));
//    for(int i=0; i<s.size(); i++)
//        for(int j=i; j<s.size(); j++)
//            if(dict.find(s.substr(i,j-1+1)) != dict.end())
//                mp[i][j] = true;
//    bool flag = false;
//    for(int i=0; i<s.size(); i++)
//        if(mp[i][s.size()-1]){
//            flag = true;
//            break;
//        }
//    if(!flag) return res;
//    vector<int> end_idx;
//    dfs(s,0,end_idx,res,dict,mp);
//    return res;
//}

vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<vector<bool> > mp(s.size(),vector<bool>(s.size(),false));
    for (int i=0;i<s.size();i++){
        for (int j=i;j<s.size();j++){
            if (dict.find(s.substr(i,j-i+1))!=dict.end()){
                mp[i][j]=true;
            }
        }
    }
    bool flag =false;
    for (int i=0;i<s.size();i++){
        if (mp[i][s.size()-1]){
            flag = true; break;
        }
    }
    vector<string> res;
    vector<int>sp;
    if (!flag){return res;}
    dfs(s,0,sp,res,dict,mp);
    return res;
}

int main(){
    vector<string> res;
    unordered_set<string> dict({"cat", "cats", "and", "sand", "dog"});
    string s("catsanddog");
    res = wordBreak(s,dict);
    for(int i=0; i<res.size(); i++)
        std::cout<<res[i]<<std::endl;
    return 0;
}
