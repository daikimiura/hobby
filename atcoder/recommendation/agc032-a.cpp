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
  vector<int> b;
  rep(i, n)
  {
    int x;
    cin >> x;
    b.push_back(x);
  }

  vector<int> ans;
  for (;;)
  {
    int before_count = b.size();
    bool flag = true;
    for (int i = b.size() - 1; i >= 0; i--)
    {
      if (b[i] == i + 1 && flag)
      {
        b.erase(b.begin() + i);
        ans.insert(ans.begin(), i + 1);
        flag = false;
      }
    }
    int after_count = b.size();
    if (before_count == after_count)
      break;
  }

  if (b.size() == 0)
  {
    for (int i : ans)
    {
      cout << i << endl;
    }
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}
