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
  ll n;
  cin >> n;

  string ans = "";
  repi(i, 1, 20)
  {
    if (n <= pow(26, i))
    {
      n -= 1;
      rep(j, i)
      {
        ans += 'a' + (n % 26);
        n /= 26;
      }
      break;
    }
    n -= pow(26, i);
  }

  reverse(ans.begin(), ans.end());
  cout << ans << endl;

  return 0;
}
