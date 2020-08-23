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

int main()
{
  int n;
  cin >> n;
  int a[10010];
  rep(i, n) cin >> a[i];

  vector<ll> num(1100000, 0);

  rep(i, n)
  {
    auto prime = prime_factor(a[i]);
    for (auto p : prime)
    {
      num[p.first] = max(num[p.first], ll(p.second));
    }
  }

  mint lcm = 1;
  repi(i, 2, 1100000)
  {
    lcm *= mint(i).pow(num[i]);
  }

  mint ans = 0;
  rep(i, n)
  {
    ans += (lcm / a[i]);
  }

  cout << ans.x << endl;

  return 0;
}
