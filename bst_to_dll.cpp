#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void convert_(TreeNode* curr, TreeNode*& first, TreeNode*& last){
    if(!curr){
        first = NULL;
        last = NULL;
        return;
    }
    TreeNode* l_f = NULL;
    TreeNode* l_l = NULL;
    convert_(curr->left,l_f,l_l);
    TreeNode* r_f = NULL;
    TreeNode* r_l = NULL;
    convert_(curr->right,r_f,r_l);
    first = l_f?l_f:curr;
    last = r_l?r_l:curr;
    curr->left = NULL;
    curr->right = NULL;
    if(l_f){
        l_l->right = curr;
        curr->left = l_l;
        l_f->left = curr;
        curr->right = l_f;
    }
    if(r_f){
        curr->right = r_f;
        r_f->left = curr;
        if(!curr->left){
            curr->left = r_l;
            r_l->right = curr;
        }
    }
    first->left = last;
    last->right = first;
}

TreeNode* convert(TreeNode* curr){
    if(!curr) return NULL;
    TreeNode* first = NULL;
    TreeNode* last = NULL;
    convert_(curr, first, last);
    return first;
}

int main(){
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    n4.left = &n2;
    n4.right = &n5;
    n2.left = &n1;
    n2.right = &n3;
    TreeNode* res = convert(&n4);
    TreeNode* curr = res;
    do{
        std::cout<<"curr: "<<curr->val<<", curr->left: "<<curr->left->val<<", curr->right: "<<curr->right->val<<std::endl;
        curr = curr->right;
    }while(curr != res);
    return 0;
}
