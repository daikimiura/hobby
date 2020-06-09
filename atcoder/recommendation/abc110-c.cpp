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
  string s, t;
  cin >> s >> t;

  char s_henkan[30], t_henkan[30];
  rep(i, 30)
  {
    s_henkan[i] = -1;
    t_henkan[i] = -1;
  }

  rep(i, s.size())
  {
    if (s_henkan[s[i] - 'a'] < 0)
    {
      s_henkan[s[i] - 'a'] = t[i];
    }
    else if (s_henkan[s[i] - 'a'] != t[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  rep(i, s.size())
  {
    if (t_henkan[t[i] - 'a'] < 0)
    {
      t_henkan[t[i] - 'a'] = s[i];
    }
    else if (t_henkan[t[i] - 'a'] != s[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
