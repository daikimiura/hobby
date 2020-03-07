#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long MOD = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;
#define N 100010

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

struct UnionFind
{
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1){};

  int find(int x)
  {
    if (d[x] < 0)
      return x;
    return d[x] = find(d[x]);
  }

  bool unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (-d[x] < -d[y])
      swap(x, y);
    // x に y をくっつける
    // x のサイズの方が大きくなければいけないので、そうでない場合は上でswap
    d[x] += d[y];
    d[y] = x;
    return true;
  }

  bool same(int x, int y) { return find(x) == find(y); };

  int size(int x) { return -d[find(x)]; };
};

int deg[100005];
vector<int> to[100005];

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  UnionFind uf(n); // 初期化

  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    deg[a]++;
    deg[b]++;
    uf.unite(a, b);
  }

  rep(i, k)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  rep(i, n)
  {
    int ans = uf.size(i) - 1 - deg[i];

    for (int u : to[i])
    {
      if (uf.same(i, u))
        --ans;
    };

    cout << ans << " ";
  }
  cout << endl;

  return 0;
}
