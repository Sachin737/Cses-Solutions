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
pll st;
vector<string>v,Move;
vll di={-1,0,1,0};
vll dj={0,1,0,-1};
    // U R D L
vvll MonsterDis,Adis;

bool valid(ll i,ll j){
    return (i>=0&&i<n&&j>=0&&j<m);
}
void brrrr()
{
    cin>>n>>m;
    v.assign(n,"");
    MonsterDis.assign(n,vll(m,INT_MAX));
    Adis.assign(n,vll(m,INT_MAX));
    for(auto &x:v)cin>>x;

    queue<pll>q;
    vvll vis(n,vll(m,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='M'){
                q.push({i,j});
                MonsterDis[i][j]=0;
                vis[i][j]=1;
            }else if(v[i][j]=='A')st={i,j};
        }
    }

    if(st.first==0||st.first==n-1||st.second==0||st.second==m-1){
        cout<<"YES\n0\n";
        return;
    }

    while(q.size()){
        pll f = q.front();
        q.pop();
        for(ll k=0;k<4;k++){
            ll ii = f.first+di[k];
            ll jj = f.second+dj[k];
            if(valid(ii,jj)&&!vis[ii][jj]&&v[ii][jj]!='#'){
                q.push({ii,jj});
                MonsterDis[ii][jj] = min(MonsterDis[ii][jj],MonsterDis[f.first][f.second]+1);
                vis[ii][jj]=1;
            }
        }
    }
    // for(auto &x:MonsterDis){
    //     for(auto &y:x){
    //         if(y==INT_MAX)cout<<"# ";
    //         else cout<<y<< " ";
    //     }
    //     cout<<"\n";
    // }

    Move=v;

    vis.assign(n,vll(m,0));

    q.push(st);
    
    vis[st.first][st.second]=1;
    Adis[st.first][st.second]=0;

    while(q.size()){
        pll f = q.front();
        q.pop();
        for(ll k=0;k<4;k++){
            ll ii = f.first+di[k];
            ll jj = f.second+dj[k];
            if(valid(ii,jj)&&!vis[ii][jj]&&v[ii][jj]!='#'){
                Adis[ii][jj] = Adis[f.first][f.second]+1;
                if(Adis[ii][jj] < MonsterDis[ii][jj]){
                    q.push({ii,jj});
                    vis[ii][jj] = 1;
                    if(k==0){
                        Move[ii][jj] = 'U';
                    }else if(k==1){
                        Move[ii][jj] = 'R';
                    }else if(k==2){
                        Move[ii][jj] = 'D';
                    }else if(k==3){
                        Move[ii][jj] = 'L';
                    }

                    if(ii==0||ii==n-1||jj==0||jj==m-1){
                        string res = "";
                        pll go = {ii,jj};
                        while(!(go.first==st.first&&go.second==st.second)){
                            res += Move[go.first][go.second];
                            if(Move[go.first][go.second]=='U'){
                                go.first++;
                            }else if(Move[go.first][go.second]=='R'){
                                go.second--;
                            }else if(Move[go.first][go.second]=='D'){
                                go.first--;
                            }else if(Move[go.first][go.second]=='L'){
                                go.second++;
                            }
                        }

                        cout<<"YES\n";
                        cout<<res.size()<<"\n";
                        reverse(all(res));
                        cout<<res<<"\n";
                        return;
                    }
                }
            }
        }
    }

    cout<<"NO\n";






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