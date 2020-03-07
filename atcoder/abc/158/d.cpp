#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long MOD = 1e9 + 7;
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
  string s;
  string bef = "";
  string af = "";
  cin >> s;
  int q;
  cin >> q;

  int state = 0; // 0 普通, 1 逆転

  rep(i, q)
  {
    int t, f;
    string c;
    
    cin >> t;
    if (t == 1)
    {
      state = 1 - state;
    }
    if (t == 2)
    {
      cin >> f >> c;
      if (state == 0)
      {
        if(f == 1) {
          bef = c + bef;
        } else {
          af = af + c;
        }
      } else {
        if (f == 1)
        {
          af = af + c;
          
        }
        else
        {
          bef = c + bef;
        }
      }
    }
  }

  if(state == 0) {
    cout << bef + s + af << endl;
  } else {
    string rev = bef + s + af;
    reverse(rev.begin(), rev.end());
    cout << rev << endl;
  }
  return 0;
}
