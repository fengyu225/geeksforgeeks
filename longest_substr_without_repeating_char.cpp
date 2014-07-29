#include "header.h"

char* longestUniqueSubstr(char* str){
    char* s=str;
    int l=0,r=0;
    int size = strlen(str);
    int count[256];
    memset(count,0,sizeof(count));
    int max = INT_MIN;
    while(r<size){
        count[str[r]]++;
        if(count[str[r]]>1){
            do{
                count[str[l]]--;
                l++;
            }while(l<=r && str[l] != str[r]);
        }
        else{
            if(r-l+1>max){
                max=r-l+1;
                s=&str[l];
            }
        }
        r++;
    }
    s[max] = '\0';
    return s;
}

int main()
{
    //char str[] = "ABDEFGABEF";
    char str[] = "AAA";
    printf("The input string is %s \n", str);
    char* res =  longestUniqueSubstr(str);
    cout<<"The length of the longest non-repeating character substring is "<<res<<endl;
    return 0;
}
