#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void generate(int l, int r, vector<TreeNode*>& res){
    if(l>r){
        res.push_back(NULL);
        return;
    }
    for(int i=l; i<=r; i++){
        vector<TreeNode*> left, right;
        generate(l,i-1,left);
        generate(i+1,r,right);
        for(int j=0;j<left.size();j++)
            for(int k=0; k<right.size(); k++){
                TreeNode* curr = new TreeNode(i);
                curr->left = left[j];
                curr->right = right[k];
                res.push_back(curr);
            }
    }
}


vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    generate(1, n, res);
    return res;
}

void dfs(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    dfs(root->left);
    dfs(root->right);
}

int main(){
    vector<TreeNode*> res = generateTrees(3);
    for(int i=0;i<res.size();i++){
        dfs(res[i]);
        printf("\n");
    }
    return 0;
}
