// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

// ---------------------------------Policy Based DataStructures-----------------------
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using omulset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//  .find_by_order(x) : index of the x element in the set starting from 0
//  .order_of_key(x)  : number of elements strictly smaller than x in the set
// -----------------------------------------------------------------------------------


#define int long long

int32_t main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    oset<pair<int,int>> ms;
    int i=0;
    for (auto &x : v)
        cin >> x, ms.insert({x,i++});



    while (q--)
    {
        char c;
        cin >> c;
        if (c == '?')
        {
            int a, b;
            cin >> a >> b;
            cout << ms.order_of_key({b+1,-1}) - ms.order_of_key({a,-1}) << "\n";
        }
        else
        {
            int k, x;
            cin >> k >> x;
            ms.erase(make_pair(v[k-1],k-1));
            v[k-1] = x;
            ms.insert({x,k-1});
        }
    }

    return 0;
}