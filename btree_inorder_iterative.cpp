#include "header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if(!root) return res;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        if(st.top()->left){
            st.push(st.top()->left);
            continue;
        }
        while(!st.empty() && st.top()->right == NULL){
            res.push_back(st.top()->val);
            st.pop();
        }
        if(!st.empty()){
            res.push_back(st.top()->val);
            TreeNode* curr = st.top();
            st.pop();
            st.push(curr->right);
        }
    }
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
    vector<int> res = inorderTraversal(&n1);
//    three.left = &one;
//    three.right = &two;
//    vector<int> res = postorderTraversal(&three);
    for(int i=0; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");
    return 0;
}
