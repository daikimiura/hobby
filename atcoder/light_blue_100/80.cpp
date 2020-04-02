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
  int h, w;
  ll k, v;
  cin >> h >> w >> k >> v;

  vector<vector<ll>> sum(h + 1, vector<ll>(w + 1));

  repi(i, 1, h + 1)
  {
    repi(j, 1, w + 1)
    {
      cin >> sum[i][j];
    }
  }

  repi(i, 1, h + 1) repi(j, 1, w + 1)
  {
    sum[i][j] += sum[i][j - 1];
  }

  repi(i, 1, h + 1) repi(j, 1, w + 1)
  {
    sum[i][j] += sum[i - 1][j];
  }

  int ans = 0;
  repi(ws, 1, w + 1) repi(we, ws, w + 1)
  {
    repi(hs, 1, h + 1) repi(he, hs, h + 1)
    {
      ll tmp = sum[he][we] + sum[hs - 1][ws - 1] - sum[hs - 1][we] - sum[he][ws - 1];
      if (tmp + (we - ws + 1) * (he - hs + 1) * k <= v)
      {
        chmax(ans, (we - ws + 1) * (he - hs + 1));
      }
    }
  }

  cout << ans << endl;
  return 0;
}
