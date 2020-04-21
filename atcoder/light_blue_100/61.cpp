#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = INT_MAX;
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

int main()
{
  int n, m;
  cin >> n >> m;

  int d[310][310];
  rep(i, n) fill(d[i], d[i] + n, iINF / 2);

  rep(i, m)
  {
    int a, b, t;
    cin >> a >> b >> t;
    --a;
    --b;
    d[a][b] = t;
    d[b][a] = t;
  }

  for (int k = 0; k < n; k++)
  { // 経由する頂点
    for (int i = 0; i < n; i++)
    { // 始点
      for (int j = 0; j < n; j++)
      { // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans = iINF;
  rep(i, n)
  {
    int tmp = 0;
    rep(j, n)
    {
      if (i == j)
        continue;
      tmp = max(tmp, d[i][j]);
    }
    ans = min(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
