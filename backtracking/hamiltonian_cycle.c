/*
 * http://www.geeksforgeeks.org/backtracking-set-7-hamiltonian-cycle/
 * Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in graph) from the last vertex to the first vertex of the Hamiltonian Path. Determine whether a given graph contains Hamiltonian Cycle or not. If it contains, then print the path. Following are the input and output of the required function.

Input:
A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is adjacency matrix representation of the graph. A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.

Output:
An array path[V] that should contain the Hamiltonian Path. path[i] should represent the ith vertex in the Hamiltonian Path. The code should also return false if there is no Hamiltonian Cycle in the graph.

For example, a Hamiltonian Cycle in the following graph is {0, 1, 2, 4, 3, 0}. There are more Hamiltonian Cycles in the graph like {0, 3, 4, 2, 1, 0}

(0)--(1)--(2)
 |   / \   |
 |  /   \  | 
 | /     \ |
(3)-------(4)

And the following graph doesn’t contain any Hamiltonian Cycle.

(0)--(1)--(2)
 |   / \   |
 |  /   \  | 
 | /     \ |
(3)      (4) 
 
*/
#include<stdio.h>
#include<stdbool.h>

#define V 5

void hamilton(int graph[V][V], int nodes[V], int nodes_size){
    if(nodes_size == V){
        if(graph[nodes[nodes_size-1]][0] == 1){
            for(int i=0; i<nodes_size; i++)
                printf("%d ", nodes[i]);
            printf("%d\n", 0);
        }
        return;
    }
    for(int i=0; i<V; i++){
        if(graph[nodes[nodes_size-1]][i]==1){
            bool not_seen=true;
            for(int j=0; j<nodes_size; j++)
                if(nodes[j] == i)
                    not_seen = false;
            if(not_seen){
                nodes[nodes_size] = i;
                hamilton(graph,nodes,nodes_size+1);
            }
        }
    }
}

int main(){
    int graph[V][V] = 
    {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    int nodes[V];
    nodes[0] = 0;
    hamilton(graph,nodes,1);
    int graph2[V][V] =
    {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
    };
    hamilton(graph2,nodes,1);
    return 0;
}
