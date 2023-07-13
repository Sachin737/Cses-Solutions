// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

// Good problem idea !!!

// 1. let assume that we can make sum [1,res-1] with coins[0,i-1]
// 2. cur position : i
// 3. lets take new Fake good range be : [1,(res+v[i]-1)]
// 4. we need to prove that for all 0<k<=v[i], we can get sum (res-1+k) 
// 5. Now, to achieve this sum, we need to remove few coins from range [0,i-1]
//    and add v[i] to current max achievable sum (res - 1)
// 6. So, newsm = (res-1) - sigma(v[j]) + v[i] = (res-1+k)
//              => v[i] - sigma(v[j]) = k
//              => 0 < v[i] - sigma(v[j]) <= v[i]
//              =>     0 <= sigma(v[j]) < v[i]                                                      
// 7. Now, since v[i] <= res, we can write
//              =>  sigma(v[j]) < res
// 8. And, its True as per our assumption, we can get get any sum in 
//    range[0,res-1] using coins[0,i-1]
// 9. Hence, new Good achievable range is [1,res+v[i]-1], and cur Ans = res+v[i] 


int main()
{
    int n;cin >> n;
    vector<long long>v(n);
    for(auto &x:v)cin>>x;

    sort(v.begin(),v.end());

    long long res = 1;

    for(int i=0;i<n;i++){
        if(v[i] <= res){
            res += v[i];
        }else{
            break;
        }
    }
    cout<<res<<"\n";

    return 0;
}