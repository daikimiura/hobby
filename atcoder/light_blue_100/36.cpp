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
  int N, Wt;
  int v[110], w[110];
  cin >> N >> Wt;

  rep(i, N)
  {
    cin >> v[i] >> w[i];
  }

  // dp[i][w]: i番目までの品物の中で大きさがwを超えないように選んだ時の価値の最大値
  int dp[110][10001] = {};

  rep(i, N)
  {
    rep(j, Wt + 1)
    {
      if (j >= w[i])
      {
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
      }
      else
      {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  cout << dp[N][Wt] << endl;

  return 0;
}
