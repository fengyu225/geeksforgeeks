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

bool is_palindrome_stack(ListNode* root){
    if(!root) return false;
    stack<ListNode*> st;
    ListNode* curr = root;
    while(curr){
        st.push(curr);
        curr = curr->next;
    }
    curr = root;
    while(curr != st.top()){
        if(curr->val != st.top()->val) return false;
        curr = curr->next;
        if(curr == st.top()) break;
        st.pop();
    }
    return true;
}

ListNode* reverse(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* curr = head;
    ListNode* next = curr->next;
    curr->next = NULL;
    while(next){
        ListNode* temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

bool is_palindrome(ListNode* root){
    if(!root) return false;
    if(!root->next) return true;
    ListNode* slow = root;
    ListNode* fast = root;
    while(fast){
        fast = fast->next;
        if(!fast) break;
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* second_head = reverse(slow->next);
    ListNode* curr1 = root;
    ListNode* curr2 = second_head;
    while(curr2){
        if(curr1->val != curr2->val) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    slow->next = reverse(second_head);
    return true;
}

bool is_palindrome_recursive(ListNode* head, ListNode*& last, int size){
    if(!head || size == 0){
        last = NULL;
        return true;
    }
    if(size == 1){
        last = head;
        return true;
    }
    if(size == 2){
        last = head->next;
        return head->next && head->val == head->next->val;
    }
    ListNode* l = NULL;
    bool res = is_palindrome_recursive(head->next,l,size-2);
    if(!res) return false;
    last = l->next;
    return head->val == l->next->val;
}

int main(){
    int arr[] = {0, 1, 2, 1, 1, 0};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    ListNode* last = NULL;
    bool r = is_palindrome_recursive(l, last, sizeof(arr)/sizeof(arr[0]));
    printf("%s\n", r?"true":"false");
    return 0;
}
