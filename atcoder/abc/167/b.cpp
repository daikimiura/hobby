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
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll ans = 0;
  for (;;)
  {
    rep(i, a)
    {
      if (k == 0)
      {
        cout << ans << endl;
        return 0;
      }

      ans++;
      k--;
    }

    rep(i, b)
    {
      if (k == 0)
      {
        cout << ans << endl;
        return 0;
      }

      k--;
    }

    rep(i, c)
    {
      if (k == 0)
      {
        cout << ans << endl;
        return 0;
      }

      ans--;
      k--;
    }
  }

  return 0;
}
