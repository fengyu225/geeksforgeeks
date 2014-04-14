/*
 * http://www.geeksforgeeks.org/backttracking-set-2-rat-in-a-maze/
 * We have discussed Backtracking and Knight’s tour problem in Set 1. Let us discuss Rat in a Maze as another example problem that can be solved using Backtracking.
 *
 * A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
 * In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path from source to destination. Note that this is a simple version of the typical Maze problem. For example, a more complex version can be that the rat can move in 4 directions and a more complex version can be with limited number of moves.
 *
 */
#include<stdio.h>
#include<stdbool.h>

#define V 4

void maze_route(int maze[V][V], int path_x[2*V-1], int path_y[2*V-1], int curr_x, int curr_y, int n){
    if(n == 2*V-1){
        for(int i=0; i<2*V-1; i++){
            printf("(%d, %d) ", path_x[i], path_y[i]);
        }
        printf("\n");
        return;
    }
    if(maze[curr_x+1][curr_y] == 1){
        path_x[n] = curr_x+1;
        path_y[n] = curr_y;
        maze_route(maze, path_x, path_y, curr_x+1, curr_y, n+1);
    }
    if(maze[curr_x][curr_y+1] == 1){
        path_x[n] = curr_x;
        path_y[n] = curr_y+1;
        maze_route(maze, path_x, path_y, curr_x, curr_y+1, n+1);
    }
}

int main(){
    int maze[V][V] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int path_x[2*V-1] = {-1};
    int path_y[2*V-1] = {-1};
    path_x[0] = 0;
    path_y[0] = 0;
    maze_route(maze, path_x, path_y, 0, 0, 1);
    return 0;
}

