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

int N, M;
ll dist[20][20];
ll d_time[20][20];
// dp[i][j] := 現在jにいて、今まで{i}を通った時の条件を満たす最短時間
ll dp[1 << 20][20];
// dp[i][j] := 現在jにいて、今まで{i}を通った時の条件を満たす最短時間の数
ll num[1 << 20][20];

int main()
{
  cin >> N >> M;

  rep(i, N) rep(j, N) dist[i][j] = INF;

  rep(i, M)
  {
    int x, y;
    ll s, t;
    cin >> x >> y >> s >> t;
    --x;
    --y;
    dist[x][y] = s;
    dist[y][x] = s;
    d_time[x][y] = t;
    d_time[y][x] = t;
  }

  for (int bit = 0; bit < (1 << N); bit++)
    rep(i, N)
    {
      dp[bit][i] = INF;
    }

  dp[0][0] = 0;
  num[0][0] = 1;

  rep(bit, 1 << N) rep(j, N)
  {
    rep(k, N)
    {
      if (dp[bit][j] + dist[j][k] > d_time[j][k] || (bit >> k & 1))
        continue;

      if (dp[bit | 1 << k][k] > dp[bit][j] + dist[j][k])
      {
        num[bit | 1 << k][k] = num[bit][j];
        dp[bit | 1 << k][k] = dp[bit][j] + dist[j][k];
      }
      else if (dp[bit | 1 << k][k] == dp[bit][j] + dist[j][k])
      {
        num[bit | 1 << k][k] += num[bit][j];
      }
    }
  }

  if (num[(1 << N) - 1][0] == 0)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << dp[(1 << N) - 1][0] << " " << num[(1 << N) - 1][0] << endl;

  return 0;
}
