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
  int n;
  cin >> n;
  vector<int> a;

  rep(i, n)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }

  sort(a.rbegin(), a.rend());

  ll ans = a[0];
  repi(i, 1, n - 1)
  {
    if (i % 2 == 1)
      ans += a[(i + 1) / 2];
    else
      ans += a[i / 2];
  }

  cout << ans << endl;
  return 0;
}
