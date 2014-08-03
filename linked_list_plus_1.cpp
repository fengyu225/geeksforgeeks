#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct node {
    int val;
    struct node* next;
};


void print_list(struct node* root){
    while(root){
        printf("%d ", root->val);
        root = root->next;
    }
    printf("\n");
}

node* plus_1(node* head, int& carry){
    if(head && !head->next){
        if(head->val==9){
            carry = 1;
            head->val = 0;
        }
        else{
            head->val += 1;
            carry = 0;
        }
        return head;
    }
    node* second = plus_1(head->next,carry);
    if(carry==0)
        return head;
    else if(head->val<9){
        head->val += 1;
        carry = 0;
    }
    else{
        carry = 1;
        head->val = 0;
    }
    return head;
}

int main(){
    struct node n0 = {.val=9,.next=NULL};
    struct node n1 = {.val=9,.next=NULL};
    struct node n2 = {.val=9,.next=NULL};
    struct node n3 = {.val=9,.next=NULL};
    struct node n4 = {.val=9,.next=NULL};
    struct node n5 = {.val=9,.next=NULL};
    n0.next=&n1;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    int carry;
    node* res;
    struct node* result = plus_1(&n0,carry);
    if(carry == 1){
        struct node x = {.val=1,.next=result};
        res = &x;
    }
    else
        res = result;
    print_list(res);
    return 0;
}

