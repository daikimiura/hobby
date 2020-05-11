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
  ll n, k;
  cin >> n >> k;
  ll a[100100];
  rep(i, n)
  {
    cin >> a[i];
  }

  repi(i, 1, n)
  {
    a[i] += a[i - 1];
  }

  ll ans = 0;

  auto bo = lower_bound(a, a + n, k);
  if (bo != a + n)
  {
    ll idx = a + n - bo;
    ans += idx;
  }

  rep(i, n - 1)
  {
    auto bo = lower_bound(a, a + n, a[i] + k);
    if (bo != a + n)
    {
      ll idx = a + n - bo;
      ans += idx;
    }
  }

  cout << ans << endl;
  return 0;
}
