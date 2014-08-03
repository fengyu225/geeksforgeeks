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

ListNode* reverse(ListNode* begin, ListNode* end){
    ListNode* curr = begin;
    ListNode* next = begin->next;
    curr->next = NULL;
    while(next && next != end){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode* first = head;
    ListNode* second = head;
    ListNode* res = NULL;
    ListNode* last_tail = NULL;
    while(1){
        for(int i=0; i<k && second; i++, second = second->next);
        if(!second){
            if(res)
                last_tail->next = first;
            else
                res = first;
            break;
        }
        else{
            ListNode* new_head = reverse(first,second);
            if(res){
                last_tail->next = new_head;
                last_tail = first;
            }
            else{
                res = new_head;
                last_tail = first;
            }
            first = second;
        }
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
