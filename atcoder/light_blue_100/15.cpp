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
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    rep(i, n)
    {
        cin >> b[i];
    }

    rep(i, n)
    {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll ans = 0;

    rep(i, n)
    {
        ll a_num = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll c_num = c.end() - upper_bound(c.begin(), c.end(), b[i]);

        ans += a_num * c_num;
    }

    cout << ans << endl;

    return 0;
}
