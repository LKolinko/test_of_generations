#pragma GCC optimize("Ofast,unroll-loops,mfma,mavx,mavx2,fast-math")
#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double a;
    cin >> a;

    ll num = reinterpret_cast<ll&>(a);
    ll q;
    cin >> q;

    cout << scientific << setprecision(100);

    while (q --> 0) {
        ll x;
        cin >> x;
        num ^= (1ll << x);
        double res = reinterpret_cast<double&>(num);
        cout << res << '\n';
    }

    return 0;
}
