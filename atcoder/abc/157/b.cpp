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
  int a[3][3];
  rep(i, 3) {
    rep(j, 3) {
      int d;
      cin >> d;
      a[i][j] = d;
    }
  }

  int n;
  cin >> n;

  bool a2[3][3];

  rep(i, 3) {
    rep(j, 3) { a2[i][j] = false; }
  }

  rep(k, n) {
    int b;
    cin >> b;

    rep(i, 3) {
      rep(j, 3) {
        if (a[i][j] == b) {
          a2[i][j] = true;
        }
      };
    }
  }

  bool ans = false;

  rep(i, 3) {
    if (a2[i][0] == true && a2[i][1] == true && a2[i][2] == true) {
      ans = true;
    }
  }

  rep(i, 3) {
    if (a2[0][i] == true && a2[1][i] == true && a2[2][i] == true) {
      ans = true;
    }
  }

  if (a2[0][0] == true && a2[1][1] == true && a2[2][2] == true) {
    ans = true;
  }

  if (a2[0][2] == true && a2[1][1] == true && a2[2][0] == true) {
    ans = true;
  }

  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
