// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1000000007;
vector<long long>v;
long long n,m;
vector<vector<long long>>dp;
 
string a,b;
 
 
long long go(long long i,long long j){
 
    if(j==m){
        return (n-i);
    }
    if(i==n){
        return (m-j);
    }
 
    if(dp[i][j]!=-1)return dp[i][j];
    long long res = INT_MAX;
    if(a[i]==b[j]){
        res = go(i+1,j+1);
    }else{
        res = 1 + min({go(i,j+1),go(i+1,j),go(i+1,j+1)});
    }
 
    return dp[i][j] = res;
}
 
int main()
{
    cin >> a >> b;
    n = a.size(), m = b.size();
    dp.assign(n,vector<long long>(m,-1));
    long long res = go(0,0);
    cout << res << "\n";
}
