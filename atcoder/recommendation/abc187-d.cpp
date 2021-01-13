#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
const int iINF = 0x3f3f3f3f;
const long long INF = 1LL << 60;
using namespace std;
using pint = pair<int, int>;

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
  ll n;
  ll diff = 0;
  cin >> n;
  ll p[n];
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    p[i] = 2 * x + y;
    diff += x;
  }

  sort(p, p + n);
  reverse(p, p + n);

  ll ans = 0;

  rep(i, n)
  {
    ans++;
    diff -= p[i];

    if (diff < 0)
    {
      cout << ans << endl;
      return 0;
    }
  }

  return 0;
}
