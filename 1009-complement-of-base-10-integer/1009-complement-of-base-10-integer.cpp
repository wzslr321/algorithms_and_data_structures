class Solution {
public:
int bitwiseComplement(int n) {
    if (n == 0) return 1;
    auto zeros_l(__builtin_clz(n));
    auto zeros_r(__builtin_ctz(n));

    string b = std::bitset<32>(~n).to_string();

    auto sum{0};

    for (auto i{32 - 1}, j{0}; i > (32 - (32 - zeros_l)); --i, ++j) {
        if (b[i] == '1') {
            sum += (1 << j);
        }
    }

    return sum;
}
};