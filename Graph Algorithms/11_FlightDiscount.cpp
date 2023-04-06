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

vll djikstra(ll node, vector<vector<pll>> &v,ll n)
{
    vll dis(n + 1, LLONG_MAX);
    set<pll> s;
    s.insert({0, node});
    dis[node] = 0;
 
    while (s.size())
    {
        ll x = (*s.begin()).ss;
        s.erase(s.begin());
 
        for (auto d : v[x])
        {
            if (dis[d.fs] > dis[x] + d.ss)
            {
                s.erase(make_pair(dis[d.fs], d.fs));
                dis[d.fs] = dis[x] + d.ss;
                s.insert(make_pair(dis[d.fs], d.fs));
            }
        }
    }

    return dis;
}

void brrrr()
{
    ll n,m;cin>>n>>m;
    vector<vpll> v(n+1,vpll());
    vector<vpll> vrev(n+1,vpll());
    vvll edge;
    for(ll i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        vrev[b].push_back({a,c});
        edge.push_back({a,c,b});
    }

    vll dis1 = djikstra(1,v,n);
    vll dis2 = djikstra(n,vrev,n);
    ll res = LLONG_MAX;
    for(auto &x:edge){
        if(dis1[x[0]]!=LLONG_MAX && dis2[x[2]]!=LLONG_MAX){
            res = min(res,dis1[x[0]]+x[1]/2ll+dis2[x[2]]);
        }
    }

    cout<<res<<"\n";
    
    



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