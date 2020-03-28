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
  int n, k;
  cin >> n >> k;

  // dp[x][y][z]: x-1日目にyを食べて、x日目にzを食べた時の組み合わせの総数
  ll dp[110][4][4] = {};
  int sche[110] = {};

  rep(i, k)
  {
    int a, b;
    cin >> a >> b;
    sche[a] = b;
  }

  repi(i, 1, 4) repi(j, 1, 4)
  {
    if ((sche[1] != 0 && sche[1] != i) || (sche[2] != 0 && sche[2] != j))
    {
      continue;
    }
    dp[2][i][j] = 1;
  }

  repi(i, 2, n)
  {
    repi(j, 1, 4)
    {
      repi(k, 1, 4)
      {
        repi(l, 1, 4)
        {
          if (j == k && k == l) // 3日連続同じものとなる場合
            continue;
          if (sche[i + 1] != 0 && sche[i + 1] != k) // すでに決まってるものと異なる場合
            continue;
          dp[i + 1][j][k] += dp[i][l][j] % 10000;
        }
      }
    }
  }

  ll ans = 0;
  repi(i, 1, 4) repi(j, 1, 4)
  {
    ans = (ans += dp[n][i][j]) % 10000;
  }

  cout << ans << endl;
  return 0;
}
