// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
 
int main()
{
    int n;cin>>n;
    vector<string>v(n);
    for(auto &x:v)cin>>x;
    vector<vector<int>>dp(n,vector<int>(n,0));
    if(v[0][0]=='*'){
        cout<<"0\n";
    }else{
 
        dp[0][0] = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i||j){
                    if(v[i][j]!='*')dp[i][j] = (i ? dp[i-1][j] : 0) + (j ? dp[i][j-1]: 0);
                    dp[i][j]%=mod;
                }
            }
        }
        cout <<dp[n-1][n-1] << "\n";
 
    }
 
    return 0;   
}
 