#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int>v;
int dp[5000][5000][2];

int go(int i,int j,int turn){
    if(i==j){
        return (!turn)*v[i];
    }
    if(dp[i][j][turn]!=-1)return dp[i][j][turn];
    int res = 0;
    if(turn==0){
        res = max(v[i] + go(i+1,j,1),v[j] + go(i,j-1,1));
    }else{
        res = min(go(i+1,j,0),go(i,j-1,0));
    }
    return dp[i][j][turn]=res;
}

int32_t main(){

    cin >> n;
    v.assign(n,0);
    for(auto &x:v)cin >> x;

    memset(dp,-1,sizeof(dp));

    cout << go(0,n-1,0) << "\n";

    
    return 0;
}