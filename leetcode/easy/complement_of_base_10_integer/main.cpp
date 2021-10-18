#include <iostream>

using namespace std;

// ive got totally no clue what ive did here
// i hope i will figure it out some day and make it work...

int bitwiseComplement(int n) {
    auto zeros_l(__builtin_clz(n));
    auto zeros_r(__builtin_ctz(n));
    auto a = std::bitset<32>(n);

    string b = std::bitset<32>(~a.to_ulong()).to_string();

    int sum{0};

    for (int i{31 - zeros_r}; i > (32 - zeros_r) - (33 - zeros_l); i--) {
        if (b[i] == '1') {
            int result = (1 << (31 - zeros_r - i - 1));
            sum += result;
        }
    }

    return sum;
}

int main() {
    cout << bitwiseComplement(5) << '\n';   // 2
    cout << bitwiseComplement(7) << '\n';   // 0
    cout << bitwiseComplement(10) << '\n';  // 5;
    cout << bitwiseComplement(21) << '\n';  // 10;

    return 0;
}
