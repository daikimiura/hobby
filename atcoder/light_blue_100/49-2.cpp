#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const long long INF = 10000;
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

int V, E;
vector<vector<int>> dist(16, vector<int>(16, INF));
// dp[i][j] := 今まで{i}を通って現在jにいる時の最短経路長
int dp[(1 << 15) + 1][16];

int main()
{
  cin >> V >> E;

  rep(i, E)
  {
    int s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
  }

  for (int bit = 0; bit < (1 << V); ++bit)
    for (int v = 0; v < V; ++v)
      dp[bit][v] = 10000;

  dp[0][0] = 0;

  rep(bit, 1 << V) rep(j, V)
  {
    rep(k, V)
    {
      if (bit >> k & 1)
        continue; // kを使用済み
      int next_bit = (bit | 1 << k);

      dp[next_bit][k] = min(dp[next_bit][k], dp[bit][j] + dist[j][k]);
    }
  }

  cout << (dp[(1 << V) - 1][0] == 10000 ? -1 : dp[(1 << V) - 1][0]) << endl;

  return 0;
}
