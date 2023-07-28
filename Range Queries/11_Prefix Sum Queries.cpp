// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Node{
    int sm;
    int prefsm;
};

int n,q;
vector<Node>seg;
vector<int>v;

Node merge(Node a, Node b){
    return Node{a.sm+b.sm,max(a.prefsm,a.sm+b.prefsm)};
}

void build(int node,int l,int r){
    if(l==r){
        seg[node].sm = v[l];
        seg[node].prefsm = max(0ll,v[l]);
        return;
    }

    int mid = (l + r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    seg[node] = merge(seg[2*node+1],seg[2*node+2]);
}

Node query(int node,int l,int r,int ql,int qr){

    if(r < ql || l > qr){
        return Node{0ll,0ll};
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
        ll t;cin>>t;
        if(t==1){
            int k,u;cin>>k>>u;
            update(0,0,n-1,k-1,u);
        }else{
            int a,b;cin>>a>>b;
            cout << query(0,0,n-1,a-1,b-1).prefsm << "\n";
        }
    }
       
    return 0;
}