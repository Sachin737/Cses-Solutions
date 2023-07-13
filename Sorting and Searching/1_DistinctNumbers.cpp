// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(auto &x:v)cin>>x;

    sort(v.begin(),v.end());
    int res = 1;
    for(int i=1;i<n;i++){
        res += (v[i]!=v[i-1]);
    }
    cout<<res;

    return 0;
}