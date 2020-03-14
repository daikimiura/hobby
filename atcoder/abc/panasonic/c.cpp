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
  ll a, b, c;
  cin >> a >> b >> c;
  ll d = a + b - c;
  // if (d >= 0)
  // {
  //   cout << "No" << endl;
  // }
  // else
  // {
  //   if (pow(d, 2) - 4 * a * b > 0)
  //   {
  //     cout << "Yes" << endl;
  //   }
  //   else
  //   {
  //     cout << "No" << endl;
  //   }
  // }
  cout << pow(d, 2) << endl;
  if (d < 0 && pow(d, 2) - 4 * a * b > 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
