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
  string original_s;
  cin >> original_s;
  string s = original_s;
  int ans = iINF;
  bool same = true;

  rep(i, s.size() - 1)
  {
    if (s[i] != s[i + 1])
      same = false;
  }

  if (same)
  {
    cout << 0 << endl;
    return 0;
  }

  rep(i, 26)
  {
    char tmp = 'a' + i;

    int tmp_ans = 0;

    bool ok = false;
    while (s.size() >= 1 || !ok)
    {
      rep(j, s.size() - 1)
      {
        if (s[j] == tmp || s[j + 1] == tmp)
        {
          s[j] = tmp;
        }
      }
      tmp_ans++;
      s = s.substr(0, s.size() - 1);

      ok = true;
      rep(j, s.size() - 1)
      {
        if (s[j] != s[j + 1])
          ok = false;
      }

      if (ok)
      {
        chmin(ans, tmp_ans);
      }
    }
    s = original_s;
  }

  cout << ans << endl;
  return 0;
}
