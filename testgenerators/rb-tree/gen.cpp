#include "testlib.h"
#include <random>
#include <iostream>
#include <set>

constexpr int MAX = 1'000'000'000;

int main(int args, char* argv[]) {
    registerGen(args, argv, 1);

    for (int i = 2; i <= 50; ++i) {

        startTest(i);
        
        int q = rnd.next(1, 10000);

        std::cout << q << std::endl;

        std::set<int> st;

        while (q --> 0) {
            if (st.empty()) {
                int val = rnd.next(-MAX, MAX);
                while (st.find(val) != st.end()) {
                    val = rnd.next(-MAX, MAX);
                }
                std::cout << "+ " << val << std::endl;
                st.insert(val);
            } else {
                int f = rnd.next(0, 1);
                if (f == 0) {
                    int val = rnd.next(-MAX, MAX);
                    while (st.find(val) != st.end()) {
                        val = rnd.next(-MAX, MAX);
                    }
                    std::cout << "+ " << val << std::endl;
                    st.insert(val);
                } else {
                    int pos = rnd.next(0, static_cast<int>(st.size()) - 1), cnt = 0, val;
                    for (auto &u : st) {
                        if (cnt == pos) {
                            val = u;
                            break;
                        }
                        ++cnt;
                    }
                    std::cout << "- " << val << std::endl;
                    st.erase(val);
                }
            }
        }
    }
    return 0;
}