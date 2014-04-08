/*
   Print all possible paths from top left to bottom right of a mXn matrix
   The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
 */

#include<stdio.h>

void print_path(int arr[2][3], int m, int n, int curr_x, int curr_y, int* res, int res_curr){
    if(res_curr == m+n-1){
        for(int i=0; i<res_curr; i++)
            printf("%d ", res[i]);
        printf("\n");
        return;
    }
    if(curr_x<m && curr_y<n){
        res[res_curr] = arr[curr_x][curr_y];
        print_path(arr,m,n,curr_x+1,curr_y,res,res_curr+1);
        print_path(arr,m,n,curr_x,curr_y+1,res,res_curr+1);
    }
}

int main(){
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int res[4];
    print_path(mat, 2, 3, 0, 0, res, 0);
    return 0;
}
