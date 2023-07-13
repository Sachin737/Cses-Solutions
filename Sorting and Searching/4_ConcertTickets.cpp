// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;cin >> n >> m;

    vector<int>p(n),mx(m);
    multiset<int>ms;

    for(auto &x:p)cin >> x, ms.insert(x);
    for(auto &x:mx)cin >> x;

    for(auto &x:mx){
        auto it = ms.upper_bound(x);
        if(it==ms.begin()){
            cout<<"-1\n";
        }else{
            it--;
            cout<<(*it)<<"\n";
            ms.erase(it);
        }
    }

    return 0;
}