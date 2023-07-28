// Sachin Mahawar
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    int i = 0;
    for (auto &x : v)
    {
        cin >> x[0] >> x[1];
        x[2] = i++;
    }
    vector<int> in(n, 0);
    vector<int> out(n, 0);

    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b)
         {
        if(a[0]==b[0]){
            return a[1]>=b[1];
        }else{
            return a[0]<b[0];
        }; });

    multiset<int> st = {v[0][1]};

    for (int i = 1; i < n; i++)
    {
        auto it = st.lower_bound(v[i][1]);
        if (it != st.end())
        {
            out[v[i][2]] = 1;
        }
        st.insert(v[i][1]);
    }


    st.clear();
    st = {v[n-1][1]};
    for (int i = n - 2; i >= 0; i--)
    {
        auto it = st.upper_bound(v[i][1]);
        if (it != st.begin())
        {
            in[v[i][2]] = 1;
        }
        st.insert(v[i][1]);
    }

    for (auto &x : in)
        cout << x << " ";
    cout << "\n";

    for (auto &x : out)
        cout << x << " ";
    cout << "\n";
}