#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
// const long long INF = 1LL << 60;
int INF = 10000;
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

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  int ans[5000] = {};
  repi(i, 1, n)
  {
    repi(j, i+1, n+1) {
      int cost = min(j - i, abs(x - i) + 1 + abs(y - j));
      ans[cost]++;
    }
  }

  repi(i, 1, n)
  {
    cout << ans[i] << endl;
  }
  return 0;
}