#include "header.h"

struct TreeNode {
 int val;
 TreeNode *left, *right;
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct LinkListNode{
    int level;
    int sum;
    LinkListNode *prev;
    LinkListNode *next;
    LinkListNode(int l,int s):level(l),sum(s),prev(NULL),next(NULL){}
};


void traverse(TreeNode* curr, int k, LinkListNode* m){
    if(!curr) return;
    if(curr->left){
        LinkListNode* prev = NULL;
        if(m->prev && m->prev->level == k-1){
            prev = m->prev;
            prev->sum += curr->left->val;
        }
        else{
            prev = new LinkListNode(k-1,curr->left->val);
            prev->next = m;
            if(m->prev){
                m->prev->next = prev;
                prev->prev = m->prev;
            }
            m->prev = prev;
        }   
        traverse(curr->left,k-1,prev);
    }
    if(curr->right){
        LinkListNode* next = NULL;
        if(m->next && m->next->level == k+1){
            next = m->next;
            next->sum += curr->right->val;
        }
        else{
            next = new LinkListNode(k+1,curr->right->val);
            next->prev = m;
            if(m->next){
                m->next->prev = next;
                next->next = m->next;
            }
            m->next = next;
        }
        traverse(curr->right,k+1,next);
    }
}


vector<int> vertical(TreeNode* root){
    vector<int> res;
    if(!root) return res;
    LinkListNode* n = new LinkListNode(0,root->val);
    traverse(root,0,n);
    LinkListNode* x = n;
    do{
        cout<<x->level<<" "<<x->sum<<endl;
        x = x->next;
    }while(x && x != n);
    x=n;
    do{
        cout<<x->level<<" "<<x->sum<<endl;
        x = x->prev;
    }while(x && x != n);
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
    vector<int> res = vertical(&n1);
    for(int i=0; i<res.size(); i++)
        std::cout<<res[i]<<" ";
    std::cout<<std::endl;
    return 0;
}
    
