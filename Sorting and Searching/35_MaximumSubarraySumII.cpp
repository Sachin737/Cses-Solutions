// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;cin>>n>>a>>b;
    vector<long long>v(n);
    for(auto &x:v)cin>>x;

    for(int i=1;i<n;i++){
        v[i] += v[i-1];
    }


    multiset<long long>ms={0};

    long long res = LLONG_MIN;

    for(int i=a-1;i<n;i++){
        // find mn in ms;
        auto it = ms.begin();
        res = max(res,v[i] - (*it));
        // cout<<res<<" "; 
        if(i-b>=0)ms.erase(ms.find(v[i-b]));
        if(i-b==-1)ms.erase(ms.find(0));
        
        ms.insert(v[i-a+1]);
    }


    cout<<res;
    
    

    return 0;
}