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
  ll n;
  cin >> n;
  vector<ll> a, a_top, a_under;

  rep(i, n + 1)
  {
    ll x;
    cin >> x;
    a.push_back(x);
  }

  ll tmp = 1;
  a_top.push_back(1);
  repi(i, 1, n + 1)
  {
    ll x;
    if (tmp - a[i - 1] < 0)
    {
      cout << -1 << endl;
      return 0;
    }

    if ((tmp - a[i - 1]) > 1e18 / 2)
    {
      x = 1e18 / 2;
    }
    else
    {
      x = (tmp - a[i - 1]) * 2;
    }
    a_top.push_back(x);
    tmp = x;
  }

  tmp = a[a.size() - 1];
  a_under.insert(a_under.begin(), tmp);
  repi(i, 1, n + 1)
  {
    ll x = ll(tmp + a[n - i]);
    a_under.insert(a_under.begin(), x);
    tmp = x;
  }

  ll ans = 0;
  ll tmp_num = 0;
  rep(i, n + 1)
  {
    if (i != 0 && a_top[i] <= 0 && a_under[i] <= 0)
    {
      cout << -1 << endl;
      return 0;
    }

    // cout << a_top[i] << " " << a_under[i] << endl;

    if (i == n && a_top[i] < a_under[i])
    {
      cout << -1 << endl;
      return 0;
    }
    else if (i == 0)
    {

      tmp_num = min(a_top[i], a_under[i]);
      ans += tmp_num;
    }
    else if (tmp_num * 2 >= min(a_top[i], a_under[i]))
    {
      tmp_num = min(a_top[i], a_under[i]);
      ans += tmp_num;
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans << endl;

  return 0;
}
