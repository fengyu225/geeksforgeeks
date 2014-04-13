/*

http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/

We have discussed Knight’s tour and Rat in a Maze problems in Set 1 and Set 2 respectively. Let us discuss N Queen as another example problem that can be solved using Backtracking.

The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. For example, following is a solution for 4 Queen problem.

The expected output is a binary matrix which has 1s for the blocks where queens are placed. For example following is the output matrix for above 4 queen solution.

              { 0,  1,  0,  0}
              { 0,  0,  0,  1}
              { 1,  0,  0,  0}
              { 0,  0,  1,  0} 
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define V 4

void n_queen(int pos[V], int n){
    if(n == V){
        for(int i=0; i<V; i++){
            printf("line %d: (%d,%d)\n", i, i, pos[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<V; i++){
        bool safe = true;
        for(int j=0; j<n; j++)
            if(pos[j] == i || abs(j-n) == abs(pos[j]-i)){
                safe = false;
                break;
            }
        if(safe){
            pos[n] = i;
            n_queen(pos, n+1);
        }
    }
}


int main(){
    int pos[V] = {-1};
    n_queen(pos, 0);
    return 0;
}
