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

vector<int> IntegerToVector(int bit, int N)
{
  vector<int> S;
  for (int i = 0; i < N; ++i)
  {
    if (bit & (1 << i))
    {
      S.push_back(i);
    }
  }
  return S;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  vector<int> p;

  rep(i, m)
  {
    int k;
    cin >> k;

    rep(j, k)
    {
      int st;
      cin >> st;
      s[i].push_back(st);
    }
  }

  rep(i, m)
  {
    int x;
    cin >> x;
    p.push_back(x);
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    bool is_ok = true;
    rep(i, m)
    {
      int on_count = 0;
      for (auto ss : s[i])
      {
        if ((bit >> (ss-1)) & 1)
          on_count++;
      }

      if (on_count % 2 != p[i])
        is_ok = false;
    }

    if (is_ok)
    {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
