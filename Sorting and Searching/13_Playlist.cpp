// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    vector<int>v(n);
    for(auto &x:v) cin >> x;

    map<int,int>id;
    for(auto &x:v)id[x]=-1;

    int l = 0, res = 0;
    for(int i=0;i<n;i++){
        if(id[v[i]]>=0){
            l = max(l,id[v[i]]+1);
        }
        id[v[i]] = i;
        res=max(res,i-l+1);
    }
    cout<<res;

    return 0;
}