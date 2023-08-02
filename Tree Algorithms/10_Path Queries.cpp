// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;


struct SegTree{
    int size;
    vector<int>v;
    vector<int> seg;

    SegTree(vector<int>vec){
        size = 1;
        while (size < vec.size()) size *= 2;
        seg.assign(2*size, 0);
        for(auto &x:vec)v.push_back(x);
    } 
    int merge(int a,int b){
        return a+b;
    }

    void build(int node,int l,int r){
        if(l==r){
            seg[node] = v[l];
            return;
        }

        int m = (l+r)/2;
        build(2*node+1,l,m);
        build(2*node+2,m+1,r);
        seg[node] = merge(seg[2*node+1], seg[2*node+2]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(r < ql || l > qr)return 0;
        if(l==ql && r==qr)return seg[node];

        int m = (l + r)/2;
        int left = query(2*node+1,l,m,ql,min(qr,m));
        int right = query(2*node+2,m+1,r,max(ql,m+1),qr);
        return merge(left, right);
    }

    void update(int node,int l,int r,int idx,int nval){
        if(l>r)return;
        if(l==r){
            seg[node] += nval;
            return;
        }
        int m = (l + r)/2;
        if(idx <= m){
            update(2*node+1,l,m,idx,nval);
        }else{
            update(2*node+2,m+1,r,idx,nval);
        }
        seg[node] = merge(seg[2*node+1], seg[2*node+2]);
    }
};

int n,q;
vector<vector<int>>v;
vector<int>val,euler,dp;

void EulerTour(int node,int par){
    euler.push_back(node);
    for(auto &x:v[node]){
        if(x!=par){
            EulerTour(x,node);
        }
    }
    euler.push_back(node);
}

void dfs(int node,int par){
    dp[node] += val[node];
    for(auto &x:v[node]){
        if(x!=par){
            dp[x] += dp[node];
            dfs(x,node);
        }
    }
}


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

    EulerTour(1,0);

    vector<vector<int>>idx(2*n+5,vector<int>());

    int m = euler.size();
    for(int i=0;i<m;i++){
        idx[euler[i]].push_back(i);
    }

    dp.assign(n+1,0);
    dfs(1,0);

    euler.assign(m,0);
    SegTree seg(euler);

    while(q--){
        int t; 
        cin >> t;
        if(t==1){
            int s,x; cin >> s >> x;
            int dif = x - val[s];
            seg.update(0,0,m-1,idx[s][0],dif);
            seg.update(0,0,m-1,idx[s][1],-dif);
            val[s] = x;
        }else{
            int s; cin >> s;
            cout << dp[s] + seg.query(0,0,m-1,0,idx[s][0]) << "\n";
        }
    }




    


    return 0;
}