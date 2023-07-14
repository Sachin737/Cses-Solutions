// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &x:v)cin >> x;

    int res = 1;
    multiset<int>ms = {v[0]};

    for(int i=1;i<n;i++){
        auto it = ms.upper_bound(v[i]);
        if(it==ms.end()){
            res++;
        }else{
            ms.erase(it);
        }
        ms.insert(v[i]);
    }

    cout<<res;

    return 0;
}