#include "header.h"

/*
 * 1 represent A, 2 rep B etc and 26 rep Z. Given a number, find number of possible decoding for this number. No need to consider number starts with zero. Eg: input – 1234, output – 3(ABCD, AWD, LCD)
 *
 */

int num_decode(string s){
    if(s.size() == 1 || s.size() == 0) return s.size();
    int arr[s.size()+1];
    memset(arr,0,sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=s.size(); i++){
        if(s[i-1]-'0'>0){
            arr[i] = arr[i-1];
        }
        if(s[i-2]<'0'+2 || s[i-2]>='0'+2 && s[i-1]<'0'+7)
            arr[i] += arr[i-2];
    }
    return arr[s.size()];
}

int main(){
    std::cout<<num_decode("1234567891011")<<std::endl;
    return 0;
}
