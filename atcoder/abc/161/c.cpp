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
  ll n, k;
  cin >> n >> k;

  if (n == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  if (n < k)
  {
    cout << min(n, k-n) << endl;
    return 0;
  }
  
  ll amari = n % k;
  cout << min(k - amari, amari) << endl;
  return 0;
}
