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

void get_k_distance(TreeNode* root, int k, unordered_set<int>& v, vector<TreeNode*>& res){
    if(!root->left && !root->right){
        v.insert(1);
        return;
    }
    unordered_set<int> l_v;
    if(root->left)
        get_k_distance(root->left,k,l_v,res);
    unordered_set<int> r_v;
    if(root->right)
        get_k_distance(root->right,k,r_v,res);
    if(l_v.find(k-1) != l_v.end() || r_v.find(k-1) != r_v.end())
        res.push_back(root);
    unordered_set<int>::iterator iter = l_v.begin();
    for(;iter != l_v.end(); iter++)
        v.insert(*iter+1);
    iter = r_v.begin();
    for(;iter != r_v.end(); iter++)
        v.insert(*iter+1);
    cout<<"curr: "<<root->val<<endl;
    iter = v.begin();
    for(;iter != v.end(); iter++)
        cout<<*iter<<" ";
    cout<<endl<<endl;
}

vector<TreeNode*> get_k_distance_nodes(TreeNode* root, int k){
    vector<TreeNode*> res;
    if(!root) return res;
    unordered_set<int> v;
    get_k_distance(root,k,v,res);
    return res;
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
    vector<TreeNode*> res = get_k_distance_nodes(&t0,3);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]->val<<" ";
    cout<<endl;
    return 0;
}
