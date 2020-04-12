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
  int k;
  cin >> k;

  ll ans = 0;
  repi(i, 1, k + 1) repi(j, 1, k + 1) repi(l, 1, k + 1)
  {
    ans += gcd(i, gcd(j, l));
  }

  cout << ans << endl;
  return 0;
}
