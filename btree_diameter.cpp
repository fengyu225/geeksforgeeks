#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int calc_diameter(TreeNode* curr, int &l_max, int& r_max){
    if(!curr){
        l_max=r_max=0;
        return 0;
    }
    int ll_max=0;
    int lr_max=0;
    int l = calc_diameter(curr->left,ll_max,lr_max);
    int rl_max=0;
    int rr_max=0;
    int r = calc_diameter(curr->right,rl_max,rr_max);
    l_max = std::max(ll_max,lr_max)+1;
    r_max = std::max(rl_max,rr_max)+1;
    return std::max(l_max+r_max-1, std::max(l,r));
}

int get_diameter(TreeNode* root){
    if(!root) return 0;
    int l_max=0,r_max=0;
    int res = calc_diameter(root,l_max,r_max);
    return res; 
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
    std::cout<<get_diameter(&n1)<<std::endl;
    return 0;
}
    
