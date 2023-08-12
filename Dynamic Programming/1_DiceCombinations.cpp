// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
#define add(a, b) (((a % mod) + (b % mod) + mod) % mod)
 
vector<long long>dp;
 
long long go(long long n){
    if(!n)return 1;
    if(dp[n]!=-1)return dp[n];
    long long ans = 0;
    for(long long i=1;i<=6;i++){
        if(i<=n){
            ans=add(ans,go(n-i));
        }
    }
    return dp[n]=ans%mod;
}
 
int main()
{
    long long n;cin >> n;
    dp.assign(n+1,-1);
    long long res = go(n);
    cout << res << "\n";
    return 0;   
}