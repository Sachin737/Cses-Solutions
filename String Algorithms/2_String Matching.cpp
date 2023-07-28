// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>ppow,h;
const int A = 31;
const int B = 1e9+10;



int32_t main()
{
    string s,p;
    cin >> s >> p;
    int n = s.size(),m = p.size();
    
    ppow.assign(n,0);
    h.assign(n,0);

    ppow[0] = 1;
    h[0] = (s[0]-'a');

    for(int i=1;i<n;i++){
        ppow[i] = ppow[i-1]*A;
        ppow[i] %= B;
        h[i] = h[i-1] + ppow[i]*(s[i]-'a');
        h[i] %= B; 
    }

    int hp = 0;
    for(int i=0;i<m;i++){
        hp += ppow[i]*(p[i]-'a');
        hp %= B;
    }
    
    int res = 0;
    for(int i=0;i<=n-m;i++){
        int j = i+m-1;
        int hval = (h[j] - (i ? h[i-1] : 0) + B)%B;
        res += hval==(hp * ppow[i])%B;
    }

    cout<<res;
    

    return 0;
}