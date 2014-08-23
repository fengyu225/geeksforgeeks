#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool zigzagLevelOrder(TreeNode *root) {
    bool left_to_right = true;
    vector<vector<int> > res;
    if(!root) return true;
    stack<TreeNode*> curr_level,next_level;
    stack<TreeNode*> s_arr[2] = {curr_level,next_level};
    int curr = 0;
    vector<int> v;
    s_arr[curr].push(root);
    unordered_map<int,int> set;
    set[root->val] = 0;
    while(!s_arr[curr].empty()){
        TreeNode* top_n = s_arr[curr].top();
        s_arr[curr].pop();
        v.push_back(top_n->val);
        if(top_n->left){
            if(set.find(top_n->left->val) != set.end())
                return false;
            set[top_n->left->val] = 0;
            s_arr[(curr+1)%2].push(top_n->left);
        }
        if(top_n->right){
            if(set.find(top_n->right->val) != set.end())
                return false;
            set[top_n->right->val] = 0;
            s_arr[(curr+1)%2].push(top_n->right);
        }
        if(s_arr[curr].empty()){
            res.push_back(v);
            v.clear();
            set.clear();
            left_to_right = !left_to_right;
            curr = (curr+1)%2;
        }
    }
    return true;
}

int main(){
    TreeNode n0(3);
    TreeNode n1(9);
    TreeNode n2(20);
    TreeNode n3(15);
    TreeNode n4(8);
    TreeNode n5(8);
    TreeNode n6(10);
    n0.left = &n1;
    n0.right = &n2;
    n1.left = &n5;
    n1.right = &n6;
    n2.left = &n3;
    n2.right = &n4;
    //vector<vector<int> > res = zigzagLevelOrder(&n0);
    bool res = zigzagLevelOrder(&n0);
    cout<<res<<endl;
//    for(int i=0; i<res.size(); i++){
//        for(int j=0; j<res[i].size(); j++)
//            printf("%d ", res[i][j]);
//        printf("\n");
//    }
    return 0;
}
