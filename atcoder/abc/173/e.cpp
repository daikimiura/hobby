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

int main()
{
  int n, k;
  cin >> n >> k;
  vector<pair<int, bool>> mps, mps2;
  bool is_zero = false;

  rep(i, n)
  {
    int a;
    cin >> a;

    if (a != 0)
    {
      mps.push_back({abs(a), a > 0});
      mps2.push_back({abs(a), a > 0});
    }
    else
    {
      is_zero = true;
    }
  }

  sort(mps.rbegin(), mps.rend());

  mint ans = {1};
  int count = 0;
  vector<int> minuses;
  bool is_ok = false;
  vector<int> minus_indexes;

  rep(i, n)
  {
    if (!mps[i].second)
      minus_indexes.push_back(i);
  }

  rep(i, n)
  {
    if (mps.size() - 1 < i)
    {
      break;
    }

    if (mps[i].second)
    {
      ans *= mps[i].first;
      count++;
    }
    else if (k - count >= 2 && minus_indexes.size() >= 2)
    {
      ans *= mps[i].first;
      minus_indexes.erase(minus_indexes.begin());
      ans *= mps[minus_indexes[0]].first;
      minus_indexes.erase(minus_indexes.begin());
      count += 2;
    }

    if (count == k)
    {
      is_ok = true;
      break;
    }
  }

  if (!is_ok)
  {
    if (is_zero)
      ans *= 0;
    else
    {
      ans = 1;
      sort(mps2.begin(), mps2.end());
      rep(i, k)
      {
        ans *= mps2[i].first;
      }
      ans *= -1;
    }
  }
  cout << ans.x << endl;

  return 0;
}
