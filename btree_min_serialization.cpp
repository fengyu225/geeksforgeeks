#include "header.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


string serialize(TreeNode* root){
    string res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t = q.front();
        q.pop();
        if(!t)
            res += "#";
        else{
            res += std::to_string(t->val);
            q.push(t->left);
            q.push(t->right);
        }
    }
    return res;
}

TreeNode* deserialize(string s){

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
    std::cout<<serialize(&t1)<<std::endl;
    return 0;
}
