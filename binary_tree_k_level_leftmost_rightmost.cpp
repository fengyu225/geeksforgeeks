#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void get_left_right_most(TreeNode* root, int curr_level, int k, TreeNode*& left_most, TreeNode*& right_most){
    if(!root)
        return;
    if(curr_level == k){
        left_most = left_most?left_most:root;
        right_most = root;
        return;
    }
    get_left_right_most(root->left, curr_level+1, k, left_most, right_most);
    get_left_right_most(root->right, curr_level+1, k, left_most, right_most);
}

int main(){
    TreeNode n0(3);
    TreeNode n1(9);
    TreeNode n2(20);
    TreeNode n3(15);
    TreeNode n4(7);
    TreeNode n5(8);
    TreeNode n6(10);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n5;
    n1.right = &n6;
    n2.left = &n3;
    n2.right = &n4;
    TreeNode* left_most = NULL, *right_most = NULL;
    get_left_right_most(&n0, 1, 3, left_most, right_most);
    if(left_most)
        cout<<"left_most "<<left_most->val<<endl;
    else
        cout<<"left_most NULL"<<endl;
    if(right_most)
        cout<<"right_most "<<right_most->val<<endl;
    else
        cout<<"right_most NULL"<<endl;
    return 0;
}
