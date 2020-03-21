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
    while (true)
    {
        int n, x;
        cin >> n >> x;
        if (n == 0 && x == 0)
            break;

        int ans = 0;
        repi(i, 1, n + 1) repi(j, i + 1, n + 1) repi(k, j + 1, n + 1)
        {
            if (i + j + k == x)
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
