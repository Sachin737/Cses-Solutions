// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
vector<int>v;
int n,m;
vector<vector<int>>dp;
 
int go(int i,int prev){
    if(i==n)return 1;
    int res = 0;
    if(dp[i][prev]!=-1)return dp[i][prev];
    if(v[i]){
        if(abs(v[i]-prev)>1)return dp[i][prev] = 0;
        else return dp[i][prev] = go(i+1,v[i])%mod;
    }else{
        if(!prev){
            for(int j=1;j<=m;j++){
                res += go(i+1,j);
                res%=mod;
            }
        }else{
            for(int j=-1;j<=1;j++){ 
                int nval = prev+j;
                if(nval>=1&&nval<=m){
                    res += go(i+1,nval);
                    res%=mod;
                }
            }
        }
    }
    return dp[i][prev] = res%mod;;
}
 
int main()
{
    cin>>n>>m;
    v.assign(n,0);
    dp.assign(n,vector<int>(m+1,-1));
    for(auto &x:v)cin>>x;
 
    int res = go(0,v[0]); // index, prevValue
    cout << res << "\n";
 
}