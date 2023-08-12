// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
 
int main()
{
    int n;cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        string s = to_string(i);
        for(auto &x:s){
            int p = (x - '0');
            if(p<=i)dp[i] = min(1+dp[i-p],dp[i]);
        }
    }
    cout<<dp[n]<<"\n";
 
 
 
    return 0;   
}