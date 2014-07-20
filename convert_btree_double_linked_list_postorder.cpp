#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* convert(TreeNode* root){
    if(!root) return NULL;
    TreeNode* left_h = convert(root->left);
    TreeNode* right_h = convert(root->right);
    TreeNode* res = left_h?left_h:right_h;
    if(left_h && right_h){
        res->left->right = right_h;
        right_h->left = res->left;
    }
    root->left = root;
    root->right = root;
    if(res){
        res->left->right = root;
        root->left = res->left;
        root->right = res;
        res->left = root;
    }
    else res = root;
    return res;
}

int main(){
    TreeNode t1(-1);
    TreeNode t2(5);
    TreeNode t3(4);
    TreeNode t4(2);
    TreeNode t5(-4);
    t1.left = &t2;
    t2.left = &t3;
    t3.right = &t4;
    t4.left = &t5;
    TreeNode* s = convert(&t5);
    TreeNode* head = s;
    printf("left: %d, curr: %d, right: %d\n", head->left->val, head->val, head->right->val);
    head = head->right;
    while(head != s){
        printf("left: %d, curr: %d, right: %d\n", head->left->val, head->val, head->right->val);
        head = head->right;
    }
    return 0;
}
