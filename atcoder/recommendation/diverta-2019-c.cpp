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
  int ans = 0;
  int head = 0, last = 0, both = 0;
  rep(i, n)
  {
    string s;
    cin >> s;
    rep(i, s.size() - 1)
    {
      if (s[i] == 'A' && s[i + 1] == 'B')
        ans++;
    }
    if (s[0] == 'B' && s[s.size() - 1] == 'A')
    {
      both++;
      continue;
    }

    if (s[0] == 'B')
      head++;

    if (s[s.size() - 1] == 'A')
      last++;
  }

  int mini = min(head, last);
  int maxi = max(head, last);

  ans += max(0, both - 1);
  if (both > 0 && mini > 0)
  {
    ans++;
    mini--;
  }

  if (both > 0 && maxi > 0)
  {
    ans++;
    maxi--;
  }

  ans += max(0, mini);

  cout << ans << endl;
  return 0;
}
