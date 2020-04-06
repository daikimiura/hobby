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
  int ans = 0;

  rep(i, 1000)
  {
    char s1 = '0' + (i / 100);
    char s2 = '0' + ((i % 100) / 10);
    char s3 = '0' + ((i % 10));

    char chars[] = {s1, s2, s3};
    char tmp = 0;
    rep(i, n)
    {
      if (chars[tmp] == s[i])
      {
        if (tmp == 0)
        {
          tmp = 1;
          continue;
        }
        if (tmp == 1)
        {
          tmp = 2;
          continue;
        }
        if (tmp == 2)
        {
          ans++;
          break;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}
