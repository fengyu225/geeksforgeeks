#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* root, int& sum){
    if(!root){
        sum = 0;
        return true;
    }
    if(!root->left && !root->right){
        sum = root->val;
        return true;
    }
    int l_sum = 0;
    bool l_b = check(root->left,l_sum);
    int r_sum = 0;
    bool r_b = check(root->right,r_sum);
//    cout<<"current: "<<root->val<<" l_sum = "<<l_sum<<" r_sum = "<<r_sum<<" l_b: "<<l_b<<" r_b: "<<r_b<<endl;
    sum = l_sum+r_sum+root->val;
    if(l_sum+r_sum == root->val){
        return l_b&&r_b;
    }
    else
        return false;
}

bool is_sum_tree(TreeNode* root){
    if(!root) return false;
    int sum = 0;
    return check(root,sum);
}

int main(){
/*

          26
        /   \
      10     3
    /    \     \
  4      6      3

 */
    struct TreeNode n4(4);
    struct TreeNode n5(6);
    struct TreeNode n7(3);
    struct TreeNode n2(10);
    struct TreeNode n3(3);
    struct TreeNode n1(26);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    bool res = is_sum_tree(&n1);
    cout<<res<<endl;
    return 0;
}
