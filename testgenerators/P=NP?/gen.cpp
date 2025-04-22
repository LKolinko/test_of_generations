#include "testlib.h"
#include <vector>
#include <set>

constexpr int MAX_N = 100, MAX_Q = 100, MAX_E = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    for (int64_t i = atoi(argv[1]); i <= atoi(argv[2]); ++i) {
        startTest(i);

        int n = rnd.next(1, MAX_N);
        int q = rnd.next(1, MAX_Q);

        std::vector<int64_t> a(n);

        for (auto &u : a) {
            u = rnd.next(0, MAX_E);
        }

        std::cout << n << ' ' << q << std::endl;

        std::vector<bool> is_ban(n, false);

        int64_t cnt = rnd.next(1, std::min(n, 50));

        std::set<int64_t> st;
        for (int64_t i = 0; i < n; ++i) {
            st.insert(i);
        }

        while (cnt > 0) {
            int64_t pos = rnd.any(st);
            st.erase(pos);
            is_ban[pos] = true;
            --cnt;
        }

        for (int64_t i = 0; i < n; ++i) {
            if (is_ban[i]) {
                std::cout << '?';
            } else {
                std::cout << a[i];
            }
            if (i != n - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;

        std::vector<int64_t> pref_sum(n + 1, 0);
        for (int64_t i = 1; i <= n; ++i) {
            pref_sum[i] = pref_sum[i - 1] + a[i - 1];
        }

        while (q --> 0) {
            int64_t l = rnd.next(1, n), r = rnd.next(1, n);
            
            if (l > r) {
                std::swap(l, r);
            }
            
            std::cout << l << ' ' << r << ' ' << pref_sum[r] - pref_sum[l - 1] << std::endl;
        }

    }   

    return 0;
}
