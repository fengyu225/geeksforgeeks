#include<stdio.h>
#include<stdlib.h>

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode* root){
    TreeLinkNode* head = NULL;
    TreeLinkNode* curr = NULL;
    TreeLinkNode* curr_last = root;
    while(1){
        if(curr_last){
            if(curr_last->left == NULL && curr_last->right == NULL){
                curr_last = curr_last->next;
                continue;
            }
            if(curr_last->left){
                if(head){
                    curr->next = curr_last->left;
                    curr = curr_last->left;
                }
                else{
                    head = curr_last->left;
                    curr = head;
                }
            }
            if(curr_last->right && !curr_last->left){
                if(head){
                    curr->next = curr_last->right;
                    curr = curr_last->right;
                }
                else{
                    head = curr_last->right;
                    curr = head;
                }
            }
            if(curr_last->right && curr_last->left){
                curr->next = curr_last->right;
                curr = curr_last->right;
            }
            curr_last = curr_last->next;
        }
        else{
            if(!head) break;
            else{
                curr_last = head;
                head = curr = NULL;
            }
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
    
