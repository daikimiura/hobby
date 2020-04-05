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
  ll n;
  cin >> n;

  ll count = 0;
  set<ll> ans;
  if (n > 2)
  {
    ans.insert(n - 1);
  }

  ans.insert(n);
  for (ll i = 2; i * i <= n - 1; i++)
  {
    if ((n - 1) % i == 0)
    {
      ans.insert(i);
      ans.insert((n - 1) / i);
    }

    if (i * i == n - 1)
    {
      ans.insert(i);
    }
  };

  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;

    ll tmp = n / i;
    while (tmp % i == 0)
    {
      tmp = tmp / i;
    }

    if (tmp % i == 1)
      ans.insert(i);
  }

  cout << ans.size() << endl;
  return 0;
}
