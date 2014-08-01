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
//    if(head->next == NULL){
//        first = second = head;
//        second->next = NULL;
//        return;
//    }
    ListNode* ls = NULL, *le = NULL, *rs = NULL, *re = NULL;
    ListNode* curr = head->next;
    head->next = NULL;
    while(curr){
        ListNode* x = curr->next;
        if(curr->val<=head->val){
            if(!ls)
                ls = le = curr;
            else{
                le->next = curr;
                le = curr;
            }
            le->next = NULL;
        }
        else{
            if(!rs)
                rs = re = curr;
            else{
                re->next = curr;
                re = curr;
            }
            re->next = NULL;
        }
        curr = x;
    }
    ListNode* l_f = NULL, *l_s = NULL, *r_f = NULL, *r_s = NULL;
    sort(ls, l_f, l_s);
    sort(rs, r_f, r_s);
    first = l_f?l_f:head;
    second = r_s?r_s:head;
    if(l_f)
        l_s->next = head;
    if(r_f)
        head->next = r_f;
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
