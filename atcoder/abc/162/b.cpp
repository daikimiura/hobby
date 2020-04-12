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
  int n;
  ll ans = 0;
  cin >> n;
  repi(i, 1, n + 1)
  {
    if (i % 15 == 0)
      continue;
    if (i % 5 == 0)
      continue;
    if (i % 3 == 0)
      continue;
    ans += i;
  }

  cout << ans << endl;
  return 0;
}
