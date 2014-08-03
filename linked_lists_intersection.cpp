#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(int arr[], int n){
    ListNode* result = NULL;
    ListNode* curr = NULL;
    ListNode* end = NULL;
    ListNode* start = NULL;
    for(int i=0; i<n; i++){
        ListNode* x = new ListNode(arr[i]);
        if(!result)
            result = curr = x;
        else{
            curr->next = x;
            curr = curr->next;
        }
    }
    return result;
}

int get_list_len(ListNode* l){
    int res = 0;
    while(l){
        res++;
        l = l->next;
    }
    return res;
}

ListNode* get_intersection_using_len_diff(ListNode* first, ListNode* second){
    int f_len = 0, s_len = 0;
    f_len = get_list_len(first);
    s_len = get_list_len(second);
    if(s_len>f_len){
        ListNode* temp = second;
        second = first;
        first = temp;
        int x = s_len;
        s_len = f_len;
        f_len = x;
    }
    int diff = f_len - s_len;
    for(int i=0; i<diff; i++)
        first = first->next;
    while(first->val != second->val){
        first = first->next;
        second = second->next;
    }
    return first;
}

ListNode* find_cycle_start(ListNode* curr){
    if(!curr) return NULL;
    ListNode* slow = curr;
    ListNode* fast = curr;
    do{
        fast = fast->next;
        if(!fast) return NULL;
        fast = fast->next;
        slow = slow->next;
    }while(slow && fast && slow != fast);
    if(!fast || !slow) return NULL;
    slow = curr;
    if(slow == fast) return slow;
    do{
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }while(slow != fast);
    return slow;
}

ListNode* get_intersection(ListNode* first, ListNode* second){
    ListNode* curr = second;
    while(curr->next)
        curr = curr->next;
    curr->next = second;
    ListNode* res = find_cycle_start(first);
    curr->next = NULL;
    return res;
}

int main(){
    int arr[] = {3, 6, 9, 15, 30};
    int arr_1[] = {10, 15, 30};
    ListNode n0(3);
    ListNode n1(6);
    ListNode n2(9);
    ListNode n3(15);
    ListNode n4(30);
    ListNode n5(10);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n5.next = &n3;
    ListNode* res = get_intersection(&n0,&n5);
    cout<<res->val<<endl;
    return 0;
}
