// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mx = 1e3+5;
int dp[mx][mx],n,q;
vector<string>v;


int32_t main(){
    cin >> n >> q;
    v.assign(n,"");
    for(auto &x:v)cin >> x;

    memset(dp,0,sizeof(dp));
    dp[0][0] = (v[0][0]=='*');
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+j){
                dp[i][j] = (v[i][j]=='*') + (i ? dp[i-1][j] : 0) + (j ? dp[i][j-1] : 0) - (i&&j ? dp[i-1][j-1] : 0);
            }
        }
    }

    while(q--){
        int pt[4];
        for(auto &x:pt){
            cin>>x;
            x--;
        }

        int res = dp[pt[2]][pt[3]] + (pt[0]&&pt[1] ? dp[pt[0]-1][pt[1]-1] : 0) - (pt[0] ? dp[pt[0]-1][pt[3]] : 0) - (pt[1] ? dp[pt[2]][pt[1]-1] : 0);

        cout<<res<<"\n";
    }

    return 0;
}