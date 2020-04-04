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

int main()
{
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  vector<int> ans;

  rep(i, q)
  {
    int com, x, y;
    cin >> com >> x >> y;

    if (com == 0)
    {
      // unite
      uf.unite(x, y);
    }
    else if (com == 1)
    {
      // same
      if (uf.same(x, y))
        ans.push_back(1);
      else
        ans.push_back(0);
    }
  }

  for (auto i : ans)
  {
    cout << i << endl;
  }
  return 0;
}
