#include "testlib.h"
#include <set>

constexpr int MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
    int q = inf.readInt(1, 10000, "n");
    
    std::set<int> st;

    inf.readEoln();
 
    for (int i = 0; i < q; ++i) {
        char flag = inf.readChar();
        inf.readSpace();
        int val = inf.readInt(-MAX, MAX, "val");
        if (flag == '+') {
            ensuref(st.find(val) == st.end(), "double addition");
            st.insert(val);
        } else if (flag == '-') {
            ensuref(st.find(val) != st.end(), "remove unadded element");
            st.erase(val);
        } else {
            ensuref(false, "flag is not + or -");
        }
        inf.readEoln();
    }
 
    inf.readEof();
 
    return 0;
}