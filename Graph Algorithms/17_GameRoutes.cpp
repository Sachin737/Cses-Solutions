// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<ll>> vvll;

#define ff(i, x, n) for (ll i = x; i < n; i++)
#define fb(i, n, x) for (ll i = n; i >= x; i--)
#define out(v, n)                        \
    ff(i, 0, n) { cout << v[i] << " "; } \
    cout << endl;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fs first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
#define inf 1000000000000000005
const ll mod = 1000000007;
const ll mod2 = 998244353;
#define fast                          \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define add(a, b, m) (((a % m) + (b % m) + m) % m)
#define sub(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul(a, b, m) (((a % m) * (b % m) + m) % m)

// ---------------------------------Policy Based DataStructures-----------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using omulset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//  .find_by_order(x) : index of the x element in the set starting from 0
//  .order_of_key(x)  : number of elements strictly smaller than x in the set
// -----------------------------------------------------------------------------------
ll n,m;
vvll v;
vll tp,ways,vis;

void topo(ll node){
    vis[node]=1;
    for(auto &x:v[node]){
        if(!vis[x])topo(x);
    }
    tp.push_back(node);
}
void dfs(ll node){
    vis[node]=1;
    for(auto &x:v[node]){
        if(!vis[x]){
            dfs(x);
        }
        ways[node] = add(ways[node],ways[x],mod);   
    }
}


void brrrr()
{
    cin>>n>>m;
    v.assign(n+1,vll());
    ways.assign(n+1,0);
    vis.assign(n+1,0);

    for(ll i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        v[a].push_back(b);
    }

    topo(1);
    reverse(all(tp));

    // if we take ways[i] : number of ways to reach i from 1, there is a problem
    // because if we see topoSort order of nodes from back side (right side), 
    // back Edges are present (i.e cycle) thus this approach wont work

    // ways[i] : number of ways to reach n from i

    ways[n] = 1; 
    vis.assign(n+1,0);

    for(auto &x:tp){
        if(!vis[x])dfs(x);
    }
    // for(auto &x:tp)cout<x<x<<" ";

    cout<<ways[1]<<"\n";


}

int main()
{
    fast;
    ll t=1;
//    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        brrrr();
    }
    return 0;
}