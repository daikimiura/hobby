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
  int a[32] = {1,
               1,
               1,
               2,
               1,
               2,
               1,
               5,
               2,
               2,
               1,
               5,
               1,
               2,
               1,
               14,
               1,
               5,
               1,
               5,
               2,
               2,
               1,
               15,
               2,
               2,
               5,
               4,
               1,
               4,
               1,
               51};

  int k;
  cin >> k;
  cout << a[k - 1] << endl;

  return 0;
}
