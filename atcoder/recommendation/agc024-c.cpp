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
  int n;
  cin >> n;
  int a[200005];
  rep(i, n)
  {
    cin >> a[i];
  }

  if (a[0] != 0)
  {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  int tmp = 0; // a[0]
  repi(i, 1, n)
  {
    if (tmp + 2 <= a[i])
    {
      cout << -1 << endl;
      return 0;
    }

    if (tmp + 1 == a[i])
    {
      ans++;
    }
    else
    {
      ans += a[i];
    }
    tmp = a[i];
  }

  cout << ans << endl;
  return 0;
}
