#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool is_cousin(TreeNode* root, TreeNode* a, TreeNode* b){
    if(!a || !b || !root || a==b) return false;
    queue<TreeNode*> curr_l, next_l;
    curr_l.push(root);
    queue<TreeNode*> qs[2] = {curr_l, next_l};
    int curr = 0;
    int found=0;
    while(!qs[curr%2].empty()){
        TreeNode* x = qs[curr%2].front();
        qs[curr%2].pop();
        if(x->left == a && x->right == b || x->left == b && x->right == a) break;
        if(x->left){
            qs[(curr+1)%2].push(x->left);
            if(x->left == a || x->left == b) found++;
        }
        if(x->right){
            qs[(curr+1)%2].push(x->right);
            if(x->right == a || x->right == b) found++;
        }
        if(qs[curr%2].empty()){
            if(found == 2) return true;
            if(found == 1) break;
            curr++;
            found = 0;
        }
    }
    return false;
}

vector<TreeNode*> get_cousins(TreeNode* root, TreeNode* a){
    vector<TreeNode*> res;
    if(!a || !root || a==root) return res;
    queue<TreeNode*> curr_l, next_l;
    curr_l.push(root);
    queue<TreeNode*> qs[2] = {curr_l, next_l};
    int curr = 0;
    bool this_level = false;
    while(!qs[curr%2].empty()){
        TreeNode* x = qs[curr%2].front();
        qs[curr%2].pop();
        if(x->left == a || x->right == a){
            this_level = true;
            continue;
        }
        if(x->left){
            qs[(curr+1)%2].push(x->left);
        }
        if(x->right){
            qs[(curr+1)%2].push(x->right);
        }
        if(qs[curr%2].empty()){
            if(this_level){
                while(!qs[(curr+1)%2].empty()){
                    res.push_back(qs[(curr+1)%2].front());
                    qs[(curr+1)%2].pop();
                }
                break;
            }
            curr++;
        }
    }
    return res;
}

int main(){
    struct TreeNode n4(4);
    struct TreeNode n5(5);
    struct TreeNode n7(7);
    struct TreeNode n8(8);
    struct TreeNode n9(9);
    struct TreeNode n2(2);
    struct TreeNode n3(3);
    struct TreeNode n1(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    n7.right = &n8;
    n5.right = &n9;
    bool res = is_cousin(&n1, &n4, &n5);
    cout<<res<<endl;
    vector<TreeNode*> res_v = get_cousins(&n1, &n9);
    for(int i=0; i<res_v.size(); i++)
        cout<<res_v[i]->val<<" ";
    cout<<endl;
    return 0;
}
