class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    bool cf{false};
    int_fast8_t last(digits.size() - 1);

    do {
        if (digits[last] + 1 == 10) {
            cf = true;
            digits[last] = 0;
            --last;
            if(last == -1) {
                digits.insert(digits.begin(), 1);
            }
        } else {
            ++digits[last];
            cf = false;
        }
    } while (cf == true && last >= 0);

    return digits;
}
};