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
  if (n % 2 == 0 || n == 1)
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
    cout << 3 << endl;
    rep(i, 2)
    {
      cout << (n + 1) / 2 << " ";
      rep(j, (n + 1) / 2)
      {
        if (i == 0)
          cout << j + 1 << " ";
        else
          cout << j + (n + 1) / 2 << " ";
      }
      cout << endl;
    }
    cout << 2 << " " << 1 << " " << n << endl;
  }
  return 0;
}
