#include "header.h"

/*
 * http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void replace(TreeNode* root, int& total_sum){
    if(!root){
        total_sum = 0;
        return;
    }
    int r_total_sum = 0;
    replace(root->right,r_total_sum);
    int l_total_sum = 0;
    replace(root->left,l_total_sum);
    total_sum = r_total_sum+l_total_sum+root->val;
    root->val = r_total_sum;
}


void replace_nodes(TreeNode* root){
    if(!root) return;
    int total_sum = 0;
    replace(root,total_sum);
}

void preorder(TreeNode* root){
    if(!root)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    TreeNode t0(15);
    TreeNode t1(10);
    TreeNode t2(20);
    TreeNode t3(8);
    TreeNode t4(12);
    TreeNode t5(16);
    TreeNode t6(25);
    TreeNode t7(13);
    TreeNode t8(17);
    t0.left = &t1;
    t0.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    t4.right = &t7;
    t5.right = &t8;
    replace_nodes(&t0);
    preorder(&t0);
    cout<<endl;
    return 0;
}
