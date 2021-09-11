#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
    int low_int{(1 << 31)};
    int max_int{(low_int + 1) * (-1)};

    if (x <= low_int || x >= max_int) return 0;

    int rv_int{0};
    int l{10};
    int lp{0};
    if (x > 0) {
        while (x > 0) {
            if (lp == 0) {
                rv_int += (x % 10);
                x /= 10;
                lp++;

            } else {
                auto rvm{rv_int * l};

                if (rvm < ) {
                    return 0;
                }
                rv_int *= l;
                rv_int += (x % 10);
                x /= 10;
            }
        }
    }

    if (x < 0) {
        while (x < 0) {
            if (lp == 0) {
                rv_int += (x % 10);
                x /= 10;
                lp++;
            } else {
                auto rvm{rv_int * l};
                if (rvm > 0) {
                    return 0;
                }
                rv_int *= l;
                rv_int += (x % 10);
                x /= 10;
            }
        }
    }

    return rv_int;
}

int main() {
    // -1563847412
    cout << reverse(-1563847412) << '\n';
    return 0;
}
