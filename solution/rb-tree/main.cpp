#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll q;
    cin >> q;
    set<ll> st;
    while (q --> 0) {
        char c;
        ll val;
        cin >> c >> val;
        if (c == '+') {
            st.insert(val);
        } else {
            st.erase(val);
        }
        for (auto &u : st) {
            cout << u << ' ';
        }
        cout << '\n';
    }
    return 0;
}