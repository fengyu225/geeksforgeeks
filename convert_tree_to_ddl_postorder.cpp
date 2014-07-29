#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct DLLNode {
    int val;
    DLLNode* prev, *next;
    DLLNode(int x):val(x),prev(NULL),next(NULL){}
};

DLLNode* convert(TreeNode* root){
    return NULL;
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
    DLLNode* res = convert(&n1);
    DLLNode* curr = res;
    do{
        if(!curr) break;
        cout<<curr->val<<", left: "<<curr->prev->val<<" right: "<<curr->next->val<<endl;
        curr = curr->next;
    }while(curr != res);
    return 0;
}
