/*
 * Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to find the number of ways the floor can be tiled.
 */

#include "header.h"

int get_num(int w){
    if(w==0 || w==1) return w;
    int arr[w+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<w+1;i++)
        arr[i] = arr[i-1]+arr[i-2];
    return arr[w];
}

int main(){
    cout<<get_num(4)<<endl;
    return 0;
}
