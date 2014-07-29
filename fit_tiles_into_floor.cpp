/*
 * Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to find the number of ways the floor can be tiled.
 */

#include "header.h"

int get_num(int w){
    if(w==0 || w==1) return w;
    int arr[2][w+1];
    memset(arr,0,sizeof(arr));
    arr[2][0] = 1;
    arr[0][2] = 1;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=w; j++){
            arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    return arr[2][w];
}

int main(){
    cout<<get_num(6)<<endl;
    return 0;
}
