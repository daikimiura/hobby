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
  ll ans = 1;
  cin >> n;
  vector<ll> a;
  rep(i, n)
  {
    ll x;
    cin >> x;
    a.push_back(x);
    if (x == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }

  for (auto ai : a)
  {
    if (ans > 1000000000000000000 / ai)
    {
      cout << -1 << endl;
      return 0;
    }
    ans *= ai;
  }

  cout << ans << endl;
  return 0;
}
