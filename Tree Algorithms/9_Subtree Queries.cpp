// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
vector<vector<int>>v;
vector<int>val;


int32_t main()
{
    cin >> n >> q;
    v.assign(n+1,vector<int>());
    val.assign(n+1,0);

    for(int i=1;i<=n;i++) cin >> val[i];

    for(int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    



    return 0;
}