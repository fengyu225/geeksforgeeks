#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<TreeNode*> > print_vertical(TreeNode* root){
    vector<vector<TreeNode*> > res;
    if(!root) return res;
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
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
