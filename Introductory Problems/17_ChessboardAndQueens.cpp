// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<string>v(8);
    for(auto &x:v)cin>>x;

    vector<int>p(8);
    iota(p.begin(),p.end(),0);
    int res = 0;

    do{
        bool ok = true;
        for(int i=0;i<8;i++){
            ok &= v[i][p[i]]=='.';
        }
        if(!ok)continue;

        ok = true;
        for(int i=0;i<8;i++){
            for(int j=i+1;j<8;j++){
                ok &= (j-i!=abs(p[j]-p[i])); 
            }
        }
        
        res += ok;
    }while(next_permutation(p.begin(),p.end()));

    cout<<res<<"\n";
    return 0;
}