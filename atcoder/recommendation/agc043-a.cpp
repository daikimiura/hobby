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

char g[110][110];
int ans = iINF;
int h_max, w_max;

int main()
{

  cin >> h_max >> w_max;

  int dp[110][110];

  rep(i, h_max) rep(j, w_max)
  {
    cin >> g[i][j];
    dp[i][j] = iINF;
  }

  ;
  dp[0][0] = g[0][0] == '#' ? 1 : 0;

  int dx[2] = {1, 0};
  int dy[2] = {0, 1};

  rep(i, h_max) rep(j, w_max)
  {
    rep(k, 2)
    {
      int next_i = i + dx[k];
      int next_j = j + dy[k];

      if (next_i >= h_max || next_j >= w_max)
        continue;

      int count = 0;
      if (g[i][j] == '.' && g[next_i][next_j] == '#')
        count++;
      chmin(dp[next_i][next_j], dp[i][j] + count);
    }
  }

  cout << dp[h_max - 1][w_max - 1] << endl;
  return 0;
}
