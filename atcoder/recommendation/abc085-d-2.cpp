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
  int n, h;
  cin >> n >> h;
  vector<int> a, b;
  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
  }

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  int max_a = a[0];

  int ans = 0;
  rep(i, n)
  {
    if (b[i] <= max_a)
      break;

    ans++;
    h -= b[i];
    // cout << b[i] << endl;
    if (h <= 0)
    {
      cout << ans << endl;
      return 0;
    }
  }

  while (h > 0)
  {
    ans++;
    // cout << max_a << endl;
    h -= max_a;
  }

  cout << ans << endl;

  return 0;
}
