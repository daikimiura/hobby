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
  int k, n;
  cin >> k >> n;

  int a[n];
  rep(i, n)
  {
    cin >> a[i];
  }

  sort(a, a + n);

  int tmp = 0;
  rep(i, n)
  {
    if (i == n - 1)
    {
      tmp = max(tmp,  k - a[i] + a[0]);
    }
    else
    {
      tmp = max(tmp, a[i + 1] - a[i]);
    }

  }

  cout << k - tmp << endl;
  return 0;
}
