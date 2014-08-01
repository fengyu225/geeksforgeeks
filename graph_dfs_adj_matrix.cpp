#include "header.h"

#define MAX_V 50


void dfs_0(int matrix[MAX_V][MAX_V], bool visited[], int tree_edge[MAX_V][MAX_V], int v, int i){
    cout<<"visiting "<<i<<endl;
    visited[i] = true;
    for(int j=0; j<v; j++){
        if(matrix[i][j] && !visited[j]){
            tree_edge[i][j] = 1;
            dfs_0(matrix,visited,tree_edge,v,j);
        }
    }
}

void dfs_adj_matrix(int matrix[MAX_V][MAX_V], int v){
    bool visited[v];
    int tree_edge[MAX_V][MAX_V];
    for(int i=0; i<v; i++) visited[i] = false;
    memset(tree_edge,0,sizeof(tree_edge));
    for(int i=0; i<v; i++){
        if(!visited[i])
            dfs_0(matrix,visited,tree_edge,v,i);
    }
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            if(tree_edge[i][j])
                cout<<"edge: "<<i<<" to "<<j<<endl;
}

int main(){
    int matrix[MAX_V][MAX_V];
    memset(matrix,0,sizeof(matrix));
    matrix[0][1] = 1;
    matrix[0][3] = 1;
    matrix[1][4] = 1;
    matrix[0][4] = 1;
    matrix[2][4] = 1;
    matrix[2][5] = 1;
    matrix[3][1] = 1;
    matrix[5][5] = 1;
    dfs_adj_matrix(matrix,6);
    return 0;
}
