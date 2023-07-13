// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n),b(m);
    multiset<int>ms;

    for(auto &x:a)cin>>x,ms.insert(x);
    for(auto &x:b)cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res = 0;

    for(int i=0;i<m;i++){
        auto it = ms.lower_bound(b[i]-k);

        if(it==ms.end())continue;
        if(abs((*it)-b[i])<=k){
            res++;
            ms.erase(it);
        }
    }

    cout<<res;

    return 0;
}