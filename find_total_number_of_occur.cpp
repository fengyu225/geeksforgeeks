#include "header.h"

/*
 *  Given number N < 10^7 and 0 =< K <= 9 (a digit).Find the total number of occurrences of K from 1 to N. Example N=11 and K=1 then ans=4. I was asked to write the code.
 */

int total(int n, int k){
    if(n<k) return 0;
    int x = 1;
    int res =0;
    while(log10(n)>=log10(x)){
        int temp = n/(10*x);
        if(n/x % 10 >= k) temp++;
        if((int)log10(n)>(int)log10(x) || n/x>k){
            res += temp*x;
        }
        else{
            res += (n-n/x*x+1);
        }
        x *= 10;
    }
    return res;
}

int main(){
    std::cout<<total(2,2)<<std::endl;
    return 0;
}
