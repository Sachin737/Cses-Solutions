// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
vector<vector<int>>v,up;
vector<int>lvl;

void dfs(int node,int par){

    up[node][0] = par;
    for(int i=1;i<19;i++){
        if(up[node][i-1] != -1){
            up[node][i] = up[up[node][i-1]][i-1];
        }else{
            up[node][i] = -1;
        }
    }

    for(auto &x:v[node]){
        if(x!=par){
            lvl[x] = lvl[node] + 1;
            dfs(x,node);
        }
    }
}

int lift_up(int node,int k){
    int res = node;

    for(int i=18;i>=0;i--){
        if(k - (1 << i) >=0){
            res = up[res][i];
            k-=(1<<i);
        }
    }

    return res;
}

int lca(int l,int r){
    if(lvl[l] < lvl[r])swap(l,r);

    l = lift_up(l,lvl[l]-lvl[r]);

    if(l==r){
        return l;
    }

    for(int i=18;i>=0;i--){
        if(up[l][i] != up[r][i]){
            l = up[l][i];
            r = up[r][i];
        }    
    }    

    return lift_up(l,1);
}

int32_t main()
{
    cin >> n >> q;
    v.assign(n+1,vector<int>());
    up.assign(n+1,vector<int>(19,0));

    for(int i=2;i<=n;i++){
        int a;cin >> a;
        v[a].push_back(i);
        v[i].push_back(a);
    }    

    lvl.assign(n+1,0);
    dfs(1,0);

    while(q--){
        int l,r;cin >> l >> r;
        int res = lca(l,r);
        cout << res << "\n";
    }



    return 0;
}