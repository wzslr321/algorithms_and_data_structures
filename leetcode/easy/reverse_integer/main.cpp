#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int reverse(int x) {
    int low_int{1 << 31};
    // i tried to overflow integer, so I can turn low_int
    // into max_int by shifring only one byte left, but I couldn't figure it out
    // or maybe compiler didn't let me.
    int max_int{(low_int << 1) + (low_int * (-1)) - 1};

    if (x < low_int || x > max_int) return 0;

    int rv_int{};
    int l{1};
    int lp{0};

    // lets assume our number is 321
    // on first loop we want to modulo it by 10
    // 321 % 10 =  1
    // we don't multiply it, we just divide our num by 10
    // second loop
    // 32 % 10 = 2
    // now we need to multiply all of our previous values by 10 
    // so we get 10 and still 2
    // we add it together so we get 12 
    // third loop
    // 3 % 10 = 3
    // as before, all previous values we multiply by 10 
    // so we get 100, 20 and 3 
    // we add them together and we have 123 
    // 3 / 10  is less than 0, so we finish
    

    // trying to implement it right now, though I'm a lil stuck 
    if (x > 0) {
        while (x > 0) {
            cout << x << '\n';
            cout << (x % 10) << '\n';
            if (lp > 0) {
                rv_int *= l;
            }
            lp++;
            l *= 10;
            rv_int += (x % 10);
            x /= 10;
        }
    }
    while (x < 0) {
        rv_int *= l;
        rv_int += (x % 10);
        x /= 10;
        l *= 10;
    }

    return rv_int;
}

int main() {
    cout << reverse(321);
    return 0;
}
