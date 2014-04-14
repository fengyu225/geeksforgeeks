/*
 * http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 * 
 */
#include<stdio.h>

void swap(char* s, int a, int b){
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

void str_perm(char* s, int size, int curr){
    if(curr == size-1){
        for(int i=0; i<size; i++)
            printf("%c", s[i]);
        printf("\n");
        return;
    }
    for(int i=curr; i<size; i++){
        swap(s, i, curr);
        str_perm(s, size, curr+1);
        swap(s, i, curr);
    }
}

int main(){
    char s[] = "ABC";
    str_perm(s, sizeof(s)/sizeof(s[0])-1, 0);
    return 0;
}
