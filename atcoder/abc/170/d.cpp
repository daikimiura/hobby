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

  vector<int> a;
  bool is_ok[1000005] = {};

  rep(i, n)
  {
    int x;
    cin >> x;
    a.push_back(x);
    is_ok[x] = true;
  }

  sort(a.begin(), a.end());
  int ans = 0;
  int index = 0;

  for (auto i : a)
  {
    // cout << "===" << endl;
    // cout << i << endl;

    if (index <= a.size() - 2 && i == a[index + 1])
    {
      is_ok[i] = false;
      index++;
      continue;
    }

    for (int j = 2; j <= a[a.size() - 1] / i; j++)
    {
      // cout << "j: " << j << " " << i * j << endl;
      if (binary_search(a.begin(), a.end(), i * j))
      {
        int x = i * j;
        is_ok[x] = false;
      }
    }
    index++;
  }

  for (auto i : a)
  {
    if (is_ok[i])
    {
      // cout << i << endl;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
