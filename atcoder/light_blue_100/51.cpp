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
  string s;
  cin >> n >> s;
  int s2[1100];

  // dp[i][bit] := i日目の部活にsが参加してる時の場合の数
  // bit := joi
  ll dp[1100][1 << 3] = {};

  rep(i, n)
  {
    switch (s[i])
    {
    case 'J':
      s2[i] = 0b100;
      break;
    case 'O':
      s2[i] = 0b010;
      break;
    case 'I':
      s2[i] = 0b001;
      break;
    }
  }

  rep(i, n)
  {
    if (i == 0)
    {
      for (int bit = 1; bit < (1 << 3); bit++)
      {
        if (((bit >> 2) & 1) && ((s2[i] & bit) != 0))
          dp[i][bit] = 1;
      }
      continue;
    }

    for (int bit = 1; bit < (1 << 3); bit++)
    {
      for (int prev_bit = 1; prev_bit < (1 << 3); prev_bit++)
      {
        if ((bit & prev_bit) != 0 && ((s2[i] & bit) != 0))
        {
          dp[i][bit] = (dp[i][bit] + dp[i - 1][prev_bit]) % 10007;
        }
      }
    }
  }

  ll ans = 0;
  for (int bit = 1; bit < (1 << 3); bit++)
  {
    ans = (ans + dp[n - 1][bit]) % 10007;
  }

  cout << ans << endl;

  return 0;
}
