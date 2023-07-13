// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;


void go(int i,set<string>&res,string cur,vector<int>&freq,int &n){
    // cout<<"\n";
    if(i==n){
        // cout<<cur<<"\n";
        res.insert(cur);
        return;
    }
    for(int j=0;j<26;j++){
        if(freq[j]){
            freq[j]--;
            cur.push_back(('a'+j));
            go(i+1,res,cur,freq,n);
            cur.pop_back();
            freq[j]++;
        }
    }
}
int main()
{
    string s;cin >> s;
    int n = s.size();
    vector<int>fr(26,0);
    for(auto &x:s){
        fr[(x-'a')]++;
    }
    set<string>res;

    go(0,res,"",fr,n);

    cout<<res.size()<<"\n";
    for(auto &x:res)cout<<x<<"\n";

    return 0;
}