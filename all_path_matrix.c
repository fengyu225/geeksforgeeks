/*
   Print all possible paths from top left to bottom right of a mXn matrix
   The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
 */

#include<stdio.h>

void print_path(int** arr, int m, int n, int curr_x, int curr_y, int* res, int res_curr){
    
}

int main(){
    int mat[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    int res[7];
    printAllPaths(mat, 4, 3, 0, 0, res, 0);
    return 0;
}
