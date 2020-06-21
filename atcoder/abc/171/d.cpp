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
  int n, q;
  map<int, int> a;
  cin >> n;
  ll sum = 0;
  rep(i, n)
  {
    int x;
    cin >> x;
    a[x]++;
    sum += x;
  }
  cin >> q;

  rep(i, q)
  {
    int b, c;
    cin >> b >> c;

    int b_count = a[b];
    sum += (c - b) * b_count;
    cout << sum << endl;
    a[b] = 0;
    a[c] += b_count;
  }
  return 0;
}
