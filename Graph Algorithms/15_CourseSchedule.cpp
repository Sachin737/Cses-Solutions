// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
 
// ---------------------------------Policy Based DataStructures----------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
// defining template when all elements are distinct
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// defining template when duplicate elements are also used
template <class T>
using omulset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//  .find_by_order(x) : index of the x element in the set starting from 0
//  .order_of_key(x)  : number of elements strictly smaller than x in the set
// ---------------------------------------------------------------------------------
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<ll>> vvll;
 
#define ff(i, x, n) for (ll i = x; i < n; i++)
#define fb(i, n, x) for (ll i = n; i >= x; i--)
#define lele(v, n) ff(i, 0, n) cin >> v[i];
#define out(v, n)                        \
    ff(i, 0, n) { cout << v[i] << " "; } \
    cout << endl;
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define fs first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sorte(v) sort(all(v))
const int mod = 1000000007;
const int mod2 = 998244353;
const ll INF = 1e18 + 7;
#define fast                          \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define add(a, b) (((a % mod) + (b % mod) + mod) % mod)
#define sub(a, b) (((a % mod2) - (b % mod) + mod) % mod)
#define mul(a, b) (((a % mod) * (b % mod) + mod) % mod)
ll n, m,f=0;
vvll v;
vll vis,cur;
stack<ll> st;
 
void dfs(ll node)
{
    vis[node] = 1;
    cur[node]=1;
    if(f)return;
 
    for (auto x : v[node])
    {
        if(!f&&cur[x])
        {
            cout<<"IMPOSSIBLE\n";
            f=1;
            return;
        }else if (!f&&!vis[x])
        {
            dfs(x);
        }
    }
    cur[node]=0;
    st.push(node);
}
 
void brrrr()
{
    cin >> n >> m;
    v.resize(n + 1, vll());
    vvll in(n + 1, vll());
    vis.resize(n + 1, 0);
    cur.resize(n+1,0);
 
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
    }
 
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cur.clear();
            f=0;
            dfs(i);
            if(f)return;
        }
    }
 
    vll res;
    while (st.size())
    {
        res.pb(st.top());
        st.pop();
    }
    
    for(auto x:res)cout<<x<<" ";
    cout<<"\n";
}
 
int main()
{
    fast;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        brrrr();
    }
    return 0;
}