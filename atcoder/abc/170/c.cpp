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
  int x, n;
  cin >> x >> n;

  if (n == 0)
  {
    cout << x << endl;
    return 0;
  }

  vector<int> p;
  rep(i, n)
  {
    int x;
    cin >> x;
    p.push_back(x);
  }

  sort(p.begin(), p.end());

  int min = p[0] - 1;
  int max = p[p.size() - 1] + 1;
  int min_abs = iINF;
  int ans = 0;

  repi(i, min, max + 1)
  {
    if (!binary_search(p.begin(), p.end(), i))
    {
      int tmp_abs = abs(x - i);
      if (tmp_abs < min_abs)
      {
        ans = i;
        min_abs = tmp_abs;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
