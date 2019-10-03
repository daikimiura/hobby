#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
long long MOD = 1e9 + 7;
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<vector<int>> rec;
  char tmp = 'R';
  int count = 1;

  rep(i, s.size()) {
    if (tmp == s.at(i)) {
      count++;
    } else if (tmp == 'R' && s.at(i) == 'L') {
      tmp = 'L';
      count++;
      rec.push_back(vector<int>{i - 1, i});
    } else {
      rec.back().push_back(count);
      count = 1;
      tmp = 'R';
    }
  }

  int ans[s.size()];

  for (auto &p : rec) {
    ans[p[0]] = p[2];
    ans[p[1]] = p[2];
  }

  rep(i, s.size()) { cout << ans[i] << endl; }
  return 0;
}
