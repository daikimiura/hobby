#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = 0x3f3f3f3f;
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

struct Cell
{
  double x, y, z, r;
};

struct Edge
{
  int a, b;
  double cost;

  bool operator<(const Edge &o) const
  {
    return cost < o.cost;
  }
};

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

int main()
{
  int n;

  for (;;)
  {
    cin >> n;
    if (n == 0)
      break;
    vector<Cell> cells;
    vector<Edge> es;

    rep(i, n)
    {
      double x, y, z, r;
      cin >> x >> y >> z >> r;
      Cell c;
      c.x = x;
      c.y = y;
      c.z = z;
      c.r = r;
      cells.push_back(c);
    }

    rep(i, cells.size()) repi(j, i + 1, cells.size())
    {
      Cell c1 = cells[i];
      Cell c2 = cells[j];
      double cost = sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2) + pow(c1.z - c2.z, 2)) - c1.r - c2.r;
      chmax(cost, 0.0);
      Edge e;
      e.a = i;
      e.b = j;
      e.cost = cost;
      es.push_back(e);
    }

    // クラスカル法
    sort(es.begin(), es.end());
    UnionFind uf(n);
    double ans = 0.0;

    rep(ei, es.size())
    {
      Edge e = es[ei];

      if (!uf.same(e.a, e.b))
      {
        ans += e.cost;
        uf.unite(e.a, e.b);
      }
    }

    cout << fixed << setprecision(3) << ans << endl;
  }

  return 0;
}
