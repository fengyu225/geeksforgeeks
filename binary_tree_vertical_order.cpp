#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void search(TreeNode* curr, int k, map<int,vector<TreeNode*> >& mp){
    if(!curr) return;
    if(mp.find(k) == mp.end()){
        vector<TreeNode*> v;
        v.push_back(curr);
        mp[k] = v;
    }
    else{
        mp[k].push_back(curr);
    }
    search(curr->left,k-1,mp);
    search(curr->right,k+1,mp);
}

vector<vector<TreeNode*> > print_vertical(TreeNode* root){
    vector<vector<TreeNode*> > res;
    if(!root) return res;
    map<int,vector<TreeNode*> > mp;
    search(root,0,mp);
    map<int,vector<TreeNode*> >::iterator iter = mp.begin();
    for(;iter != mp.end(); iter++){
        res.push_back(iter->second);
    }
    return res;
}

int main(){
    struct TreeNode n4(4);
    struct TreeNode n5(5);
    struct TreeNode n7(7);
    struct TreeNode n2(2);
    struct TreeNode n3(3);
    struct TreeNode n1(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    vector<vector<TreeNode*> > res = print_vertical(&n1);
    for(int i=0; i<res.size(); i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]->val<<" ";
        cout<<endl;
    }
    return 0;
}
