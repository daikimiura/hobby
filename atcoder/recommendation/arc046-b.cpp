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
  ll n, a, b;
  cin >> n >> a >> b;
  if (n <= a)
  {
    cout << "Takahashi" << endl;
  }
  else if (a < n && n <= (1 + a))
  {
    cout << "Aoki" << endl;
  }
  else
  {
    cout << "Takahashi" << endl;
  }
  return 0;
}
