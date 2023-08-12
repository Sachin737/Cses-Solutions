// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
vector<int>price,pages;
int n,x;
vector<vector<int>>dp;
 
int main()
{
    cin>>n>>x;
    price.assign(n,0);
    pages.assign(n,0);
    dp.assign(n+1,vector<int>(x+1,0));
    for(auto &y:price)cin>>y;
    for(auto &y:pages)cin>>y;
    
 
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(price[i-1]<=j)dp[i][j]=max(dp[i][j],dp[i-1][j-price[i-1]] + pages[i-1]);
        }
    }
 
    cout<<dp[n][x]<<"\n";
    return 0;   
}
 