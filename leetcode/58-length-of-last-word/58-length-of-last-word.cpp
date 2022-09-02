class Solution {
public:
int lengthOfLastWord(string s) {
    int last{static_cast<int>(s.size() - 1)};
    int length{0};
    if (last - 1 < 0) {
        return s[0] == ' ' ? 0 : 1;
    }
    while (s[last] == ' ') {
        --last;
    }

    while ((last != -1) && (s[last] != ' ')) {
        --last;
        ++length;
    }

    return length;
}
};