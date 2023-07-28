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

    for(int i=0;i<n;i++){
        int h1 = h[i];
        bool ok = true;
        
        int j=2*i+1;
        // cout << i << ": ";
        for(j;j<n;j+=(i+1)){
            int h2 = (h[j] - h[j-i-1] + B) % B;
            ok &= ((h1 * ppow[j-i]) % B == h2);
            // cout << (h1 * ppow[j-i]) % B << " " << h2 << "\n";
        }

        if(ok && j-(i+1) < n-1){
            int len = n-1 - (j-(i+1));

            int h11 = (h[n-1] - h[n-1-len] + B) % B;
            int h22 = h[len-1];
            if((h22 * ppow[n-len]) % B == h11){
                cout << i+1<<" "; 
            }
        }else if(ok){
            cout << i+1 << " ";
        }
   }
    
    return 0;
}