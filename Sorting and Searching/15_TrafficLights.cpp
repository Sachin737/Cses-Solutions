// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> x >> n;
    multiset<int> starts = {0};
    map<int, int> lens;
    lens[x] = 1;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto it = starts.upper_bound(p);
        it--;

        int st = (*it);
        int l = (*it);
        it++;

        if (it == starts.end())
        {
            l = x - l;
            lens[x - p]++;
        }
        else
        {
            l = (*it) - l;
            lens[(*it) - p]++;
        }

        lens[l]--;
        lens[p - st]++;
        it--;

        if (p != st)
        {
            if (!lens[l])
                lens.erase(l);
            starts.erase(it);
            starts.insert(st);
            starts.insert(p);
        }

        cout << (*(--lens.end())).first << " ";
    }

    return 0;
}