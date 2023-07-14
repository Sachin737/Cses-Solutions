// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
vector<int>seg;
vector<int>v;

int merge(int a, int b){
    return min(a,b);
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
        return INT_MAX;
    }

    if(l>=ql && r<=qr){
        return seg[node];
    }

    int mid = (l + r)/2;
    int L = query(2*node+1,l,mid,ql,min(qr,mid));
    int R = query(2*node+2,mid+1,r,max(ql,mid+1),qr);

    return merge(L,R);
}

int32_t main()
{
    cin >> n >> q;
    v.assign(n,0);
    for(auto &x:v)cin >> x;

    seg.assign(4*n,0);
    build(0,0,n-1);

    while(q--){
        int l,r;cin>>l>>r;
        int res = query(0,0,n-1,l-1,r-1);
        cout << res << "\n";
    }   
       
    return 0;
}