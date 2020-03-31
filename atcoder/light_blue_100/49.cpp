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
vector<vector<int>> g(16);
int dp[(1 << 15) + 1][16];

int rec(int bit, int v)
{
  // すでに探索済みだったらリターン
  if (dp[bit][v] != -1)
    return dp[bit][v];

  // 初期値
  if (bit == (1 << v))
  {
    return dp[bit][v] = 0;
  }

  // 答えを格納する変数
  int res = INF;

  // bit の v を除いたもの
  int prev_bit = bit & ~(1 << v);
  cout << "bit: " << bitset<4>(bit) << endl;
  cout << "prev_bit: " << bitset<4>(prev_bit) << endl;
  cout << "v: " << v << endl;
  // v の手前のノードとして u を全探索
  for (int u = 0; u < V; ++u)
  {
    if (!(prev_bit & (1 << u)))
      continue; // u が prev_bit になかったらダメ

    if (dist[u][v] == -1)
      continue;

    cout << u << "=>" << v << endl;

    // 再帰的に探索
    res = min(res, rec(prev_bit, u) + dist[u][v]);
  }

  return dp[bit][v] = res; // メモしながらリターン
}

int rec2(int bit, int v)
{
  // すでに探索済みだったらリターン
  if (dp[bit][v] != -1)
    return dp[bit][v];

  // 初期値
  if (bit == (1 << V) - 1 && v == 0)
  {
    return dp[bit][v] = 0;
  }

  // 答えを格納する変数
  int res = INF;

  // v の次のノードとして u を全探索
  for (int u = 0; u < V; ++u)
  {
    if (bit >> u & 1)
      continue; // すでにuを使ってたらダメ

    // cout << u << "=>" << v << endl;

    // 再帰的に探索
    res = min(res, rec2(bit | 1 << u, u) + dist[v][u]);
  }

  return dp[bit][v] = res; // メモしながらリターン
}

int main()
{
  cin >> V >> E;

  rep(i, E)
  {
    int s, t, d;
    cin >> s >> t >> d;
    dist[s][t] = d;
    g[s].push_back(t);
  }

  for (int bit = 0; bit < (1 << V); ++bit)
    for (int v = 0; v < V; ++v)
      dp[bit][v] = -1;

  int res = INF;

  res = rec2(0, 0);

  cout << (res == INF ? -1 : res) << endl;

  return 0;
}
