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
    TreeNode* res = NULL;
    if(s.size() == 0) return res;
    queue<string> q;
    for(int i=0; i<s.size(); ){
        string f = s[i]=='-'?s.substr(i,2):s.substr(i,1);
        if(s[i] == '-') i+=2;
        else i++;
        q.push(f);
    }
    res = new TreeNode(std::stoi(q.front()));
    q.pop();
    queue<TreeNode*> t_q;
    t_q.push(res);
    while(!t_q.empty()){
        TreeNode* t_q_front = t_q.front();
        t_q.pop();
        if(!t_q_front) continue;
        string left = q.front();
        q.pop();
        string right = q.front();
        q.pop();
        if(left == "#")
            t_q_front->left = NULL;
        else
            t_q_front->left = new TreeNode(std::stoi(left));
        t_q.push(t_q_front->left);
        if(right == "#")
            t_q_front->right = NULL;
        else
            t_q_front->right = new TreeNode(std::stoi(right));
        t_q.push(t_q_front->right);
    }
    return res;
}

void preorder(TreeNode* root){
    if(!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
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
    TreeNode* r = deserialize(serialize(&t1));
    preorder(r);
    printf("\n");
    return 0;
}
