#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void reverse_iter_level(TreeNode* root){
    stack<TreeNode*> curr_l, next_l;
    int curr = 0;
    stack<TreeNode*> st[2] = {curr_l, next_l};
    bool left_to_right = true;
    st[curr].push(root);
    vector<vector<int> > nodes;
    vector<int> n;
    while(!st[curr].empty()){
        TreeNode* x = st[curr].top();
        n.push_back(x->val);
        st[curr].pop();
        if(left_to_right){
            if(x->left){
                st[(curr+1)%2].push(x->left);
            }
            if(x->right){
                st[(curr+1)%2].push(x->right);
            }
        }
        else{
            if(x->right){
                st[(curr+1)%2].push(x->right);
            }
            if(x->left){
                st[(curr+1)%2].push(x->left);
            }
        }
        if(st[curr].empty()){
            nodes.push_back(n);
            n.clear();
            curr = (curr+1)%2;
            left_to_right = !left_to_right;
        }
    }
    for(int i=0; i<nodes.size(); i++){
        for(int j=0; j<nodes[i].size(); j++)
            cout<<nodes[i][j]<<" ";
        cout<<endl;
    }
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
    reverse_iter_level(&n1);
    cout<<endl;
    return 0;
}
    
