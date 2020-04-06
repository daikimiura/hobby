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
  int n;
  cin >> n;
  int p = 0;
  int q = 0;
  vector<int> vec;
  rep(i, n)
  {
    int x;
    cin >> x;
    p += x * pow(10, (n - i - 1));
    vec.push_back(i + 1);
  }

  rep(i, n)
  {
    int x;
    cin >> x;
    q += x * pow(10, (n - i - 1));
  }

  vector<int> perms;

  do
  {
    int tmp = 0;
    rep(i, n)
    {
      tmp += vec[i] * pow(10, (n - i - 1));
    }
    perms.push_back(tmp);
  } while (next_permutation(vec.begin(), vec.end()));

  sort(perms.begin(), perms.end());

  int a = find(perms.begin(), perms.end(), p) - vec.begin();
  int b = find(perms.begin(), perms.end(), q) - vec.begin();
  cout << abs(a - b) << endl;
  return 0;
}
