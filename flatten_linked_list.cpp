#include "header.h"

struct ListNode {
    int val;
    ListNode *next, *child;
    ListNode(int x) : val(x), next(NULL), child(NULL) {}
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

ListNode* flatten(ListNode* head){
    ListNode* tail = NULL;
    ListNode* curr = head, *next_start = NULL, *next_end = NULL;
    tail = NULL;
    while(1){
        if(curr){
            if(curr->child){
                if(!next_start)
                    next_start = next_end = curr->child;
                else
                    next_end->next = curr->child;
                while(next_end->next) next_end = next_end->next;
            }
            if(tail){
                tail->next = curr;
                tail = tail->next;
            }
            else
                tail = curr;
            curr = curr->next;
        }
        else{
            if(!next_start) break;
            curr = next_start;
            next_start = next_end = NULL;
        }
    }
    return head;
}

int main(){
    int arr0[] = {10, 5, 12, 7, 11};
    int arr1[] = {4, 20, 13};
    int arr2[] = {17, 6};
    int arr3[] = {9, 8};
    int arr4[] = {19, 15};
    int arr5[] = {2};
    int arr6[] = {16};
    int arr7[] = {3};
    ListNode* l0 = create_list(arr0, sizeof(arr0)/sizeof(arr0[0]));
    ListNode* l1 = create_list(arr1, sizeof(arr1)/sizeof(arr1[0]));
    ListNode* l2 = create_list(arr2, sizeof(arr2)/sizeof(arr2[0]));
    ListNode* l3 = create_list(arr3, sizeof(arr3)/sizeof(arr3[0]));
    ListNode* l4 = create_list(arr4, sizeof(arr4)/sizeof(arr4[0]));
    ListNode* l5 = create_list(arr5, sizeof(arr5)/sizeof(arr5[0]));
    ListNode* l6 = create_list(arr6, sizeof(arr6)/sizeof(arr6[0]));
    ListNode* l7 = create_list(arr7, sizeof(arr7)/sizeof(arr7[0]));
    l0->child = l1;
    l0->next->next->next->child = l2;
    l1->next->child = l5;
    l1->next->next->child = l6;
    l6->child = l7;
    l2->child = l3;
    l3->child = l4;
    ListNode* res = flatten(l0);
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
