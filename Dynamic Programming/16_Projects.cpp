#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;

    for (int i = 0; i < n; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        v.push_back({a, b, p});
    }

    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         {
        if(a[1]==b[1]){
            return (a[0] >= b[0]);
        }else{
            return (a[1] <= b[1]);
        } });
        

    set<pair<int, int>> ms; // ends

    vector<int> dp(n, 0);

    dp[0] = v[0][2];
    ms.insert({v[0][1], dp[0]});
    int res = v[0][2];

    for (int i = 1; i < n; i++)
    {
        auto it = ms.lower_bound(make_pair(v[i][0], 0));

        dp[i] = max(v[i][2], dp[i - 1]);
        if (it != ms.begin())
        {
            it--;
            dp[i] = max(dp[i], (*it).second + v[i][2]);
        }
        ms.insert({v[i][1], dp[i]});
        res = max(res, dp[i]);
    }

    cout << res << "\n";

    return 0;
}