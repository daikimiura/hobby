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
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p, q, r;
  rep(i, a)
  {
    ll tmp;
    cin >> tmp;
    p.push_back(tmp);
  }

  rep(i, b)
  {
    ll tmp;
    cin >> tmp;
    q.push_back(tmp);
  }

  rep(i, c)
  {
    ll tmp;
    cin >> tmp;
    r.push_back(tmp);
  }

  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  sort(q.begin(), q.end());
  reverse(q.begin(), q.end());
  sort(r.begin(), r.end());
  reverse(r.begin(), r.end());

  vector<ll> merged;

  rep(i, x)
  {
    merged.push_back(p[i]);
  }

  rep(i, y)
  {
    merged.push_back(q[i]);
  }

  rep(i, r.size())
  {
    merged.push_back(r[i]);
  }

  sort(merged.begin(), merged.end());
  reverse(merged.begin(), merged.end());

  ll ans = 0;
  rep(i, x + y)
  {
    ans += merged[i];
  }

  cout << ans << endl;

  return 0;
}
