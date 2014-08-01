#include "header.h"

#define MAX_V 50

struct GraphNode{
    int val;
    bool visited;
    list<GraphNode*> children;
    GraphNode(int v):val(v),visited(false){}
};

void _dfs(GraphNode* node){
    cout<<"visiting "<<node->val<<endl;
    node->visited = true;
    list<GraphNode*> children = node->children;
    list<GraphNode*>::iterator iter = children.begin();
    for(;iter != children.end(); iter++)
        if((*iter)->visited == false){
            cout<<"going from "<<node->val<<" to "<<(*iter)->val<<endl;
            (*iter)->visited = true;
            _dfs(*iter);
        }
}

void dfs(GraphNode nodes[], int v){
    for(int i=0; i<v; i++)
        if(!nodes[i].visited)
            _dfs(&nodes[i]);
}

int main(){
    GraphNode n0(0);
    GraphNode n1(1);
    GraphNode n2(2);
    GraphNode n3(3);
    GraphNode n4(4);
    GraphNode n5(5);
    n0.children.push_back(&n1);
    n0.children.push_back(&n3);
    n1.children.push_back(&n4);
    n2.children.push_back(&n4);
    n2.children.push_back(&n5);
    n3.children.push_back(&n1);
    n4.children.push_back(&n3);
    n5.children.push_back(&n5);
    GraphNode nodes[6] = {n0, n1, n2, n3, n4, n5};
    dfs(nodes, sizeof(nodes)/sizeof(nodes[0]));
    return 0;
}
