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
  ll h;
  cin >> n >> h;
  vector<pair<ll, string>> k;
  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    k.push_back({x, "a"});
    k.push_back({y, "b"});
  }

  sort(k.rbegin(), k.rend());

  ll ans = 0;
  for (;;)
  {
    for (auto p : k)
    {
      if (p.second == "a")
      {
        while (h > 0)
        {
          h -= p.first;
          ans++;
        }
      }
      else
      {
        h -= p.first;
        ans++;
      }

      if (h <= 0)
      {
        cout << ans << endl;
        return 0;
      }
    }
  }
  return 0;
}
