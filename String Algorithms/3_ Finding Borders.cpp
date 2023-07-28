// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>ppow,h;
const int A = 31;
const int B = 1e9+10;


int32_t main()
{
    string s;
    cin >> s;
    int n = s.size();
    
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

    for(int i=0;i<n-1;i++){
        int h1 = (h[i] * ppow[n-i-1]) % B;
        int h2 = (h[n-1] - h[n-i-2] + B) % B;
        if(h1==h2){
            cout << i+1 << " ";
        }
    }
    
    return 0;
}