#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long MOD = 1e9 + 7;
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
  int a, b;
  cin >> a >> b;

  int ans_a, ans_a_max;
  ans_a = ceil(a * (1 / 0.08));
  ans_a_max = ceil((a + 0.9) * (1 / 0.08));
  int ans_b, ans_b_max;
  ans_b = ceil(b * (1 / 0.1));
  ans_b_max = ceil((b + 0.9) * (1 / 0.1));

  int ans = max(ans_a, ans_b);

  if (ans == ans_a)
  {
    if (ans_b_max > ans)
    {
      cout << ans << endl;
      return 0;
    };
  }
  else
  {
    if (ans_a_max > ans)
    {
      cout << ans << endl;
      return 0;
    }
  }

  cout << "-1" << endl;
  return 0;
}
