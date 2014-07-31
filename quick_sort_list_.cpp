#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head){
    if(!head){
        cout<<"head is NULL"<<endl;
        return;
    }
    do{
        cout<<head->val<<" ";
        head = head->next;
    }while(head);
    cout<<endl;
}

void sort(ListNode* head, ListNode*& first, ListNode*& second){
    if(!head){
        first = second = NULL;
        return;
    }
    if(head->next == NULL){
        first = second = head;
        second->next = NULL;
        return;
    }
    ListNode* curr_le = head; 
    ListNode* curr = head;
    cout<<"-----------------------------------"<<endl;
    cout<<"head: "<<head->val<<endl;
    print_list(head);
    ListNode* last_pre = NULL;
    while(curr->next){
        if(curr->next->val<head->val){
            ListNode* x = curr_le->next;
            ListNode* y = x?x->next:NULL;
            curr_le->next = curr->next;
            ListNode* z = curr->next->next;
            curr->next = x;
            x->next = z;
            curr_le->next->next = y;
            curr_le = curr_le->next;
        }
        if(curr->next->next == NULL) last_pre = curr;
        curr = curr->next;
    }
    print_list(head);
    cout<<"-----------------------------------"<<endl;
    cout<<endl;
    ListNode* second_head = curr_le == head?NULL:curr_le->next;
    ListNode* new_head = head->next;
    curr_le->next = NULL;
    ListNode* lh = NULL, *le = NULL, *sh = NULL, *se = NULL;
    sort(new_head, lh, le);
    sort(second_head, sh, se);
    first = lh;
    second = se;
    if(le)
        le->next = head;
    head->next = sh;
    if(se)
        se->next = NULL;
}

ListNode *sortList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode* first = NULL, *second = NULL;
    sort(head, first, second);
    return first;
}

int main(){
    ListNode l0(0);
    ListNode l1(5);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(1);
    ListNode l6(6);
    l0.next = &l1;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    ListNode* curr = sortList(&l0);
    while(curr){
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
