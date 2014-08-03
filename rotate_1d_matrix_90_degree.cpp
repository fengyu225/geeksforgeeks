#include "header.h"

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int get_next(int curr, int r_size){
    int c = curr%r_size;
    int r = (curr-c)/r_size;
    return c*r_size+r_size-1-r;
}

void rotate(int matrix[], int row, int col){
    bool visited[row*col];
    for(int i=0; i<row*col; i++) visited[i] = false;
    int curr = 0;
    int cycle_start, next;
    int size = row*col;
    while(curr<size){
        cycle_start = curr;
        int last_val = matrix[curr];
        do{
            next = get_next(curr,row);
            int x = matrix[next];
            matrix[next] = last_val;
            last_val = x;
            visited[curr] = true;
            if(curr == next) break;
            curr = next;
        }while(curr != cycle_start);
        for(curr=0; curr<size && visited[curr];curr++);
    }
}

int main(){
    int matrix[] = {1, 2, 3, 4, 5, 6, 7, 8};
    rotate(matrix, 2, 4);
    for(int i=0; i<sizeof(matrix)/sizeof(matrix[0]); i++)
        cout<<matrix[i]<<" ";
    cout<<endl;
    return 0;
}
