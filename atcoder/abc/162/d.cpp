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

int main()
{
  int n;
  cin >> n;

  ll ans = 0;
  vector<int> r;
  vector<int> g;
  vector<int> b;
  string s;
  cin >> s;

  rep(i, n)
  {
    if (s[i] == 'R')
      r.push_back(i);
    else if (s[i] == 'G')
      g.push_back(i);
    else if (s[i] == 'B')
      b.push_back(i);
  }
  ans = r.size() * g.size() * b.size();

  repi(aida, 0, n)
  {
    rep(i, n)
    {
      int j = i + aida;
      int k = j + aida;
      if (j <= n - 1 && k <= n - 1 && s[i] != s[j] && s[j] != s[k] && s[k] != s[i])
      {
        ans--;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
