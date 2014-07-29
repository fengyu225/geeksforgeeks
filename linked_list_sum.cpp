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

int get_list_length(node* lst){
    int res=0;
    while(lst){
        res++;
        lst = lst->next;
    }
    return res;
}

node* get_sum(node* first, node* second){
    int l=0,s=0;

    return first;
}


int main(){
    struct node n0 = {.val=5,.next=NULL};
    struct node n1 = {.val=6,.next=NULL};
    struct node n2 = {.val=3,.next=NULL};
    struct node n3 = {.val=8,.next=NULL};
    struct node n4 = {.val=4,.next=NULL};
    struct node n5 = {.val=2,.next=NULL};
    n0.next=&n1;
    n1.next=&n2;
    n3.next=&n4;
    n4.next=&n5;
    struct node* result = get_sum(&n0, &n3);
    if(!result)
        printf("no cycle\n");
    else
        print_list(result);
    return 0;
}

