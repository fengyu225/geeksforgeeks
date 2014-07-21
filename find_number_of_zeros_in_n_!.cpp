#include "header.h"

int find(int n){
    if(n == 0) return 0;
    int res = 0;
    while(n/5>0){
        res += n/5;
        n = n/5;
    }
    return res;
}

int main(){
    std::cout<<find(5)<<std::endl;
    std::cout<<find(100)<<std::endl;
    std::cout<<find(500)<<std::endl;
    std::cout<<find(1000)<<std::endl;
    return 0;
}
