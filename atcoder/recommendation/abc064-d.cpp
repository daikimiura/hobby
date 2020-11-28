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
  int n;
  string s, t;
  cin >> n >> s;

  t = s;

  bool all_deleted = false;
  while (!all_deleted)
  {
    bool deleted = false;
    rep(i, t.size() - 1)
    {
      if (t[i] == '(' && t[i + 1] == ')')
      {
        t.erase(i, 2);
        deleted = true;
        break;
      }
    }
    if (!deleted)
      all_deleted = true;
  }

  if (t.size() == 0)
  {
    cout << s << endl;
    return 0;
  }

  int r_count = 0;
  int l_count = 0;
  rep(i, t.size())
  {
    if (t[i] == '(')
      l_count++;
    else if (t[i] == ')')
      r_count++;
  }

  rep(i, r_count)
  {
    cout << '(';
  }

  cout << s;
  rep(i, l_count)
  {
    cout << ')';
  }

  cout << endl;
  return 0;
}
