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

int c[10][10];

int main()
{
  int h, w;
  cin >> h >> w;

  rep(i, 10) rep(j, 10)
  {
    cin >> c[i][j];
  }

  rep(k, 10) rep(i, 10) rep(j, 10)
  {
    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
  }

  ll ans = 0;
  rep(i, h) rep(i, w)
  {
    int a;
    cin >> a;
    if (a == -1)
      continue;
    ans += c[a][1];
  }

  cout << ans << endl;

  return 0;
}
