// Sachin Mahawar
#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[7][7];
int res = 0;

bool good(int r, int c)
{
    bool ok = (r >= 0 && c >= 0 && r < 7 && c < 7 && !vis[r][c]);
    return ok;
}

void go(int i, int r, int c)
{
    if (r == 6 && c == 0)
    {
        res += (i == 48);
        return;
    }

    if (i == 48)
        return;

    // check division condition
    if (((r + 1 == 7 || (vis[r - 1][c] && vis[r + 1][c])) && c - 1 >= 0 && c + 1 < 7 && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c + 1 == 7 || (vis[r][c - 1] && vis[r][c + 1])) && r - 1 >= 0 && r + 1 < 7 && !vis[r - 1][c] && !vis[r + 1][c]) ||
        ((r == 0 || (vis[r + 1][c] && vis[r - 1][c])) && c - 1 >= 0 && c + 1 < 7 && !vis[r][c - 1] && !vis[r][c + 1]) ||
        ((c == 0 || (vis[r][c + 1] && vis[r][c - 1])) && r - 1 >= 0 && r + 1 < 7 && !vis[r - 1][c] && !vis[r + 1][c]))
        return;

    vis[r][c] = true;

    if (s[i] == '?')
    {
        if (good(r - 1, c))
        {
            go(i + 1, r - 1, c);
        }
        if (good(r + 1, c))
        {
            go(i + 1, r + 1, c);
        }
        if (good(r, c - 1))
        {
            go(i + 1, r, c - 1);
        }
        if (good(r, c + 1))
        {
            go(i + 1, r, c + 1);
        }
    }
    else
    {
        if (good(r + (s[i] == 'D') - (s[i] == 'U'), c + (s[i] == 'R') - (s[i] == 'L')))
        {
            go(i + 1, r + (s[i] == 'D') - (s[i] == 'U'), c + (s[i] == 'R') - (s[i] == 'L'));
        }
    }

    vis[r][c] = false;
}

int main()
{

    cin >> s;
    memset(vis, 0, sizeof(vis));

    go(0, 0, 0);
    cout << res;

    return 0;
}