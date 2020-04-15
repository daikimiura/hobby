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
  int D, N;
  cin >> D >> N;
  int t[210], c[210][3];

  rep(i, D)
  {
    cin >> t[i];
  }

  rep(i, N)
  {
    rep(j, 3)
    {
      cin >> c[i][j];
    }
  }

  // dp[i][j] := i日目に服jを選んだ時の派手さの差の合計値の最大値
  int dp[210][210] = {};

  rep(i, D) rep(j, N)
  {
    if (c[j][0] <= t[i] && t[i] <= c[j][1])
    {
      rep(k, N)
      {
        if (c[k][0] <= t[i + 1] && t[i + 1] <= c[k][1])
        {
          dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + abs(c[j][2] - c[k][2]));
        }
      }
    }
  }

  int ans = 0;
  rep(j, N)
  {
    chmax(ans, dp[D - 1][j]);
  }
  cout << ans << endl;

  return 0;
}
