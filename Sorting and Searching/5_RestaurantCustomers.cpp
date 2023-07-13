// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<pair<int,int>>v(n);
    map<int,int>mp;

    for(auto &x:v){
        cin>>x.first>>x.second;
        mp[x.first]++;
        mp[x.second+1]--;
    }

    vector<int>res;
    for(auto &x:mp){
        res.push_back(x.second);
    }
    
    int ans = res[0];
    for(int i=1;i<res.size();i++){
        res[i]+=res[i-1];
        ans=max(ans,res[i]);
    }
    cout<<ans;

    return 0;
}