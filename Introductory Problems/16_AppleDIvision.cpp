// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int>v(n);
    long long sm = 0, res = INT_MAX;
    for(auto &x:v)cin>>x,sm+=x;

    for(int i=0;i<(1<<n);i++){
        long long  sm1 = 0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                sm1+=v[j];
            }
        }
        res=min(res,abs(sm-sm1-sm1));
    }
    cout<<res<<"\n";

    return 0;
}