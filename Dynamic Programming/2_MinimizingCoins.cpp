// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
#define add(a, b) (((a % mod) + (b % mod) + mod) % mod)
#define ll long long
 
ll n,sm;
vector<ll> v;
vector<ll>dp;
 
ll go(ll x){
    if(x==0)return 0;
    if(dp[x]!=-1)return dp[x];
    ll ans=INT_MAX;
    for(auto &y:v){
        if(y<=x){
            ans=min(ans,1+go(x-y));
        }
    }
    return dp[x]=ans;
}
int main()
{
    cin>>n>>sm;
    v.assign(n,0);
    dp.assign(sm+1,-1);
    for(auto &x:v)cin>>x;
 
    ll ans = go(sm);
    if(ans==INT_MAX)ans=-1;
    cout<<ans<<"\n";
    return 0;   
}