#include "header.h"

#define MAX_V 50

void dfs_0(int matrix[MAX_V][MAX_V], bool visited[], int v, int i){
    cout<<"visiting "<<i<<endl;
    visited[i] = true;
    for(int j=0; j<v; j++){
        if(matrix[i][j] && !visited[j])
            dfs_0(matrix,visited,v,j);
    }
}

void dfs_adj_matrix(int matrix[MAX_V][MAX_V], int v){
    bool visited[v];
    for(int i=0; i<v; i++) visited[i] = false;
    for(int i=0; i<v; i++){
        if(!visited[i])
            dfs_0(matrix,visited,v,i);
    }
}

int main(){
    int matrix[MAX_V][MAX_V];
    memset(matrix,0,sizeof(matrix));
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][0] = 1;
    matrix[2][3] = 1;
    matrix[3][3] = 1;
    matrix[0][4] = 1;
    dfs_adj_matrix(matrix,5);
    return 0;
}
