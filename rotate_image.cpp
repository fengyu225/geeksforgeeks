#include "header.h"

using namespace std;

void rotate(vector<vector<int> > &matrix) {
    int sz = matrix.size();
    for(int i=0; i<sz/2; i++){
        int first = i;
        int last = sz-1-i;
        for(int j=i;j<sz-i-1;j++){
            int offset = j-first;
            int x = matrix[i][j];
            matrix[i][j] = matrix[last-offset][i];
            matrix[last-offset][i] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[j][last];
            matrix[j][last] = x;
        }
    }
}

int main(){
    int arr0[] = {1, 2, 3};
    int arr1[] = {4, 5, 6};
    int arr2[] = {7, 8, 9};
    vector<vector<int> > matrix;
    matrix.push_back(vector<int>(arr0, arr0+sizeof(arr0)/sizeof(arr0[0])));
    matrix.push_back(vector<int>(arr1, arr1+sizeof(arr1)/sizeof(arr1[0])));
    matrix.push_back(vector<int>(arr2, arr2+sizeof(arr2)/sizeof(arr2[0])));
    rotate(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
