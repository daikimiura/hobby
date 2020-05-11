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
  int n;
  string c;
  cin >> n >> c;

  int ans = iINF;

  string b = "ABXY";
  rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4)
  {
    string L = "", R = "";
    L += b[i];
    L += b[j];
    R += b[k];
    R += b[l];

    int count = 0;
    rep(m, n)
    {
      if (m < n - 1 && (c.substr(m, 2) == L || c.substr(m, 2) == R))
        m++;
      count++;
    }

    chmin(ans, count);
  }

  cout << ans << endl;
  return 0;
}
