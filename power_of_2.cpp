#include "header.h"

bool is_power_of_2(int n){
    if(n<0) return false;
    if(n == 0) return true;
    while(n>0 && (n&1)==0) n = n>>1;
    if(n == 1) return true;
    else return false;
}

int main(){
    cout<<is_power_of_2(2)<<endl;
    cout<<is_power_of_2(1024)<<endl;
    cout<<is_power_of_2(1024*2048)<<endl;
    cout<<is_power_of_2(INT_MAX)<<endl;
    cout<<is_power_of_2(-100)<<endl;
    return 0;
}
