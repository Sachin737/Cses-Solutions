// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
 
int main()
{
    int n,sm;
    cin>>n>>sm;
    vector<int> v(n);
    vector<vector<int>>dp(n+1,vector<int>(sm+1,0));
    for(auto &x:v)cin>>x;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sm;j++){
            dp[i][j]=dp[i-1][j];
            if(v[i-1]<=j){
                dp[i][j] = (dp[i][j]+dp[i][j-v[i-1]])%mod;
            }
        }
    }
    cout<<dp[n][sm]<<"\n";
 
 
    return 0;   
}
 