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


ll n, m, k;
vvll v;
vll vis;
 
void dfs(ll node)
{
    vis[node] = 1;
    // cout<<node<<" ";
    for (auto c : v[node])
    {
        if (!vis[c])
        {
            dfs(c);
        }
    }
}
 
struct ed
{
    ll a, b, w;
};
 
void brrrr()
{
    cin >> n >> m;
    vector<ed> edge;
    vis.resize(n + 1, 0);
    v.resize(n + 1, vll());
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.pb({a, b, -c}); // to find positive cycle if exist
        v[a].pb(b);
    }
    vll dis(n + 1, LLONG_MAX);
 
    ll x = -1;
    vll par(n + 1, -1);
    dis[1] = 0;
 
    for (ll i = 0; i < n; i++)
    {
        x = -1;
        for (ll j = 0; j < m; j++)
        {
            if (dis[edge[j].a] != LLONG_MAX)
            {
                if (dis[edge[j].a] + edge[j].w < dis[edge[j].b])
                {
                    dis[edge[j].b] = dis[edge[j].a] + edge[j].w;
                    par[edge[j].b] = edge[j].a;
                    x = edge[j].b;
 
                    if(i==n-1)dfs(x);
                    
                    if (i == n - 1 && vis[n])
                    {
                        cout << "-1\n";
                        return;
                    }
                }
            }
        }
    }
 
    cout << -dis[n] << "\n";
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