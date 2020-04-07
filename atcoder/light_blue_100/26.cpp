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

int n, q;
vector<vector<int>> g(200100);
ll c[200100];

// p: parent
void calc(int v, int p = -1)
{
  for (auto u : g[v])
  {
    if (u == p)
      continue; // 親には戻らない
    c[u] += c[v];
    calc(u, v);
  }
}

int main()
{
  cin >> n >> q;
  memset(c, 0, sizeof(c));
  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rep(i, q)
  {
    int p, x;
    cin >> p >> x;
    c[p] += x;
  }

  calc(1);

  repi(i, 1, n + 1)
  {
    cout << c[i] << " ";
  }
  cout << endl;
  return 0;
}
