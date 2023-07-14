// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
vector<int>seg;
vector<int>v;

int merge(int a, int b){
    return a+b;
}

void build(int node,int l,int r){
    if(l==r){
        seg[node] = v[l];
        return;
    }

    int mid = (l + r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    seg[node] = merge(seg[2*node+1],seg[2*node+2]);
}

int query(int node,int l,int r,int ql,int qr){
    if(r < ql || l > qr){
        return 0;
    }

    if(l>=ql && r<=qr){
        return seg[node];
    }

    int mid = (l + r)/2;
    int L = query(2*node+1,l,mid,ql,min(qr,mid));
    int R = query(2*node+2,mid+1,r,max(ql,mid+1),qr);

    return merge(L,R);
}


void update(int node,int l,int r,int id,int val){
    if(l==r){
        seg[node] += val;
        return;
    }

    int mid = (l + r)/2;

    if(id<=mid){
        update(2*node+1,l,mid,id,val);
    }else{
        update(2*node+2,mid+1,r,id,val);
    }

    seg[node] = merge(seg[2*node+1],seg[2*node+2]);
}

int32_t main()
{
    cin >> n >> q;
    v.assign(n,0);
    for(auto &x:v)cin >> x;

    seg.assign(4*n,0);

    while(q--){
        int t;cin>>t;
        if(t==1){
            int a,b,u;cin>>a>>b>>u;
            a--,b--;
            update(0,0,n-1,a,u);
            if(b<n-1)update(0,0,n-1,b+1,-u);
        }else{
            int k;cin>>k;
            k--;
            int res = v[k] + query(0,0,n-1,0,k);
            cout<<res<<"\n";
        }
    }   
       
    return 0;
}