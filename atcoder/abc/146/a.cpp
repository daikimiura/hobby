#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
long long MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  int ans;
  if (s == "SUN")
    ans = 7;
  else if (s == "MON")
    ans = 6;
  else if (s == "TUE")
    ans = 5;
  else if (s == "WED")
    ans = 4;
  else if (s == "THU")
    ans = 3;
  else if (s == "FRI")
    ans = 2;
  else if (s == "SAT")
    ans = 1;

  cout << ans << endl;
  return 0;
}
