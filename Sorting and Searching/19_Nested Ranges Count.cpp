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

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }

    vector<int> contains(n, 0), contained(n, 0);

    sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b)
         {
        if(a[0]==b[0]){
            return a[1]>=b[1];
        }else{
            return a[0]<b[0];
        } });


    // contains
    omulset<int> oms;
    oms.insert(v[n-1][1]);
    for(int i=n-2;i>=0;i--){
        int cnt = oms.order_of_key(v[i][1]+1);
        contains[v[i][2]] = cnt;
        oms.insert(v[i][1]);
    }
    for(auto &x:contains){
        cout<<x<<" ";
    }
    cout<<"\n";

    


    // contained
    oms.clear();
    oms.insert(v[0][1]);
    for(int i=1;i<n;i++){
        int cnt = oms.order_of_key(v[i][1]);
        cnt = oms.size() - cnt;
        contained[v[i][2]] = cnt;
        oms.insert(v[i][1]);
    }
    for(auto &x:contained){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}