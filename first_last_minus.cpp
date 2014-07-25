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
        if(i==n-1) end=curr;
    }
    return result;
}

ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* next = curr->next;
    head->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr; 
}

ListNode* minus(ListNode* head){
    if(!head) return NULL;
    if(!head->next){
        head->val = 0;
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast){
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        if(!fast) break;
        slow = slow->next;
    }
    ListNode* x = slow->next;
    ListNode* new_head = reverse(x);
    ListNode* curr = head;
    ListNode* curr1 = new_head;
    while(curr->next != curr1){
        if(curr1 == NULL){
            curr->val = 0;
            break;
        }
        curr->val = curr1->val-curr->val;
        curr = curr->next;
        curr1 = curr1->next;
    }
    if(curr->next == curr1)
        curr->val = curr1->val-curr->val;
    slow->next = reverse(new_head);
    return head;
}

int main(){
    int arr[] = {3, 8, 1};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* r = minus(l);
    while(r){
        cout<<r->val<<" ";
        r = r->next;
    }
    cout<<endl;
    return 0;
}
