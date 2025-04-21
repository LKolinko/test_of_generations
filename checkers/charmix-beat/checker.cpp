#include "testlib.h"
#include <cmath>
#include <iostream>

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    while (!ans.eof() && !ouf.eof()) {
        std::string jury_ans = ans.readString();
        std::string user_ans = ouf.readString();

        double jury = std::stod(jury_ans);
        double user = std::stod(user_ans);

        if (abs(jury - user) > 1e-6) {
            quitf(_wa, "Absolute error too big: |%lf - %lf|", jury, user);
        }
    }

    if (!ans.eof() || !ouf.eof()) {
        quitf(_wa, "Files have different lengths.");
    }

    quitf(_ok, "Accepted");
    return 0;
}
