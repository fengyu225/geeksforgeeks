#include "header.h"

int* minAbsSumPair(int* arr, int size){
	std::sort(arr,arr+size);
	for(int i=0; i<size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<size<<endl;
	int* res = (int*)malloc(size*sizeof(int));
	return res;
}

int main(){
	int arr[] = {1, 60, -10, 70, -80, 85};
	int* res = minAbsSumPair(arr,sizeof(arr)/sizeof(arr[0]));
	free(res);
	return 0;
}
