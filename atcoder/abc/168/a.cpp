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
  switch (n % 10)
  {
  case 2:
  case 4:
  case 5:
  case 7:
  case 9:
    cout << "hon" << endl;
    break;
  case 0:
  case 1:
  case 6:
  case 8:
    cout << "pon" << endl;
    break;
  case 3:
    cout << "bon" << endl;
    break;
  default:
    break;
  }
  return 0;
}
