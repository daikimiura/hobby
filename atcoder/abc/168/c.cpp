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
  double a, b;
  int h, m;
  cin >> a >> b >> h >> m;
  double deg = abs(360 * m / 60 - (360 * h / 12 + 0.5 * m));
  double ans = sqrt(a * a + b * b - 2 * a * b * cos(deg * M_PI / 180));
  cout << setprecision(15) << ans << endl;
  return 0;
}
