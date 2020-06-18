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

int main()
{
  int q;
  cin >> q;

  bool is_ok[100010], is_prime[100010];
  int sum[100010];

  is_prime[1] = false;

  for (int i = 2; i <= 100004; i++)
  {
    is_prime[i] = true;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
        is_prime[i] = false;
    }
  }

  is_ok[1] = false;
  for (int i = 2; i <= 100004; i++)
  {
    if (i % 2 == 0)
      is_ok[i] = false;
    else if (is_prime[i] && is_prime[(i + 1) / 2])
    {
      is_ok[i] = true;
    }
    else
    {
      is_ok[i] = false;
    }
  }

  sum[1] = 0;
  int tmp = 0;
  for (int i = 2; i <= 100002; i++)
  {
    if (is_ok[i])
    {
      sum[i] = ++tmp;
    }
    else
      sum[i] = tmp;
  }

  int ls[100005], rs[100005];

  rep(i, q)
  {
    cin >> ls[i] >> rs[i];
  }

  rep(i, q)
  {
    cout << sum[rs[i]] - sum[max(ls[i] - 2, 1)] << endl;
  }

  // repi(i, 1, 10)
  // {
  //   cout << is_prime[i] << " ";
  // }
  // cout << endl;

  // repi(i, 1, 10)
  // {
  //   cout << is_ok[i] << " ";
  // }
  // cout << endl;
  return 0;
}
