#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int search(TreeNode* curr, TreeNode*& max_bst, int& max_so_far, int min, int max, TreeNode*& child){
    if(!curr) return 0;
    if(min<curr->val && curr->val<max){
        int l = search(curr->left, max_bst, max_so_far, min, curr->val, child);
        TreeNode* left_child = l==0?NULL:child;
        int r = search(curr->right, max_bst, max_so_far, curr->val, max, child);
        TreeNode* right_child = r==0?NULL:child;
        TreeNode* new_curr = new TreeNode(curr->val);
        new_curr->left = left_child;
        new_curr->right = right_child;
        child = new_curr;
        if(l+r+1>max_so_far){
            max_so_far = l+r+1;
            max_bst = new_curr;
        }
        return l+r+1;
    }
    else{
        search(curr, max_bst, max_so_far, INT_MIN, INT_MAX, child);
        return 0;
    }
}

TreeNode* get_max_bst(TreeNode* root){
    if(!root) return NULL;
    TreeNode* res = NULL;
    TreeNode* child = NULL;
    int max_so_far = INT_MIN;
    search(root, res, max_so_far, INT_MIN, INT_MAX, child);
    return res;
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
    TreeNode* res = get_max_bst(&n0);
    preorder(res);
    cout<<endl;
    return 0;
}
