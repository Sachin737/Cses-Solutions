// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Node{
    int sm;
    int mxsum;
    int prefsm;
    int sufsum;
};

int n,q;
vector<Node>seg;
vector<int>v;

Node merge(Node a, Node b){
    int sm = a.sm+b.sm;
    int mxpref = max(a.prefsm,a.sm+b.prefsm);
    int mxsuf = max(b.sufsum,b.sm+a.sufsum);
    int mxsm = max(max(a.mxsum,b.mxsum),a.sufsum+b.prefsm);
    return Node{sm,mxsm,mxpref,mxsuf};
}

void build(int node,int l,int r){
    if(l==r){
        seg[node].sm = v[l];
        seg[node].prefsm = max(0ll,v[l]);
        seg[node].sufsum = max(0ll,v[l]);
        return;
    }

    int mid = (l + r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    seg[node] = merge(seg[2*node+1],seg[2*node+2]);
}

Node query(int node,int l,int r,int ql,int qr){

    if(r < ql || l > qr){
        return Node{0ll,0ll,0ll};
    }

    if(r<=qr && l>=ql){
        return seg[node];
    }

    int m = (l + r)/2;
    Node L = query(2*node+1,l,m,ql,min(qr,m));
    Node R = query(2*node+2,m+1,r,max(ql,m+1),qr);

    return merge(L,R);
}


void update(int node,int l,int r,int id,int val){
    if(l==r){
        seg[node].sm = val;
        seg[node].prefsm = max(0ll,val);
        seg[node].sufsum = max(0ll,val);
        return;
    }

    int m = (l + r)/2;

    if(id<=m){
        update(2*node+1,l,m,id,val);
    }else{
        update(2*node+2,m+1,r,id,val);
    }

    seg[node] = merge(seg[2*node+1],seg[2*node+2]);
}

int32_t main()
{
    cin >> n >> q;
    v.assign(n,0);
    for(auto &x:v)cin >> x;

    seg.assign(4*n,Node());
    build(0,0,n-1);

    while(q--){
        int k,u;cin>>k>>u;
        update(0,0,n-1,k-1,u);
        cout << query(0,0,n-1,0,n-1).mxsum << "\n";
    }
       
    return 0;
}