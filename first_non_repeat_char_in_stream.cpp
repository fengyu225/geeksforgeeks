#include "header.h"

struct ListNode {
    char val;
    ListNode *next;
    ListNode *prev;
    ListNode(char x) : val(x), next(this), prev(this) {}
};

void get_first_non_repeat(string s){
    ListNode* head = NULL;
    ListNode* tail = NULL;
    ListNode* ptr_arr[256] = {NULL};
    bool duplicate[256] = {false};
    for(int i=0; i<s.size(); i++){
        if(duplicate[s[i]]){
            std::cout<<"at time "<<i<<", first non repeat char is: "<<head->val<<std::endl;
            continue;
        }
        if(ptr_arr[s[i]] == NULL){
            ListNode* x = new ListNode(s[i]);
            ptr_arr[s[i]] = x;
            if(head){
                tail->next = x;
                x->prev = tail;
                x->next = head;
                head->prev = x;
                tail = x;
            }
            else{
                head = x;
                tail = x;
            }
            std::cout<<"at time "<<i<<", first non repeat char is: "<<head->val<<std::endl;
        }
        else{
            ListNode* x = ptr_arr[s[i]];
            ptr_arr[s[i]] = NULL;
            duplicate[s[i]] = true;
            if(head->prev == head && head->next == head && head == x){
                head = tail = NULL;
            }
            else{
                x->next->prev = x->prev;
                x->prev->next = x->next;
                if(head == x)
                    head = x->next;
                if(tail == x)
                    tail = x->prev;
            }
            std::cout<<"at time "<<i<<", first non repeat char is: "<<head->val<<std::endl;
        }
    }
}

int main(){
    get_first_non_repeat("geeksforgeeksandgeeksquizfor");
    return 0;
}
