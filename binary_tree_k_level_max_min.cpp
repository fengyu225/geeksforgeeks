#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void get_min_max(TreeNode* root, int curr_level, int k, int& min, int& max){
    if(!root)
        return;
    if(k == 1){
        min = max = root->val;
        return;
    }
    if(curr_level == k){
        min = std::min(root->val, min);
        max = std::max(root->val, max);
        return;
    }
    int l_min = INT_MAX, l_max = INT_MIN, r_min = INT_MAX, r_max = INT_MIN;
    get_min_max(root->left, curr_level+1, k, l_min, l_max);
    get_min_max(root->right, curr_level+1, k, r_min, r_max);
    min = std::min(l_min, r_min);
    max = std::max(l_max, r_max);
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
    int min = INT_MAX, max = INT_MIN;
    get_min_max(&n0, 1, 3, min, max);
    cout<<min<<" "<<max<<endl;
    return 0;
}
