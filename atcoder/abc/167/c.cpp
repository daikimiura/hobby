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
  int n, m, x;
  cin >> n >> m >> x;

  int c[100];
  int a[100][100];

  rep(i, n)
  {
    cin >> c[i];
    rep(j, m)
    {
      cin >> a[i][j];
    }
  }

  ll ans = iINF;

  for (int bit = 0; bit < (1 << n); ++bit)
  {
    int skill[100] = {0};
    vector<int> S;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
      if (bit & (1 << i))
      {
        rep(j, m)
        {
          skill[j] += a[i][j];
        }
        sum += c[i];
      }
    }

    bool flag = true;

    rep(i, m)
    {
      if (skill[i] < x)
      {
        flag = false;
      }
    }
    if (flag)
    {
      chmin(ans, sum);
    }
  }
  if (ans == iINF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
