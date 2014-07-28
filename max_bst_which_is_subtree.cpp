#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int search(TreeNode* curr, TreeNode*& max_bst, int& max_so_far, int min, int max){
    if(!curr){
        return 0;
    }
    if(curr->val>min && curr->val<max){
        int l = search(curr->left,max_bst,max_so_far,min,curr->val);
        int r = search(curr->right,max_bst,max_so_far,curr->val,max);
        if(l>=0 && r>=0){
            if(l+r+1>max_so_far){
                max_bst = curr;
                max_so_far = l+r+1;
            }
            return l+r+1;
        }
        else
            return -1;
    }
    else{
        search(curr,max_bst,max_so_far,INT_MIN,INT_MAX);
        return -1;
    }
}

TreeNode* get_max_bst(TreeNode* root){
    if(!root) return NULL;
    TreeNode* res = NULL;
    TreeNode* child = NULL;
    int max_so_far = INT_MIN;
    search(root, res, max_so_far, INT_MIN, INT_MAX);
    return res;
}

void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    /*
         ____10____
        /          \
      __5_         15_
     /    \           \
     1     8           7
     */
    struct TreeNode n0(15);
    struct TreeNode n1(10);
    struct TreeNode n3(5);
    struct TreeNode n4(7);
    struct TreeNode n8(8);
    struct TreeNode n9(1);
    n1.left = &n3;
    n1.right = &n0;
    n3.left = &n9;
    n3.right = &n8;
    n0.right = &n4;
    TreeNode* res = get_max_bst(&n1);
    preorder(res);
    cout<<endl;
    return 0;
}
