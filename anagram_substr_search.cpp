#include "header.h"

vector<int> search(string s, string p){
    vector<int> res;
    int need_to_find[256];
    int has_found[256];
    memset(need_to_find, 0, sizeof(need_to_find));
    memset(has_found, 0, sizeof(has_found));
    int a=0,b=0,count=0;
    for(int i=0; i<p.size(); i++) need_to_find[p[i]]++;
    for(;b<p.size();b++){
        has_found[s[b]]++;
        if(has_found[s[b]]<=need_to_find[s[b]]){
            count++;
        }
    }
    while(b<s.size()){
        if(count == p.size())
            res.push_back(a);
        if(has_found[s[a]]<=need_to_find[s[a]])
            count--;
        has_found[s[a]]--;
        a++;
        has_found[s[b]]++;
        if(has_found[s[b]]<=need_to_find[s[b]])
            count++;
        b++;
    }
    return res;
}

int main(){
    string t("BACDGABCDA");
    string p("ABCD");
    vector<int> res = search(t,p);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
