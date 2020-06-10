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

map<int64_t, int> prime_factor(int64_t n)
{
  map<int64_t, int> ret;
  for (int64_t i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1)
    ret[n] = 1;
  return ret;
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
  int n;
  cin >> n;

  ll count[1000];

  rep(i, 1000)
      count[i] = 0;

  repi(i, 1, n + 1)
  {
    for (auto p : prime_factor(i))
    {
      while (p.second--)
      {
        count[p.first]++;
      }
    }
  }

  mint ans = {1};
  repi(i, 2, n + 1)
  {
    if (count[i] != 0)
      ans *= (count[i] + 1);
  }

  cout << ans.x << endl;
  return 0;
}
