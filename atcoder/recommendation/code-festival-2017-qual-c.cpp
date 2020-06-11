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

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  bool ok = true;
  while (s.size() >= 2)
  {
    if (s[0] == s[s.size() - 1])
    {
      s = s.substr(1, s.size() - 2);
      continue;
    }

    if (s[0] == 'x')
    {
      ans++;
      s = s.substr(1, s.size() - 1);
      continue;
    }

    if (s[s.size() - 1] == 'x')
    {
      ans++;
      s = s.substr(0, s.size() - 1);
      continue;
    }

    ok = false;
    break;
  }

  if (ok)
  {
    cout << ans << endl;
  }
  else
  {
    cout << -1 << endl;
  }
  return 0;
}
