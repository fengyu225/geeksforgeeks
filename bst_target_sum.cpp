#include "header.h"

/*
 * http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool has_target_sum(TreeNode* root, int target){
    int res = false;
    stack<TreeNode*> left,right;
    left.push(root);
    right.push(root);
    TreeNode* left_curr = NULL;
    TreeNode* right_curr = NULL;
    queue<TreeNode*> left_q,right_q;
    bool left_d = true, right_d=true;
    while(!left.empty() && !right.empty()){
        TreeNode* l_t = left.top();
        if(l_t->left){
            left.push(l_t->left);
        }
        else{
            if(left_d){
                if(left_q.empty()){
                    while(!left.empty() && left.top()->right == NULL){
                        left_q.push(left.top());
                        left.pop();
                    }
                    if(!left.empty()){
                        TreeNode* x = left.top();
                        left.pop();
                        left.push(x->right);
                        left_q.push(x);
                    }
                }
                left_curr = left_q.front();
                left_q.pop();
                left_d = false;
            }
        }
        TreeNode* r_t = right.top();
        if(r_t->right){
            right.push(r_t->right);
        }
        else{
            if(right_d){
                if(right_q.empty()){
                    while(!right.empty() && right.top()->left == NULL){
                        right_q.push(right.top());
                        right.pop();
                    }
                    if(!right.empty()){
                        TreeNode* x = right.top();
                        right.pop();
                        right.push(x->left);
                        right_q.push(x);
                    }
                }
                right_curr = right_q.front();
                right_q.pop();
                right_d = false;
            }
        }
        if(left_curr && right_curr){
            if(left_curr->val+right_curr->val == target)
                return true;
            else if(left_curr->val+right_curr->val<target)
                left_d = true;
            else
                right_d = true;
        }
    }
    return false;
}

int main(){
    TreeNode t0(15);
    TreeNode t1(10);
    TreeNode t2(20);
    TreeNode t3(8);
    TreeNode t4(12);
    TreeNode t5(16);
    TreeNode t6(25);
    TreeNode t7(13);
    TreeNode t8(17);
    t0.left = &t1;
    t0.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    t4.right = &t7;
    t5.right = &t8;
    bool res = has_target_sum(&t0,32);
    printf("%s\n", res?"true":"false");
    return 0;
}
