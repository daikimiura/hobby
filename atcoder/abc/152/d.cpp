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
  int n;
  cin >> n;

  int c[10][10];
  rep(i, 10)rep(j, 10){
    c[i][j] = 0;
  }
  repi(i, 1, n + 1)
  {
    string s = to_string(i);
    int first, last;
    first = s[0] - '0';
    last = s[s.length() - 1] - '0';
    c[first][last]++;
  }

  int ans = 0;
  rep(i, 10)
  {
    rep(j, 10)
    {
      ans += c[i][j] * c[j][i];
    }
  }

  cout << ans << endl;
  return 0;
}
