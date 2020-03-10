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
  int n, p;
  string s;
  cin >> n >> p >> s;

  ll ans = 0;
  if (p == 2 || p == 5)
  {
    rep(i, n)
    {
      if ((s[i] - '0') % p == 0)
      {
        ans += i + 1;
      }
    }
    cout << ans << endl;
    return 0;
  }

  vector<int> d(n + 1, 0);
  int ten = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    int a;
    a = (s[i] - '0') * ten % p;
    d[i] = (d[i + 1] + a) % p;
    ten *= 10;
    ten %= p;
  }

  vector<int> cnt(p, 0);

  for (int i = n; i >= 0; i--)
  {
    ans += cnt[d[i]];
    cnt[d[i]]++;
  }

  cout << ans << endl;
  return 0;
}
