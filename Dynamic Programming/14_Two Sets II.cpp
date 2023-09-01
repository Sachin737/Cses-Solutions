#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
const int mod = 1e9+7;
int dp[501][125251];

int go(int i,int j){
    if(i==n+1){
        return (!j);
    }
    if(j==0){
        return 1;
    }

    if(dp[i][j]!=-1)return dp[i][j];

    // dont take
    int res = go(i+1,j)%mod;

    // take
    if(j>=i)res += go(i+1,j-i)%mod;

    return dp[i][j] = res;
}

int32_t main(){
    cin >> n;
    memset(dp,-1,sizeof(dp));

    int sm = (n*(n+1))/2;

    if(sm&1){
        cout << "0\n";
    }else{
        cout << go(1,sm/2)/2 << "\n";
    }

    
    return 0;
}