#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long mod = 1e9 + 7;
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
  int n, m;
  int sum = 0;
  cin >> n >> m;
  vector<int> a;
  rep(i, n)
  {
    int x;
    cin >> x;
    a.push_back(x);
    sum += x;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  rep(i, m)
  {
    if (a[i] * 4 * m < sum)
    {
      cout << "No" << endl;
      return 0;
    }
  }

    cout << "Yes" << endl;
  return 0;
}
