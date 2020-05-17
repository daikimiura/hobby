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

int n, m;
int seen[100100] = {};
vector<vector<int>> g(100100, vector<int>());

int main()
{
  cin >> n >> m;
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  rep(i, n) seen[i] = -1;

  queue<int> q;
  q.push(0);
  seen[0] = 1;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();

    for (auto i : g[v])
    {
      if (seen[i] == -1)
      {
        seen[i] = v;
        q.push(i);
      }
    }
  }

  bool flag = true;
  repi(i, 1, n)
  {
    if (seen[i] == -1)
      flag = false;
  }

  if (flag)
  {
    cout << "Yes" << endl;
    repi(i, 1, n)
    {
      cout << seen[i] + 1 << endl;
    }
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
