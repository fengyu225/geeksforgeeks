/*
 * Remove the nodes in the binary tree for that the sum of all values from root to leaf is less than K.
 */

#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool delete_n(TreeNode* curr, int k){
    if(!curr)
        return k<=0;
    bool l = delete_n(curr->left,k-curr->val);
    bool r = delete_n(curr->right,k-curr->val);
    if(!l && !r){
        delete curr;
        return false;
    }
    if(!l)
        curr->left = NULL;
    if(!r)
        curr->right = NULL;
    return true;
}

TreeNode* delete_nodes(TreeNode* root, int k){
    bool res = delete_n(root,k);
    return res?root:NULL;
}

void preorder(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(12);
    root->right->right->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);
    root->left->left->right->left = new TreeNode(13);
    root->left->left->right->right = new TreeNode(14);
    root->left->left->right->right->left = new TreeNode(15);
    TreeNode* res = delete_nodes(root, 20);
    if(!res)
        std::cout<<"NULL"<<std::endl;
    else
        preorder(root);
    cout<<std::endl;
    return 0;
}
