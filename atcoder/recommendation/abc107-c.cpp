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
  int n, k;
  cin >> n >> k;
  vector<ll> left, right;

  rep(i, n)
  {
    int x;
    cin >> x;
    if (x <= 0)
      left.push_back(-x);
    else
      right.push_back(x);
  }

  reverse(left.begin(), left.end());

  ll ans;

  if (right.size() >= k)
  {
    ans = right[k - 1];
  }
  else
  {
    ans = iINF;
  }

  rep(i, left.size())
  {
    if (k - i - 1 > right.size())
      continue;

    if (i > k - 1)
      continue;

    if (i == k - 1)
    {
      chmin(ans, left[i]);
      continue;
    }

    chmin(ans, left[i] + right[k - i - 2] + min(left[i], right[k - i - 2]));
  }

  cout << ans << endl;
  return 0;
}
