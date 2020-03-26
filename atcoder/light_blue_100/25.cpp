#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int wi, he;
int c[100][100];
bool seen[100][100];

void dfs(int w, int h)
{
    if (c[w][h] == 1 && seen[w][h] == false)
    {
        seen[w][h] = true;
        if (c[w + 1][h] == 1)
        {
            dfs(w + 1, h);
        }

        if (c[w - 1][h] == 1)
        {
            dfs(w - 1, h);
        }

        if (c[w][h - 1] == 1)
        {
            dfs(w, h - 1);
        }

        if (c[w][h + 1] == 1)
        {
            dfs(w, h + 1);
        }

        if (c[w + 1][h + 1] == 1)
        {
            dfs(w + 1, h + 1);
        }

        if (c[w + 1][h - 1] == 1)
            dfs(w + 1, h - 1);

        if (c[w - 1][h + 1] == 1)
            dfs(w - 1, h + 1);

        if (c[w - 1][h - 1] == 1)
            dfs(w - 1, h - 1);
    };
}

int main()
{
    vector<int> res;
    while (true)
    {
        int ans = 0;

        rep(i, 100) rep(j, 100)
        {
            c[i][j] = 0;
            seen[i][j] = 0;
        }

        cin >> wi >> he;
        if (wi == 0 && he == 0)
            break;

        repi(j, 1, he + 1) repi(i, 1, wi + 1)
        {
            cin >> c[i][j];
        };

        repi(i, 1, wi + 1) repi(j, 1, he + 1)
        {
            if (c[i][j] == 1 && seen[i][j] == false)
            {
                dfs(i, j);
                ans++;
            }
        }

        res.push_back(ans);
    }

    for (auto r : res)
    {
        cout << r << endl;
    }
    return 0;
}
