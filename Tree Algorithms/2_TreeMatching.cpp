// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,mx=1;
vector<vector<int>>v;
vector<int>dis;

void dfs(int node,int par){
    for(auto &x:v[node]){
        if(x!=par){
            dis[x]=dis[node]+1;
            if(dis[x] >= dis[mx]){
                mx = x;
            }
            dfs(x,node);
        }
    }
}

int32_t main()
{
    cin >> n;    
    v.assign(n+1,vector<int>());

    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dis.assign(n+1,0);
    dfs(1,0);

    dis.assign(n+1,0);
    dfs(mx,0);

    cout << dis[mx] << "\n";

    return 0;
}