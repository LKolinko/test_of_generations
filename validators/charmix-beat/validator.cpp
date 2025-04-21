#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    double num = inf.readDouble(-1e9, 1e9, "num");
    inf.readEoln();
    int q = inf.readInt(1, 1'000'000, "q");
    inf.readEoln();

    int64_t tmp = reinterpret_cast<int64_t&>(num);

    while (q --> 0) {
        int pos = inf.readInt(0, 63, "pos");
        tmp ^= (1ll << pos);
        ensuref(!std::isinf(reinterpret_cast<double&>(tmp)), "invalid qw");
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}
