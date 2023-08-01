// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fast                          \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int n,q;
vector<vector<int>>v,up;
vector<int>lvl,vis,val,subsm;


void binary_lifting(int node,int par)
{
    up[node][0]=par;
    for(int i=1;i<19;i++)
    {
        if(up[node][i-1]!=-1)
        {
            up[node][i] = up[up[node][i-1]][i-1];
        }else
        {
            up[node][i] = -1;
        }
    }
 
    for(auto &x:v[node])
    {
        if(x!=par)
        {
            lvl[x]=lvl[node]+1;
            binary_lifting(x,node);
        }
    }
}
 
 
int liftnode(int node, int jump)
{
    for (int i = 18; i >= 0; i--)
    {
        if (jump == 0 || node == -1)
            break;
     
        if (jump >= (1 << i))
        {
            jump -= (1 << i);
            node = up[node][i];
        }
    }
    return node;
}
 
int lca(int n1, int n2)
{
    if (lvl[n1] < lvl[n2])
        swap(n1, n2);
 
    n1 = liftnode(n1, lvl[n1] - lvl[n2]);
 
    if (n1 == n2)
        return n1;
 
    for (int i = 18; i >= 0; i--)
    {
        if (up[n1][i] != up[n2][i])
        {
            n1 = up[n1][i];
            n2 = up[n2][i];
        }
    }
    return liftnode(n1, 1);
}

void dfs(int node,int par){
    subsm[node] = val[node];
    for(auto &x:v[node]){
        if(x!=par){
            dfs(x,node);
            subsm[node] += subsm[x];
        }
    }
}
 

int32_t main()
{
    fast;
    cin >> n >> q;
    v.assign(n+1,vector<int>());
    up.assign(n+1,vector<int>(19,0));

    for(int i=2;i<=n;i++){
        int a,b;cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    lvl.assign(n+1,0);
    binary_lifting(1,0);
    
    val.assign(n+1,0);
    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        int x = lca(a,b);
        val[a]++;
        val[b]++;
        val[x]--;
        int par = up[x][0];
        if(par!=-1){
            val[par]--;
        }
    }

    subsm.assign(n+1,0);
    dfs(1,0);

    for(int i=1;i<=n;i++)cout << subsm[i] << " ";




    return 0;
}