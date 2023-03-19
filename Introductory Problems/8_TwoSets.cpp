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
    ll n;cin>>n;
    vll a,b;
    ll sm = n*(n+1)/2ll;
    if(sm&1ll){
        cout << "NO\n";
    }else{
        if(n%4ll==0){
            cout<<"YES\n";
            for(ll i=1;i<=n/2;i++){
                if(i&1ll){
                    a.push_back(i);
                    a.push_back(n-i+1);
                }else{
                    b.push_back(i);
                    b.push_back(n-i+1);
                }
            }
        }else{
            if((n-3)%4==0){
                cout << "YES\n";
                a.push_back(1);
                a.push_back(2);
                b.push_back(3);
                ll i=4,j=n;
                while(i<j){
                    if(i&1ll){
                        a.push_back(i);
                        a.push_back(j);
                    }else{
                        b.push_back(i);
                        b.push_back(j);
                    }
                    i++,j--;
                }
            }else{
                cout << "NO\n";
            }
        }
    }
    if(a.size()){
        cout<<a.size()<<"\n";
        for(auto &x:a)cout<<x<<" ";
        cout<<"\n";

        cout<<b.size()<<"\n";
        for(auto &x:b)cout<<x<<" ";
        cout<<"\n";
    }

    



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