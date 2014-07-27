#include "header.h"


struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root){
    TreeLinkNode* head = NULL;
    TreeLinkNode* tail = NULL;
    TreeLinkNode* last_curr = root;
    while(1){
        if(!last_curr){
            if(!head) break;
            last_curr = head;
            head = tail = NULL;
        }
        else{
            if(last_curr->left || !last_curr->left && last_curr->right){
                TreeLinkNode* x = last_curr->left?last_curr->left:last_curr->right;
                if(head){
                    tail->next = x;
                    cout<<"connecting "<<tail->val<<" with "<<x->val<<endl;
                    tail = x;
                }
                else{
                    head = tail = x;
                }
            }
            if(last_curr->left && last_curr->right){
                tail->next = last_curr->right;
                cout<<"connecting "<<tail->val<<" with "<<last_curr->right->val<<endl;
                tail = last_curr->right;
            }
            last_curr = last_curr->next;
        }
    }
}

int main(){
    struct TreeLinkNode n4(4);
    struct TreeLinkNode n5(5);
    struct TreeLinkNode n7(7);
    struct TreeLinkNode n2(2);
    struct TreeLinkNode n3(3);
    struct TreeLinkNode n1(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n7;
    connect(&n1);
    return 0;
}
    
