#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int64_t n, q;

    n = inf.readInt();
    inf.readSpace();
    q = inf.readInt();
    
    inf.readEoln();

    for (int64_t i = 0; i < n; ++i) {
        std::string elem = inf.readToken();
        if (i + 1 != n) {
            inf.readSpace();
        }
    }

    inf.readEoln();

    std::vector<long long> input = ouf.readLongs(n);

    std::vector<int64_t> pref(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + input[i - 1];
    }

    int cnt = 0;

    for (int64_t i = 0; i < q; ++i) {
        int64_t l, r, x;
        l = inf.readInt(1, n);
        inf.readSpace();
        r = inf.readInt(l, n);
        inf.readSpace();
        x = inf.readLong();
        inf.readEoln();

        if (pref[r] - pref[l - 1] == x) {
            ++cnt;
        }
    }

    quitp(((double)cnt / (double)(q)) * 10.0, "res");

    inf.readEof();

    return 0;
}