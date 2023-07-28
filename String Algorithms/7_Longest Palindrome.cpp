// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

const int m = 1e9+9;
const int p = 31;
vector<int>p_pow,shash,revhash;


int main()
{
    string s;cin >> s;
    int n = s.size();

    p_pow.assign(n,0);
    p_pow[0] = 1;
    for(int i=1;i<n;i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    shash[0] = (s[0]-'a');
    for(int i=1;i<n;i++){
        shash[i] = (shash[i-1]%m + (p_pow[i]*(s[i]-'a'))%m + m)%m;
    }

    // hash(i,j) *p_pow[i] = hash(0,j) - hash(0,i-1)

    reverse(s.begin(),s.end());
    revhash[0] = (s[0]-'a');
    for(int i=1;i<n;i++){
        revhash[i] = (revhash[i-1]%m + (p_pow[i]*(s[i]-'a'))%m + m)%m;
    }

    


    

    return 0;
}