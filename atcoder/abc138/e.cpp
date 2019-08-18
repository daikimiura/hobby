#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int flag = 0;
  for (int i = 0; i < t.size(); i++) {
    for (int j = 0; j < s.size(); j++) {
      if (t[i] == s[j]) {
        flag += i;
        break;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < t.size(); i++) {
    sum += i;
  }

  if (sum != flag) {
    cout << -1 << endl;
    return 0;
  }

  int sikii = 0;
  int index = 0;

  int counter = 0;
  int j = 0;
  int i = 0;
  for (; i < t.size();) {
    for (; j < s.size(); j++) {
      if (t[i] == s[j]) {
        index = j + 1;
        i += 1;
        j += 1;
        break;
      }
      if (j == s.size() - 1) {
        sikii += 1;
        j = 0;
        break;
      }
    }
    if (i == t.size()) {
      break;
    }
  }

  cout << sikii * s.size() + index << endl;

  return 0;
}
