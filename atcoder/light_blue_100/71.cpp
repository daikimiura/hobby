#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
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

const int mod = 1000000007;

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

mint comb(int n, int a)
{
  mint x = 1, y = 1;
  rep(i, a)
  {
    x *= n - i;
    y *= i + 1;
  }
  return x / y;
}

int main()
{
  int n, q;
  cin >> n >> q;

  int a[120100];
  int c[120100];
  ll cost[120100];

  rep(i, n)
  {
    cin >> a[i];
  }

  rep(i, q)
  {
    cin >> c[i];
  }

  rep(i, n - 1)
  {
    struct mint m(a[i]);
    int idx = i + 1;
    cost[idx] = m.pow(a[i + 1]).x;
  }

  repi(i, 2, n)
  {
    cost[i] += cost[i - 1];
  }

  int now = 1;
  int next;
  ll ans = 0;
  rep(i, q)
  {
    next = c[i];
    if (now < next)
    {
      ans += (cost[next - 1] - cost[now - 1]) % mod;
      ans %= mod;
    }
    else
    {
      ans += (cost[now - 1] - cost[next - 1]) % mod;
      ans %= mod;
    }

    now = next;
  }
  ans += (cost[next - 1] - cost[0]) % mod;
  ans %= mod;

  cout << ans << endl;
  return 0;
}
