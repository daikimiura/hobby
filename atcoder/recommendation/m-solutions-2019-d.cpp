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

vector<vector<int>> g(10005);
vector<int> c;
int ans[10005];
int start;

void dfs(int v, int parent = -1)
{
  if (g[v].size() == 0)
  {
    ans[v] = c[0];
    // cout << v + 1 << ":" << c[0] << endl;
    c.erase(c.begin());
    return;
  }

  if (parent != -1 && ans[parent] != -1)
  {
    ans[v] = c[0];
    // cout << v + 1 << ":" << c[0] << endl;
    c.erase(c.begin());
  }

  for (int i : g[v])
  {
    if (i != parent)
    {
      dfs(i, v);
      if (ans[i] == -1)
      {
        ans[i] = c[0];
        // cout << i + 1 << ":" << c[0] << endl;
        c.erase(c.begin());
      }

      if (ans[v] == -1)
      {
        ans[v] = c[0];
        // cout << v + 1 << ":" << c[0] << endl;
        c.erase(c.begin());
      }
    }
  }

  return;
}

int main()
{
  int n;
  cin >> n;

  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ll sum = 0;
  rep(i, n)
  {
    int x;
    cin >> x;
    c.push_back(x);
    ans[i] = -1;
  }

  sort(c.rbegin(), c.rend());

  rep(i, n)
  {
    if (i != 0)
      sum += c[i];
  }

  start = 0;
  dfs(start);

  cout << sum << endl;
  rep(i, n)
  {
    cout << ans[i] << endl;
  }

  return 0;
}
