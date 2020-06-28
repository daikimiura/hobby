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
  int n;
  cin >> n;
  vector<ll> arr(10000005);

  rep(i, n + 1)
  {
    arr[i] = 1;
  }

  repi(i, 2, n + 1)
  {
    for (int j = 1; j <= n / i; j++)
    {
      arr[i * j]++;
    }
  }

  ll ans = 0;
  repi(i, 1, n + 1)
  {
    // cout << arr[i] << endl;
    ans += ll(i * arr[i]);
  }

  cout << ans << endl;
  return 0;
}
