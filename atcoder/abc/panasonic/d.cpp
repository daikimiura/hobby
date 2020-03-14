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

int n;

void dfs(string s, char mx)
{
  if(s.length() == n){
    cout << s << endl;
  }else {
    for (char c = 'a'; c <= mx; c++){
      dfs(s + c, ((c == mx) ? (char)(mx + 1) : mx));
    }
  }
}

int main()
{
  cin >> n;
  dfs("", 'a');
  return 0;
}
