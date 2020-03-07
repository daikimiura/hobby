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
  int N,P;
  string S;
  cin >> N >> P >> S;
  long long res = 0;
  int right = 0;
  set<char> member;
  for (int left = 0; left < N; ++left)
  {
    while (right < N && !member.count(S[right]))
    {
      member.insert(S[right]);
      ++right;
    }
    res += right - left;
    if (left == right)
      ++right;
    else
      member.erase(S[left]); // a[left] を削除
  }
  cout << res << endl;
}
