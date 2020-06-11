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
  int n;
  cin >> n;
  int p[200005];
  int q[200005];

  rep(i, n)
  {
    cin >> p[i];
  }

  rep(i, n)
  {
    q[--p[i]] = i;
  }

  // rep(i, n)
  // {
  //   cout << q[i] << " ";
  // }
  // cout << endl;

  int left, right;
  left = right = 0;
  int tmp = q[0];
  int m = 0;

  while (right <= n - 1)
  {
    while (q[right + 1] > tmp && right <= n - 2)
    {
      right++;
      tmp = q[right];
    }
    // cout << left << right << endl;
    chmax(m, right - left);
    left = ++right;
    tmp = q[left];
  }

  cout << n - m - 1 << endl;
  return 0;
}
