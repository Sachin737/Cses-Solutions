// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,mx=1;
vector<vector<int>>v;
vector<int>dis;

void dfs(int node,int par,vector<int>&dis){
    for(auto &x:v[node]){
        if(x!=par){
            dis[x]=dis[node]+1;
            if(dis[x] >= dis[mx]){
                mx = x;
            }
            dfs(x,node,dis);
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
    vector<int>res(n+1,0);

    dis.assign(n+1,0);
    dfs(1,0,dis);

    dis.assign(n+1,0);
    dfs(mx,0,dis);

    res = dis;

    dis.assign(n+1,0);
    dfs(mx,0,dis);

    for(int i=1;i<=n;i++){
        res[i] = max(res[i],dis[i]);
    }

    for(int i=1;i<=n;i++){
        cout << res[i] << " ";
    }


    return 0;
}