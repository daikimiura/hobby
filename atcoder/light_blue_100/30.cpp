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

pair<int, int> start;
vector<string> mp;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int h, w, n;

struct P
{
    pair<int, int> pos;
    int cost;
};

P bfs(char goal, int x, int y)
{
    queue<P> q;
    bool seen[1010][1010] = {};
    q.push({{x, y}, 0});

    while (!q.empty())
    {
        P v = q.front();
        q.pop();

        pair<int, int> now = v.pos;

        if (seen[now.first][now.second])
            continue;
        seen[now.first][now.second] = true;

        if (mp[now.first][now.second] == goal)
            return v;

        rep(i, 4)
        {
            pair<int, int> next;
            next.first = now.first + dx[i];
            next.second = now.second + dy[i];

            if (next.first >= 0 && next.first < h && next.second >= 0 && next.second < w && mp[next.first][next.second] != 'X')
            {
                q.push({{next.first, next.second}, v.cost + 1});
            }
        }
    }
    return {{x, y}, 100000};
}

int main()
{
    cin >> h >> w >> n;

    rep(i, h)
    {
        string s;
        cin >> s;
        mp.push_back(s);
        rep(j, w)
        {
            if (s[j] == 'S')
            {
                start = {i, j};
            }
        }
    };

    int ans = 0;
    rep(i, n)
    {
        P result = bfs('0' + (i + 1), start.first, start.second);
        start = result.pos;
        ans += result.cost;
    }

    cout << ans << endl;
    return 0;
}