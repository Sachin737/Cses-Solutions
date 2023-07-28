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

    sort(v.begin(), v.end(), [&](const vector<int> &a, const vector<int> &b)
         {
        if(a[0]==b[0]){
            return a[1]>b[1];
        }else{
            return a[0]<b[0];
        } });

    vector<int> room(n, 0);

    omulset<int> oms;
    oms.insert(v[0][1]);
    int res = 0;
    room[v[0][2]] = 1;

    for (int i = 1; i < n; i++)
    {
        int cnt = oms.order_of_key(v[i][0]);
        cnt = oms.size() - cnt;
        res = max(res, cnt + 1);
        oms.insert(v[i][1]);
    }

    sort(v.begin(), v.end());
    
    // for(auto &x:v){
    //     cout<<x[0]<<","<<x[1]<<"\n";
    // }


    int roomId = 1;
    set<vector<int>>ms;
    for(auto &x:v)ms.insert(x);

    while(ms.size()){
        vector<int> cur = *ms.begin();
        room[cur[2]] = roomId;
        ms.erase(ms.begin());

        while(ms.size()){
            vector<int>tmp = {cur[1],INT_MAX,INT_MAX};
            auto nxt = ms.upper_bound(tmp);
            if(nxt==ms.end())break;

            // cout<<cur[1]<<": "<<(*nxt)[0]<<"\n";
            
            room[(*nxt)[2]] = roomId;
            cur = *nxt;
            ms.erase(nxt);
        }
        roomId++;
    }

    cout << res << "\n";
    for (auto &x : room)
        cout << x << " ";
    cout << "\n";

    return 0;
}