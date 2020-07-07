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

int main()
{
  string x;
  cin >> x;

  reverse(x.begin(), x.end());
  int t_count = 0;
  int ans = 0;

  for (char c : x)
  {
    if (c == 'S')
    {
      if (t_count > 0)
      {
        t_count--;
      }
      else
      {
        ans++;
      }
    }
    else
    {
      t_count++;
    }
  }

  cout << ans * 2 << endl;
  return 0;
}
