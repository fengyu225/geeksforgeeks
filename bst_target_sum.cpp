#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool has_target_sum(TreeNode* root, int target){
    int res = false;
    stack<TreeNode*> left,right;

}

int main(){
    TreeNode* t0(15);
    TreeNode* t1(10);
    TreeNode* t2(20);
    TreeNode* t3(8);
    TreeNode* t4(12);
    TreeNode* t5(16);
    TreeNode* t6(25);
    t0.left = &t1;
    t0.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    bool res = has_target_sum(&t0,27);
    printf("%s\n", res?"true":"false");
    return 0;
}
