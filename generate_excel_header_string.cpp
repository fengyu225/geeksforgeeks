#include "header.h"

string get(int n){
    string res;
    while(n>0){
        int rem = n%26;
        if(rem==0){
            res+='Z';
            n=n/26-1;
        }
        else{
            res+=rem-1+'A';
            n=n/26;
        }
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
