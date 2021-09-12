#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) {
        return strs[0];
    }

    string match{strs[0]};

    if (match.size() == 0) {
        return "";
    }

    // We got X strings in vector 
    // Let's say v = ["flower", "flow", "flight]
    // initially, match = v[0];
    // we start looping from v[1] element, and we loop by its every char
    // i {0};
    // check if v[1][i] == match[i]
    // if yes, continue 
    // if no,concatenate match  to 0,i and return it 

    return match;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << '\n';
    return 0;
}
