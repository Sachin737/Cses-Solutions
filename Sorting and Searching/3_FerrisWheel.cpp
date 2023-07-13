// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;cin>>n>>x;
    vector<int>w(n);
    multiset<int>ms;

    for(auto &y:w)cin>>y,ms.insert(y);

    int res = 0;
    while(ms.size()){
        int cur = *ms.begin();
        ms.erase(ms.begin());

        int canFit = x-cur;
        auto it = ms.upper_bound(canFit);
        
        if(ms.size() && it!=ms.begin()){
            it--;
            ms.erase(it);
        }   
        res++;
    }
    
    cout<<res;


    return 0;
}