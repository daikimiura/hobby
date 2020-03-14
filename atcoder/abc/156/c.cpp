#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long MOD = 1e9 + 7;
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
  int x[n];

  rep(i, n) {
    cin >> x[i];
  }

  ll ans = INF;

  repi(i, 1, 101) {
    ll power = 0;

    rep(j, n) {
      power += pow(x[j] - i, 2);
    }
    ans = min(ans, power);
  }

  cout << ans << endl;
  return 0;
}
