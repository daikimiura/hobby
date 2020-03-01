#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
typedef long long ll;
long long MOD = 1e9 + 7;
const long long INF = 1LL << 60;
using namespace std;

template <class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> a;
  vector<int> tmp_wa;

  rep(i, n + 1) {
    a.push_back(false);
    tmp_wa.push_back(0);
  }

  int ac = 0;
  int wa = 0;

  rep(i, m) {
    int p;
    string s;

    cin >> p >> s;

    if (a[p] == false) {
      if (s == "AC") {
        ac++;
        wa += tmp_wa[p];
        a[p] = true;
      } else {
        tmp_wa[p]++;
      }
    }
  }

  cout << ac << " " << wa << endl;
  return 0;
}
