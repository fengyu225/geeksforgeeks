#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void get_diameter_helper(TreeNode* root, vector<TreeNode*>& longest_path, vector<TreeNode*>& res){
    if(!root){
        longest_path.clear();
        res.clear();
        return;
    }
    vector<TreeNode*> l_long;
    vector<TreeNode*> r_long;
    vector<TreeNode*> l_res;
    vector<TreeNode*> r_res;
    get_diameter_helper(root->left,l_long,l_res);
    get_diameter_helper(root->right,r_long,r_res);
    vector<TreeNode*> temp = l_res.size()>r_res.size()?l_res:r_res;
    if(temp.size()>l_long.size()+r_long.size()+1)
        res = temp;
    else{
        vector<TreeNode*> x = l_long;
        std::reverse(x.begin(), x.end());
        x.push_back(root);
        x.insert(x.end(), r_long.begin(), r_long.end());
        res = x;
    }
    if(l_long.size()>r_long.size())
        longest_path = l_long;
    else
        longest_path = r_long;
    longest_path.insert(longest_path.begin(),root);
}

vector<TreeNode*> get_diameter(TreeNode* root){
    vector<TreeNode*> res;
    vector<TreeNode*> longest_path;
    get_diameter_helper(root,longest_path,res);
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
    vector<TreeNode*> res = get_diameter(&n1);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]->val<<" ";
    cout<<endl;
    return 0;
}
    
