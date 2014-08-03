#include "header.h"

char* compress(char s[]){
    int size = strlen(s);
    int a=0,b=0;
    int count = 0;
    do{
        while(s[a] == s[b]){
            if(a<b) s[b] = '.';
            b++;
            count++;
            continue;
        }
        if(a+1 < b)
            s[a+1] = count+'0';
        a = b;
        count = 0;
    }while(b<size);
    a=0;b=0;
    while(b<size){
        if(s[b] != '.')
            s[a++] = s[b];
        b++;
    }
    s[a] = '\0';
    return s;
}

int main(){
    //char s[] = "aabbbccc";
    char s[] = "ccc";
//    char s[] = "abcdeee";
    cout<<compress(s)<<endl;
    return 0;
}
