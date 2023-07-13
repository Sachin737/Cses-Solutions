// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;cin >> n >> a;
    vector<int>v(n);
    multiset<pair<int,int>>ms;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ms.insert({v[i],i});
    }

    for(int i=0;i<n;i++){
        int x = a-v[i];
        ms.erase({v[i],i});
        auto it = ms.lower_bound({x,0});

        if(it!=ms.end() && (*it).first==x){
            cout<<i+1<<" "<<(*it).second+1<<"\n";
            return 0;
        }
        ms.insert({v[i],i});
    }
    cout<<"IMPOSSIBLE\n";


    return 0;
}