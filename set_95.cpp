#include "header.h"

//Given a number, find the just greater number than the given number containing the same digits as the given number. Write code for this.
int find_next_greater(int n){
    if(n<10) return n;
    int temp = n;
    int a,b;
    vector<int> v;
    while(temp>=10){
        a = temp/10%10;
        b = temp%10;
        v.push_back(b);
        temp /=10;
        if(a<b)
            break;
    }
    if(temp<10) return n;
    int m = INT_MAX;
    for(int i=0; i<v.size(); i++)
        m = std::min(m,v[i]);
    vector<int>::iterator pos = std::find(v.begin(), v.end(), m);
    v.erase(pos);
    temp = temp/10*10+m;
    v.push_back(a);
    std::sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        temp *=10;
        temp += v[i];
    }
    return temp;
}

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};




int main(){
    printf("%d\n", find_next_greater(941345873));
    printf("%d\n", find_next_greater(11));
    return 0;
}
