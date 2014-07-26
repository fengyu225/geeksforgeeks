#include "header.h"

char* compress(char s[]){
    int size = strlen(s);
    int a=0,b=0;
    int dup = 0;
    while(b<=size){
        if(s[b] == s[a]){
            dup++;
            b++;
            continue;
        }
        if(dup>1){
            s[a+1] = dup+'0';
            for(int i=a+2;i<b;i++) s[i]='.';
        }
        dup = 0;
        a=b;
    }
    a=0;b=0;
    while(b<size){
        if(s[b] == '.') b++;
        else
            s[a++] = s[b++];
    }
    s[a] = '\0';
    return s;
}

int main(){
    char s[] = "aabbbccc";
//    char s[] = "abcdeee";
    cout<<compress(s)<<endl;
    return 0;
}
