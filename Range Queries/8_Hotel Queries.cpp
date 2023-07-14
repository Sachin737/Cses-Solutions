// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define fast                          \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int n, q;
vector<int> seg;
vector<int> v;

int merge(int a, int b)
{
    return max(a, b);
}

void build(int node, int l, int r)
{
    if (l == r)
    {
        seg[node] = v[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);

    seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
}

int query(int node, int l, int r, int ql, int qr)
{
    if (r < ql || l > qr)
    {
        return 0;
    }

    if (l == ql && r == qr)
    {
        return seg[node];
    }

    int mid = (l + r) / 2;
    int L = query(2 * node + 1, l, mid, ql, min(qr, mid));
    int R = query(2 * node + 2, mid + 1, r, max(ql, mid + 1), qr);

    return merge(L, R);
}

void update(int node, int l, int r, int id, int val)
{
    if (l == r)
    {
        seg[node] = val;
        v[l] = val;
        return;
    }

    int mid = (l + r) / 2;

    if (id <= mid)
    {
        update(2 * node + 1, l, mid, id, val);
    }
    else
    {
        update(2 * node + 2, mid + 1, r, id, val);
    }

    seg[node] = merge(seg[2 * node + 1], seg[2 * node + 2]);
}

int main()
{
    fast;
    cin >> n >> q;
    v.assign(n, 0);
    seg.assign(4 * n, 0);

    for (auto &x : v)
        cin >> x;

    build(0, 0, n - 1);

    while (q--)
    {
        int x;
        cin >> x;

        int l = 0, r = n - 1, res = n;
        while (l <= r)
        {
            int m = (l + r) / 2;

            int rmx = query(0, 0, n - 1, 0, m);

            if (rmx >= x)
            {
                res = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        if (res != n)
        {
            update(0, 0, n - 1, l, v[res] - x);
        }
        else
        {
            res = -1;
        }

        cout << res + 1 << " ";
    }

    return 0;
}