#include "header.h"

int get_first_1(int arr[], int l, int r, int size){

}

int main(){
    int arr[] = {0, 0, 0, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<get_first_1(arr,0,size-1,size)<<endl;
    return 0;
}
