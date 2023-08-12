#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int a,b; cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,INT_MAX));
 
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            if(i==j)
            {
                dp[i][j]=0;
                continue;
            }
            for(int cuts=1;cuts<j;cuts++)
            {
                dp[i][j] = min(dp[i][j],1 + dp[i][j-cuts] + dp[i][cuts]);
            }
            for(int cuts=1;cuts<i;cuts++)
            {
                dp[i][j] = min(dp[i][j],1 + dp[i-cuts][j] + dp[cuts][j]);
            }
        }
    }
 
    cout<<dp[a][b];
    
    return 0;
}