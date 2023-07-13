// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long q;cin>>q;

    while(q--){
        long long i = 0, cur = 0, k;
        cin >> k;

        while(k - 9*(long long)pow(10ll,i)*(i+1) >= 0ll){
            k -= 9*(long long)pow(10ll,i)*(i+1);
            cur += 9*(long long)pow(10ll,i);
            i++;
        }
        i++;

        if(k==0){
            cout << cur%10 << "\n";
            continue;
        }

        cur = cur + (k+i-1)/i;
        string fin = to_string(cur);

        long long idx = (k - 1)%i;
        cout << fin[idx] << "\n";
    }





    return 0;
}