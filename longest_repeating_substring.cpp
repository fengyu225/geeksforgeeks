#include "header.h"

class comp{
    public:
        bool operator() (char* a, char *b){
            return strcmp(a,b)<0;
        }
};

int get_longest_prefix(char* a, char* b, char* c){
    char* a_curr = a;
    char* b_curr = b;
    int max_len = 0;
    while(*a_curr && *b_curr && *a_curr==*b_curr){
        *c = *a_curr;
        a_curr++;
        b_curr++;
        c++;
        max_len++;
    }
    *c = '\0';
}

char* lrs(char* s){
    int size = strlen(s);
    if(size == 0 || size == 1) return s;
    char *arr[size];
    for(int i=0; i<size; i++)
        arr[i] = &s[i];
    std::sort(arr,arr+size,comp());
    char* res = new char[size];
    char* temp = new char[size];
    int max = INT_MIN;
    for(int i=0; i<size-1; i++){
        char* a = arr[i];
        char* b = arr[i+1];
        int x = get_longest_prefix(a,b,temp);
        if(x>max){
            max = x;
            strcpy(res,temp);
        }
    }
    return res;
}

int main(){
    char s0[] = "banana";
    char s1[] = "abc";
    cout<<lrs(s0)<<endl;
    cout<<lrs(s1)<<endl;
    return 0;
}
