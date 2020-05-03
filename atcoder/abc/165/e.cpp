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
  int n, m;
  cin >> n >> m;
  bool done[1001000] = {};
  ll count = 0;
  ll i = 0;
  for (;;)
  {
    if (done[n - 2 * i - 1] || done[2 * i + 1])
    {
      i++;
      continue;
    }
    cout << i + 1 << " " << n - i << endl;
    done[n - 2*i - 1] = true;
    done[2 * i + 1] = true;
    i++;
    count++;
    if (count == m)
      break;
  }
  return 0;
}
