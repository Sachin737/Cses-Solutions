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
 
vll di = {1, 0, -1, 0};
vll dj = {0, 1, 0, -1};
vector<char> dir = {'D', 'R', 'U', 'L'};
ll n, m;
 
bool valid(ll x, ll y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
 
void brrrr()
{
    cin >> n >> m;
    vector<string> v(n),path;
    for (auto &x : v) cin >> x;
    path = v;
 
    pll st, en;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
                st = {i, j};
            if (v[i][j] == 'B')
                en = {i, j};
        }
    }
    vvll vis(n, vll(m, 0));
 
    queue<pll> q;
    q.push(st);
    vis[st.fs][st.ss] = 1;
 
    ll f = 0;
    while (q.size())
    {
        pll node = q.front();
        q.pop();
 
        for (ll i = 0; i < 4; i++)
        {
            ll x = node.fs + di[i];
            ll y = node.ss + dj[i];
            if (valid(x, y) && !vis[x][y])
            {
                if (v[x][y] == 'B')
                {
                    vis[x][y] = 1;
                    f = 1;
                    path[x][y] = dir[i];
                    break;
                }
                if (v[x][y] == '.')
                {
                    q.push({x, y});
                    vis[x][y] = 1;
                    path[x][y] = dir[i];
                }
                
            }
        }
        if (f)
            break;
    }
 
    if (!f)
    {
        no;
        return;
    }
 
    ll x = en.fs,y=en.ss;
    string res = "";
 
    while(!(x==st.fs && y==st.ss))
    {
        res += path[x][y];
        if(path[x][y]=='U')x++;
        else if(path[x][y]=='D')x--;
        else if(path[x][y]=='L')y++;
        else y--;
    }
 
    reverse(all(res));
 
    yes;
    cout<<res.size()<<"\n";
    cout<<res<<"\n";
 
 
 
 
 
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
