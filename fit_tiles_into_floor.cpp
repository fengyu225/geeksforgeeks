/*
 * Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, write code to find the number of ways the floor can be tiled.
 */

#include "header.h"

int get_num(int w){
    if(w==0 || w==1) return w;
    int arr[2][w];
    memset(arr,0,sizeof(arr));

}

int main(){
    cout<<get_num(2)<<endl;
    return 0;
}
