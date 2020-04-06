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
  cin >> n;

  int ans = 0;
  repi(i, 1, n + 1)
  {
    int count = 0;
    for (int j = 1; j * j < i; j++)
    {
      if (i % j == 0)
        count += 2;
    }

    if (i % 2 == 1 && count == 8)
    {
      cout << i << endl;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
