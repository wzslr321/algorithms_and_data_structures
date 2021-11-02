#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

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

int main() {
    assert((lengthOfLastWord("   fly me   to   the moon  "), 4));
    assert((lengthOfLastWord("Hello World"), 5));
    assert((lengthOfLastWord("a"), 1));
    assert((lengthOfLastWord("a "), 1));

    return 0;
}
