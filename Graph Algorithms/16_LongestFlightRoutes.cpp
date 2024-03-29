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



void brrrr()
{
    ll n,m;cin>>n>>m;
    vvll v(n+1,vll());

    for(ll i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        v[a].push_back(b);
    }

    multiset<pll>ms = {make_pair(0,1)};
    vll dis(n+1,INT_MAX),par(n+1,-1);
    dis[1] = 0;

    while(ms.size()){
        ll node = (*ms.begin()).second;
        ll d = (*ms.begin()).first;
        ms.erase(ms.begin());

        for(auto &x:v[node]){
            if(dis[node] - 1 < dis[x]){
                ms.erase({dis[x],x});
                dis[x] = dis[node] - 1;
                par[x] = node;
                ms.insert({dis[x],x});
            }
        }
    }

    if(dis[n]==INT_MAX){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    ll st = n;
    vll res;
    while(st!=-1){
        res.push_back(st);
        st=par[st];
    }

    reverse(all(res));
    cout << res.size()<<"\n";
    for(auto &x:res)cout<<x<<" ";

    
    



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