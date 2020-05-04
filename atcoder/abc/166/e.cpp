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
  vector<int> sum, diff;
  cin >> n;
  rep(i, n)
  {
    int x;
    cin >> x;
    sum.push_back(x + i + 1);
    diff.push_back(i + 1 - x);
  }
  ll ans = 0;
  sort(diff.begin(), diff.end());
  rep(i, n)
  {
    int tmp = sum[i];
    auto l = lower_bound(diff.begin(), diff.end(), tmp);
    auto u = upper_bound(diff.begin(), diff.end(), tmp);
    if (l == diff.end() && u == diff.end())
      continue;
    ans += (u - diff.begin()) - (l - diff.begin());
  }
  cout << ans << endl;
  return 0;
}
