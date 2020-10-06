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

int main()
{
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a, b;

  rep(i, n)
  {
    int aa;
    cin >> aa;
    a.push_back(aa);
  }

  rep(i, m)
  {
    int bb;
    cin >> bb;
    b.push_back(bb);
  }

  char current = 'a';
  int time = 0, ans = 0;
  while (true)
  {
    if (current == 'a')
    {
      auto a_lb = lower_bound(a.begin(), a.end(), time);

      if (a_lb != a.end())
      {
        time = *a_lb + x;
        current = 'b';
        continue;
      }
      else
      {
        break;
      };
    }
    else
    {
      auto b_lb = lower_bound(b.begin(), b.end(), time);
      if (b_lb != b.end())
      {
        time = *b_lb + y;
        current = 'a';
        ans++;
      }
      else
      {
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
