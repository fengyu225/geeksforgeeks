#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void _convert(TreeNode* curr, TreeNode*& start, TreeNode*& end){
    if(!curr){
        start = end = NULL;
        return;
    }
    TreeNode* r_s = NULL;
    TreeNode* r_e = NULL;
    _convert(curr->right, r_s, r_e);
    TreeNode* l_s = NULL;
    TreeNode* l_e = NULL;
    _convert(curr->left, l_s, l_e);
    start = l_s?l_s:r_s?r_s:curr; 
    end = curr;
    TreeNode* a = NULL;
    TreeNode* b = NULL;
    if(r_s){
        a = r_s;
        b = curr;
        r_e->right = curr;
        curr->left = r_e;
        r_s->left = curr;
        curr->right = r_s;
    }
    else
        a = b = curr;
    if(l_s){
        l_e->right = a;
        a->left = l_e;
        l_s->left = b;
        b->right = l_s;
    }
}

TreeNode* convert(TreeNode* root){
    if(!root) return NULL;
    TreeNode* start = NULL;
    TreeNode* end = NULL;
    _convert(root,start,end);
    return start;
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
    TreeNode* res = convert(&n1);
    TreeNode* curr = res;
    do{
        if(!curr) break;
        cout<<curr->val<<", left: "<<curr->left->val<<" right: "<<curr->right->val<<endl;
        curr = curr->right;
    }while(curr != res);
    return 0;
}
