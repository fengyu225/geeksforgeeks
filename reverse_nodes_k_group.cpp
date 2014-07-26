#include "header.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(int arr[], int n){
    ListNode* result = NULL;
    ListNode* curr = NULL;
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

void reverse(ListNode* head, ListNode* tail){
    if(!tail || !head || head == tail) return;
    ListNode* curr = head;
    ListNode* next = curr->next;
    while(curr != tail){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode* last_tail = NULL;
    ListNode* res = NULL;
    ListNode* first = head;
    ListNode* last = head;
    while(1){
        for(int i=0; i<k-1; i++){
            if(!last) break;
            last = last->next;
        }
        if(!last){
            res = res?res:first;
            if(last_tail) last_tail->next = first;
            break;
        }
        ListNode* x = last->next;
        reverse(first,last);
        if(last_tail){
            last_tail->next = last;
            last_tail = first;
        }
        else{
            res = last;
            last_tail = first;
        }
        first=last=x;
    }
    return res;
}

int main(){
//    int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = reverseKGroup(l,2);
    while(r){
        printf("%d ", r->val);
        r = r->next;
    }
    printf("\n");
    return 0;
}
