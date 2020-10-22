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
  int n, m;
  cin >> n >> m;

  ll sums[8][n];

  rep(i, n)
  {
    ll x, y, z;
    cin >> x >> y >> z;
    sums[0][i] = x + y + z;
    sums[1][i] = x + y - z;
    sums[2][i] = -x + y + z;
    sums[3][i] = -x + y - z;
    sums[4][i] = x - y + z;
    sums[5][i] = x - y - z;
    sums[6][i] = -x - y + z;
    sums[7][i] = -x - y - z;
  }

  rep(i, 8)
  {
    sort(sums[i], sums[i] + n, greater<>());
  }

  ll ans = 0;
  rep(i, 8)
  {
    ll total = 0;
    rep(j, m)
    {
      total += sums[i][j];
    }

    chmax(ans, total);
  }

  cout << ans << endl;

  return 0;
}
