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
  vector<int> a, b;
  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;

  if (n % 2 == 1)
  {
    int a_mid = a[a.size() / 2];
    int b_mid = b[b.size() / 2];
    ans = b_mid - a_mid + 1;
  }
  else
  {
    int a_mid = a[a.size() / 2 - 1] + a[a.size() / 2];
    int b_mid = b[b.size() / 2 - 1] + b[b.size() / 2];
    ans = b_mid - a_mid + 1;
  }

  cout << ans << endl;

  return 0;
}
