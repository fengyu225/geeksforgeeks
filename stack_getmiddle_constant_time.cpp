#include "header.h"

struct DLLNode{
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int v):val(v),prev(this),next(this){}
};

struct stack_mid{
    int count;
    DLLNode* head;
    DLLNode* tail;
    DLLNode* mid;
    int x;
    stack_mid():count(0),head(NULL),tail(NULL),mid(NULL),x(0){}
};

void push(stack_mid* s, int n){
    DLLNode* v = new DLLNode(n);
    if(s->head){
        s->tail->next = v;
        v->prev = s->tail;
        s->head->prev = v;
        v->next = s->head;
        s->tail = v;
        s->x = (s->x+1)%2;
        if(s->x == 1)
            s->mid = s->mid->next;
    }
    else{
        s->head = v;
        s->tail = v;
        s->mid = v;
        s->x=1;
    }
}

int pop(stack_mid* s){
    if(!s->head){
        return INT_MIN;
    }
    if(s->head == s->tail){
        int ret = s->head->val;
        delete s->head;
        s->head = s->tail = NULL;
        s->mid = NULL;
        s->x = 0;
        return ret;
    }
    else{
        s->x = (s->x-1)%2;
        if(s->x == 0)
            s->mid = s->mid->prev;
        DLLNode* temp_n = s->tail;
        int ret = temp_n->val;
        s->tail = s->tail->prev;
        s->tail->next = s->head;
        s->head->prev = s->tail;
        delete temp_n;
        return ret;
    }
}

int findMiddle(stack_mid* s){
    if(s->mid)
        return s->mid->val;
    else
        return INT_MIN;
}
//
//int deleteMiddle(stack_mid* s){
//
//}


int main(){
    stack_mid s;
    cout<<findMiddle(&s)<<endl;
    push(&s,0);
    cout<<findMiddle(&s)<<endl;
    push(&s,1);
    cout<<findMiddle(&s)<<endl;
    push(&s,2);
    cout<<findMiddle(&s)<<endl;
    push(&s,3);
    cout<<findMiddle(&s)<<endl;
    push(&s,4);
    cout<<findMiddle(&s)<<endl;
    push(&s,5);
    cout<<findMiddle(&s)<<endl;
    push(&s,6);
    cout<<findMiddle(&s)<<endl;
    push(&s,7);
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    cout<<"pop "<<pop(&s)<<endl;
    cout<<findMiddle(&s)<<endl;
    return 0;
}
