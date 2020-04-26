#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 2019;
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

struct mint
{
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint &operator+=(const mint a)
  {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const
  {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint &operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};

int main()
{
  string s;
  cin >> s;

  ll arr[200100] = {};
  ll count[3000] = {};

  int keta = 0;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    struct mint m(10);
    struct mint tmp(s[i] - '0');
    int val = (tmp * m.pow(keta)).x;
    arr[i] = (arr[i + 1] + val) % 2019;
    count[arr[i]]++;
    keta++;
  }

  ll ans = 0;
  rep(i, 2019)
  {
    if (i == 0)
    {
      if (count[i] == 0)
        continue;
      if (count[i] == 1)
      {
        ans++;
        continue;
      }
      ans += ((count[i] + 1) * count[i]) / 2;
      continue;
    }

    ans += (count[i] * (count[i] - 1)) / 2;
  }

  cout << ans << endl;

  return 0;
}
