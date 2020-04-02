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
struct UnionFind
{
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {}
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
    if (d[x] > d[y])
      swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};

struct Edge
{
  int a, b, cost;

  bool operator<(const Edge &o) const
  {
    return cost < o.cost;
  }
};

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<Edge> es;
  rep(i, m)
  {
    Edge e;
    int a, b, cost;
    cin >> a >> b >> cost;
    --a;
    --b;
    e.a = a;
    e.b = b;
    e.cost = cost;
    es.push_back(e);
  }

  set<int> parents;
  // クラスカル法
  sort(es.begin(), es.end());
  UnionFind uf(n);
  int min_cost = 0;
  int num_city = n;

  rep(ei, es.size())
  {
    Edge &e = es[ei];

    if (!uf.same(e.a, e.b))
    {
      if (num_city == k)
      {
        cout << min_cost << endl;
        return 0;
      }
      min_cost += e.cost;
      uf.unite(e.a, e.b);
      num_city--;
    }
  }

  cout << min_cost << endl;
  return 0;
}
