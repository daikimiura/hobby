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

map<int64_t, int> prime_factor(int64_t n)
{
  map<int64_t, int> ret;
  for (int64_t i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
}

int main()
{
  ll n;
  cin >> n;

  map<ll, ll> mp;

  ll tmp = -1;
  for (auto p : prime_factor(n))
  {
    while (p.second--)
    {
      mp[p.first]++;
    }
  }

  ll ans = 0;
  for (auto mi : mp)
  {
    ll v = mi.second;
    int tmp = 1;
    for (;;)
    {
      if (v - tmp < 0)
        break;

      ans++;
      v -= tmp;
      tmp++;
    }
  }
  cout << ans << endl;
  return 0;

  // return 0;
}
