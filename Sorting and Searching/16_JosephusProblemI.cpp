// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;


    multiset<int>ms;
    for(int i=1;i<=n;i++){
        ms.insert(i);
    }

    auto it = ms.begin();
    it++;
    if(it==ms.end())it=ms.begin();

    while(ms.size()){
        cout<<(*it)<<" ";
        it = ms.erase(it);
        if(it==ms.end())it=ms.begin();

        if(!ms.size())break;
        it++;
        if(it==ms.end())it=ms.begin();
    }

    return 0;
}