#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) {
        return strs[0];
    }

    string match{strs[0]};
    string cr{};

    if (match.size() == 0) {
        return "";
    }
    for (int i{1}; i < strs.size(); i++) {
        for (int j{}; j < strs[i].size(); j++) {
            if (strs[i][j] == match[j]) {
                if (strs[i][j + 1] == match[j + 1]) {
                    cr = match.substr(0, j + 1);
                    if (i == (strs.size() - 1) && j == (strs[i].size() - 1)) {
                        return cr;
                    }
                }
                if (j == 0) {
                    cr = match.substr(0, j + 1);
                } else {
                    cr = match.substr(0, j);
                }
            } else {
                cr = match.substr(0, j);
                return cr;
            }
        }
    }

    return cr;
}

int main() {
    // "ab, a"
    // "a, a, b"
    vector<string> strs = {"flower", "flower", "flower", "flower"};
    cout << longestCommonPrefix(strs) << '\n';
    return 0;
}
