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
  int d[510];
  ll ans_max = 0;
  int max_d = 0;
  rep(i, n)
  {
    cin >> d[i];
    ans_max += d[i];
    chmax(max_d, d[i]);
  }

  cout << ans_max << endl;
  cout << max(0LL, max_d - (ans_max - max_d)) << endl;

  return 0;
}
