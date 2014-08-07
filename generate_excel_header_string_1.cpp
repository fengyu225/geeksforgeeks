#include "header.h"

string get(int n){
    string res;
    while(n>0){
        string temp;
        temp += ((n-1)%26+'A');
        res = temp+res;
        n = (n-1)/26;
    }
    return res;
}

int main(){
    std::cout<<get(26)<<std::endl;
    std::cout<<get(51)<<std::endl;
    std::cout<<get(52)<<std::endl;
    std::cout<<get(80)<<std::endl;
    std::cout<<get(676)<<std::endl;
    std::cout<<get(702)<<std::endl;
    std::cout<<get(705)<<std::endl;
    return 0;
}
