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

int n;
vector<int> h, s;

bool check(ll mid)
{
  vector<double> lim_time;
  rep(i, n)
  {
    lim_time.push_back(double(mid - h[i]) / s[i]);
  }

  sort(lim_time.begin(), lim_time.end());

  rep(i, n)
  {
    if (lim_time[i] < i)
      return false;
  }

  return true;
}

int main()
{
  cin >> n;
  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    h.push_back(x);
    s.push_back(y);
  }

  ll left = 0;
  ll right = 1e16;

  while (right - left > 1)
  {
    ll mid = (left + right) / 2;
    if (check(mid))
      right = mid;
    else
      left = mid;
  }

  cout << right << endl;

  return 0;
}
