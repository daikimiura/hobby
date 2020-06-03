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
  ll ans;
  cin >> n;
  vector<int> a;
  rep(i, n)
  {
    int x;
    cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());

  bool ok = true;
  if (n % 2 == 1)
  {
    if (a[0] != 0)
      ok = false;

    int tmp = 2;
    int count = 0;
    repi(i, 1, n)
    {
      if (a[i] != tmp)
        ok = false;

      if (count == 0)
      {
        count++;
      }
      else
      {
        count = 0;
        tmp += 2;
      }
    }

    ans = mint(2).pow(n / 2).x;
  }
  else
  {
    int tmp = 1;
    int count = 0;
    rep(i, n)
    {
      if (a[i] != tmp)
        ok = false;

      if (count == 0)
      {
        count++;
      }
      else
      {
        count = 0;
        tmp += 2;
      }
    }

    ans = mint(2).pow(n / 2).x;
  }

  if (ok)
  {
    cout << ans << endl;
  }
  else
  {
    cout << 0 << endl;
  }

  return 0;
}
