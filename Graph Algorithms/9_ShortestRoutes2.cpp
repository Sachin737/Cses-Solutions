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
#define out(v, n)            \
    ff(i, 0, n)              \
    {                        \
        cout << v[i] << " "; \
    }                        \
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

ll n, m, q;
vector<vpll> v;
vvll dis;

void brrrr()
{
    cin >> n >> m >> q;
    v.assign(n + 1, vpll());
    dis.assign(n + 1, vll(n + 1, LLONG_MAX));

    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        v[x].pb({y, w});
        v[y].pb({x, w});
        dis[x][y] = min(dis[x][y], w);
        dis[y][x] = min(dis[y][x], w);
    }

    for (ll i = 1; i <= n; i++)
        dis[i][i] = 0;

    for (ll k = 1; k <= n; k++){
        for (ll i = 1; i <= n; i++){
            for (ll j = 1; j <= n; j++){
                if(dis[i][k] < LLONG_MAX && dis[k][j] < LLONG_MAX){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if (dis[a][b] == LLONG_MAX)
            dis[a][b] = dis[b][a] = -1;
        cout << dis[a][b] << "\n";
    }
}

int main()
{
    fast;
    ll t = 1;
    //    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        brrrr();
    }
    return 0;
}