#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* get_max_bst(TreeNode* root){
    if(!root) return NULL;
    int l_num = 0;
    int r_num = 0;
    int l_max = INT_MIN;
    int r_max = INT_MIN;
    int l_min = INT_MAX;
    int r_min = INT_MAX;
    
}

void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct TreeNode n0(15);
    struct TreeNode n1(10);
    struct TreeNode n2(20);
    struct TreeNode n3(5);
    struct TreeNode n4(7);
    struct TreeNode n5(2);
    struct TreeNode n6(5);
    struct TreeNode n7(0);
    struct TreeNode n8(8);
    struct TreeNode n9(3);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n3;
    n1.right = &n4;
    n4.left = &n5;
    n4.right = &n6;
    n5.left = &n7;
    n5.right = &n8;
    n6.left = &n9;
    preorder(&n0);
    cout<<endl;
    return 0;
}
