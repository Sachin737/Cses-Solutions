// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    vector<int>v(n);
    for(auto &x:v)cin>>x;

    long long mx = LLONG_MIN, cur = 0;

    for(int i=0;i<n;i++){
        cur += v[i];
        mx=max(mx,cur);
        if(cur < 0)cur = 0;
    }

    cout<<mx<<"\n";
    
    return 0;
}