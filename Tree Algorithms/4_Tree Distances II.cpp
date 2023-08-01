// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>>v;
vector<int>dis,sz,res;

void dfs(int node,int par){
    sz[node] = 1;
    for(auto &x:v[node]){
        if(x!=par){
            dis[x] = dis[node]+1;
            dfs(x,node);
            sz[node] += sz[x];
        }
    }
}

void dfs1(int node,int par){
    for(auto &x:v[node]){
        if(x!=par){
            res[x] = res[node] + n - 2 * sz[x];
            dfs1(x,node);
        }
    }
}

int32_t main()
{
    cin >> n;
    v.assign(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        int a,b;cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dis.assign(n+1,0);
    sz.assign(n+1,0);
    res.assign(n+1,0);

    dfs(1,0);

    for(auto &x:dis)res[1]+=x;

    dfs1(1,0);

    for(int i=1;i<=n;i++){
        cout<<res[i]<<" ";
    }

    return 0;
}