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


TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b){
    if(!root) return NULL;
    if(root == a || root == b) return root;
    TreeNode* l = lca(root->left,a,b);
    TreeNode* r = lca(root->right,a,b);
    if(l && r) return root;
    return l?l:r;
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
    cout<<lca(&t0,&t3,&t7)->val<<endl;
    return 0;
}
