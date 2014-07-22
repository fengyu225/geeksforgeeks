#include<stdlib.h>
#include<stdio.h>

struct node{
    int val;
    struct node* next;
    node(int v): val(v),next(NULL) {}
};

int main(){
    node n1(1);
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    node n6(6);
    node n7(7);
    node n8(8);
    node n9(9);
    node n10(10);


