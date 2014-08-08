#include "header.h"

int findMaxSum(int arr[][5], int row, int col){
    int m[row][col];
    memset(m,0,sizeof(m));
    int res = INT_MIN;
    for(int i=0; i<row; i++)
        for(int j=0;j<col;j++){
            int m_i_1_j = i>0?m[i-1][j]:0;
            int m_i_j_1 = j>0?m[i][j-1]:0;
            int m_i_1_j_1 = i>0&&j>0?m[i-1][j-1]:0;
            m[i][j] = m_i_1_j+m_i_j_1-m_i_1_j_1+arr[i][j];
        }
    int res_row_s = -1, res_row_col=-1, res_k=-1;
    for(int i=0; i<row; i++)
        for(int j=i;j<row;j++){
            int sum = 0;
            for(int k=0;k<col;k++){
                int x;
                if(k==0){
                    if(i>0)
                        x = m[j][k]-m[i-1][k];
                    else
                        x = m[j][k];
                }
                else{
                    if(i>0)
                        x = m[j][k]-m[j][k-1]-m[i-1][k]+m[i-1][k-1];
                    else
                        x = m[j][k]-m[j][k-1];
                }
                if(k==0)
                    sum = x;
                else
                    sum = std::max(x,sum+x);
                if(sum>res){
                    res_row_s = i;
                    res_row_col = j;
                    res_k=k;
                    res = sum;
                }
            }
        }
    return res;
}

int main(){
    int arr[4][5] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    cout<<findMaxSum(arr, 4, 5)<<endl;
    return 0;
}
