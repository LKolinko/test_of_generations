#include "testlib.h"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int flag = atoi(argv[5]);

    int l = atoi(argv[3]), r = atoi(argv[4]); 

    std::cout << std::fixed << std::setprecision(10);

    for (int i = atoi(argv[1]); i <= atoi(argv[2]); ++i) {
        startTest(i);
        
        double num = rnd.next(-1e9, 1e9);

        int64_t tmp = reinterpret_cast<int64_t&>(num);

        int q = rnd.next(l, r);

        if (flag == 1) {
            q = 1e5;
        }

        std::cout << num << std::endl;
        std::cout << q << std::endl;

        for (int j = 0; j < q; ++j) {
            int pos = rnd.next(0, 63);
            while (true) {
                tmp ^= (1ll << pos);
                if (std::isnan(reinterpret_cast<double&>(tmp))) {
                    tmp ^= (1ll << pos);
                    pos = rnd.next(0, 63);
                    continue;
                } else {
                    break;
                }
            }
            std::cout << pos << std::endl;
        }
    }

    return 0;
}