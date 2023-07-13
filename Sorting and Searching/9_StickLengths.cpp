// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    vector<long long>v(n);
    for(auto &x:v)cin>>x;

    sort(v.begin(),v.end());
    vector<long long>pre = v;

    for(int i=1;i<n;i++){
        pre[i] += pre[i-1];
    }

    long long res = LLONG_MAX;
    
    for(int i=0;i<n;i++){
        long long suf = pre[n-1] - pre[i];
        long long pref = (i ? pre[i-1] : 0);
        
        long long x = i*v[i]-pref;
        x += suf - (n-i-1)*v[i];

        res=min(res,x); 
    }

    cout<<res;


    return 0;
}