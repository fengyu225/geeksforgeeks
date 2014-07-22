#include "header.h"

void setZeroes(vector<vector<int> > &matrix) {
    if(matrix.size() == 0) return;
    bool row = false,col = false;
    for(int i=0; i<matrix[0].size(); i++)
        if(matrix[0][i] == 0)
            row = true;
    for(int i=0; i<matrix.size(); i++)
        if(matrix[i][0] == 0)
            col = true;
    for(int i=1; i<matrix.size(); i++){
        for(int j=1;j<matrix[i].size();j++)
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                break;
            }
    }
    for(int i=1; i<matrix[0].size(); i++){
        for(int j=1; j<matrix.size(); j++)
            if(matrix[j][i] == 0){
                matrix[0][i] = 0;
                break;
            }
    }
    for(int i=1; i<matrix.size(); i++)
        if(matrix[i][0] == 0){
            for(int j=0; j<matrix[i].size();j++)
                matrix[i][j] = 0;
        }
    for(int i=1; i<matrix[0].size(); i++)
        if(matrix[0][i] == 0){
            for(int j=0;j<matrix.size();j++)
                matrix[j][i] = 0;
        }
    if(row)
        for(int i=0; i<matrix[0].size(); i++)
            matrix[0][i] = 0;
    if(col)
        for(int i=0; i<matrix.size(); i++)
            matrix[i][0] = 0;
}

int main(){
    /*
     1, 1, 0, 0
     1, 1, 1, 1
     1, 1, 1, 1
     1, 1, 1, 0
     */
    vector<vector<int> > matrix(4, vector<int>(4, 1));
    matrix[0][3]=0;
    matrix[0][2]=0;
    matrix[3][3]=0;
    setZeroes(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return 0;
}
