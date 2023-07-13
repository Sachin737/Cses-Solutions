// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin >> n;
    vector<int>v(n);
    map<int,int>id;
    for(int i=0;i<n;i++){
        cin >> v[i];
        id[v[i]] = i;
    }
    id[n+1] = n;
    
    int res = 1;
    for(int i=1;i<n;i++){
        res += (id[v[i]+1] < i);
    }
    cout<<res;


    return 0;
}