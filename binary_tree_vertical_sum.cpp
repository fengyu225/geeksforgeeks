#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void traverse(TreeNode* curr, int k, map<int,int>& m){
    if(!curr) return;
    m[k] += curr->val;
    traverse(curr->left,k-1,m);
    traverse(curr->right,k+1,m);
}


vector<int> vertical(TreeNode* root){
    vector<int> res;
    map<int,int> m;
    traverse(root,0,m);
    map<int,int>::iterator iter = m.begin();
    for(;iter != m.end();iter++){
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
    vector<int> res = vertical(&n1);
    for(int i=0; i<res.size(); i++)
        std::cout<<res[i]<<" ";
    std::cout<<std::endl;
    return 0;
}
    
