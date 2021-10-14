// it fails when number is to big

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

string addBinary(string a, string b) {
    ll sum{};
    ll inc{1};

    for (int i(a.size() - 1); i >= 0; i--) {
        sum += (a[i] - '0') * inc;
        inc *= 2;
    }
    inc = 1;
    for (int i(b.size() - 1); i >= 0; i--) {
        sum += (b[i] - '0') * inc;
        inc *= 2;
    }

    if (sum == 0) return "0";

    string sbin;
    for (; sum > 0;) {
        sbin = (sum % 2 == 0 ? "0" : "1") + sbin;
        sum = sum / 2;
    }
    return sbin;
}

int main() {
    string a1 = "11";
    string b1 = "1";
    string a2 = "1010";
    string b2 = "1011";

    cout << addBinary(a1, b1) << '\n';
    cout << addBinary(a2, b2) << '\n';

    return 0;
}
