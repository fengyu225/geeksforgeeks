/*
 http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/
 Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with same color. Here coloring of a graph means assignment of colors to all vertices.

Input:
1) A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is adjacency matrix representation of the graph. A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.
2) An integer m which is maximum number of colors that can be used.

Output:
An array color[V] that should have numbers from 1 to m. color[i] should represent the color assigned to the ith vertex. The code should also return false if the graph cannot be colored with m colors.
 */

#include<stdio.h>
#include<stdbool.h>

#define V 4

void m_color(int graph[V][V], int colors[V], int c_curr, int m){
    if(c_curr == V){
        for(int i=0; i<V; i++){
            printf("nodes %d has color %d\n", i, colors[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1; i<=m ; i++){
        bool safe = true;
        for(int j=0; j<c_curr;  j++){
            if(graph[j][c_curr] == 1 && colors[j] == i){
                safe = false;
                break;
            }
        }
        if(safe){
            colors[c_curr] = i;
            m_color(graph, colors, c_curr+1, m);
        }
    }
}



int main(){
    int graph[V][V] = 
    {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };        
    int colors[V] = {-1};
    colors[0] = 1; 
    m_color(graph, colors, 1, 3);
    return 0;
}
