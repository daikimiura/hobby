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

bool is_ok(ll num)
{
  for (int i = 2; i * i <= num; i++)
  {
    if (num % 5 != 1)
      return false;
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
  int n;
  cin >> n;

  vector<ll> primes;
  primes.push_back(11);

  ll tmp = 31;
  int count = 1;
  while (count < n)
  {
    if (is_ok(tmp))
    {
      primes.push_back(tmp);
      count++;
    }
    tmp++;
  }

  for (ll num : primes)
  {
    cout << num << " ";
  }
  return 0;
}
