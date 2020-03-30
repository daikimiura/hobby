#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
// const long long INF = 1LL << 60;
int INF = 10000;
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

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  --x;
  --y;

  vector<vector<int>> g(2010);

  rep(i, n)
  {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }

  g[x].push_back(y);
  g[y].push_back(x);

  vector<int> ans(n);

  rep(sv, n)
  {
    vector<int> dist(n, 10000);
    queue<int> q;

    dist[sv] = 0;
    q.push(sv);

    while (!q.empty())
    {
      int v = q.front();
      q.pop();
      for (auto next_v : g[v])
      {
        if (dist[next_v] == INF)
        {
          dist[next_v] = dist[v] + 1;
          q.push(next_v);
        }
      }
    }

    rep(i, n) ans[dist[i]]++;
  }

  repi(i, 1, n)
  {
    cout << ans[i] / 2 << endl;
  }
  return 0;
}