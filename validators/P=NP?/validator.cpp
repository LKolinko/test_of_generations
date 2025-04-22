#include "testlib.h"

constexpr int64_t MAX_N = 100, MAX_Q = 100, MAX_E = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int64_t n, q;

    n = inf.readInt(1, MAX_N);
    inf.readSpace();
    q = inf.readInt(1, MAX_Q);
    
    inf.readEoln();

    for (int64_t i = 0; i < n; ++i) {
        std::string elem = inf.readToken();
        if (i + 1 != n) {
            inf.readSpace();
        }
    }

    inf.readEoln();

    for (int64_t i = 0; i < q; ++i) {
        int64_t l, r, x;
        l = inf.readInt(1, n);
        inf.readSpace();
        r = inf.readInt(l, n);
        inf.readSpace();
        x = inf.readLong();
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
