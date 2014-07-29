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

bool is_palindrome(ListNode* root){

}

int main(){
    int arr[] = {0, 1, 2, 3, 2, 1, 0};
    ListNode* l = create_list(arr, sizeof(arr)/sizeof(arr[0]));
    bool r = is_palindrome_stack(l);
    printf("%s\n", r?"true":"false");
    return 0;
}
