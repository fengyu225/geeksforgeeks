/*
poj2488
http://en.wikipedia.org/wiki/Knight%27s_tour
http://www.geeksforgeeks.org/backtracking-set-1-the-knights-tour-problem/
The knight is placed on the first block of an empty board and, moving according to the rules of chess, must visit each square exactly once.
 */
#include<stdio.h>
#include<stdbool.h>

#define M 26
#define N 26

int x_move[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int y_move[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool done = false;


void knight_tour(bool visited[M][N], int curr_x, int curr_y, int path_x[M*N], int path_y[M*N], int n, int bound_x, int bound_y){
    if(done == true)
        return;
    if(n == bound_x*bound_y){
        for(int i=0; i<n; i++){
            printf("%c%d", path_x[i]+'A', path_y[i]+1);
        }
        done = true;
        return;
    }
    for(int i=0; i<8; i++){
        int new_x = curr_x+x_move[i];
        int new_y = curr_y+y_move[i];
        if(
                new_x>=0 && new_y>=0 && new_x<bound_x && new_y<bound_y && 
                visited[new_x][new_y] == false
          ){
            path_x[n] = new_x;
            path_y[n] = new_y;
            visited[new_x][new_y] = true;
            knight_tour(visited, new_x, new_y, path_x, path_y, n+1, bound_x, bound_y);
            visited[new_x][new_y] = false;
        }
    }
}

int main(){
    bool visited[M][N];
    int path_x[M*N];
    int path_y[M*N];
    int n;
    int bound_x, bound_y;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d %d", &bound_y, &bound_x);
        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++){
                visited[i][j] = false;
                path_x[i*j] = -1;
                path_y[i*j] = -1;
            }
        path_x[0] = 0;
        path_y[0] = 0;
        visited[0][0] = true;
        done = false;
        printf("Scenario #%d:\n", i+1);
        knight_tour(visited, 0, 0, path_x, path_y, 1, bound_x, bound_y);
        if(!done)
            printf("impossible");
        if(i != n-1)
            printf("\n\n");
    }
    return 0;
}
