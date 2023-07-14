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
        seg[node] = 1;
        return;
    }

    int mid = (l + r)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);

    seg[node] = merge(seg[2*node+1],seg[2*node+2]);
}

int query(int node,int l,int r,int id){
    if(id > seg[node]){
        return 0;
    }

    if(l==r){
        return l;
    }

    int mid = (l + r)/2;
    int ans;
    if(seg[2*node+1] >= id){
        ans = query(2*node+1,l,mid,id);
    }else{
        ans = query(2*node+2,mid+1,r,id-seg[2*node+1]);
    }
    return ans;
}


void update(int node,int l,int r,int id,int val){
    if(l==r){
        seg[node] = val;
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
    cin >> n;
    v.assign(n,0);
    for(auto &x:v)cin >> x;

    seg.assign(4*n,0);
    build(0,0,n-1);

    for(int i=0;i<n;i++){
        int id;cin >> id;
        int res = query(0,0,n-1,id);
        cout<<v[res]<<" ";
        update(0,0,n-1,res,0);
    }
       
    return 0;
}