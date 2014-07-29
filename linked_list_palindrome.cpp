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

int main(){
    int arr[] = {0, 1, 2, 9, 2, 1, 0};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    bool r = is_palindrome(l);
    printf("%s\n", r?"true":"false");
    return 0;
}
