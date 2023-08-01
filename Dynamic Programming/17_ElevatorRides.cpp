// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,x;
vector<int>v,dp;

bool go(int i,vector<int>ws){
    if(i==n){
        return true;
    }
    // if(dp[i]!=-1)return dp[i];
    int m = ws.size();
    bool res = false;
    for(int j=0;j<m;j++){
        if(ws[j]-v[i]>=0){
            ws[j] -= v[i];
            res |= go(i+1,ws);
            ws[j] += v[i];
        }
    }

    return dp[i]=(res==true);
}

int32_t main()
{
    cin >> n >> x;
    v.assign(n,0);
    for(auto &x:v)cin >> x;

    int res=n;

    for(int i=1;i<=n;i++){
        vector<int>ws(i,x);
        dp.assign(n,-1);
        bool ok = go(0,ws);
        if(ok){
            res = i;
            break;
        }
    }

    cout<<res<<"\n";

    return 0;
}