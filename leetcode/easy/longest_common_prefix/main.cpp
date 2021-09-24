
/*
 * First string is a initial prefix, so if it is an empty string, we should
 * return it before even trying to loop over vector. Obviously, we should always
 * immidiately return "" in a first block of the loop, if the string is empty.
 * We also know from description that a vector will always have atleast 1
 * element, so we don't need to check if it is empty or something like this.
 *
 * Then, we have to check if current character with index n is equal to
 * character in current prefix string with same index. If no, we might want to
 * return current prefix. But it would fail, if an invalid character would be a
 * first character. So we can perform an if statement, that check if index of an
 * accessed character in string is equal 0 && char[0] != prefix[0]. In such a
 * case, return "";
 *
 * If character is valid, we may want to update our prefix, but it would be
 * waste of performance, since we would have to modify a variable on every loop.
 * Instead of this we can just do it once, when it will stop being valid.
 *
 * With the theory said, we can now consider a few cases.
 * 1.  ["flower","flow","flight"]
 * 2.  ["dog","racecar","car"]
 * 3.  ["ab", "a"]
 * 4.  ["flower","flower","flower","flower"]
 * 5.  ["aaa","aa","aaa"]
 * 6.  ["abab","aba",""]
 * 7.  ["baab","bacb","b","cbc"]
 *
 * 1 --> We start looping from 'flow', we finish loop with 'flow'
 *       so we have to change our current prefix to 'flow' and continue checks
 * on 'flight' From here we can see that something is not perfect. With every
 * loop, prefix can become shorter, so checks we performed before, may seem
 * redundant. We will have to remember about it and try to find a solution on
 * how to optimize it.
 *
 * 2 --> This one is pretty straightforward, we return "", because accessed
 *       character index is equal to 0 and it fails.
 *
 * 3 --> First loop was fine, 2nd
 *       one failed? No. Check wasn't even performed.
 *       So we  need to perform check on this too.
 *
 * 4 --> Everything is the same, prefix variable shouldn't be changed even once.
 *
 * 5 --> Here we most likely would return "aaa", because our checks would never
 * fail. Loop would omit last character in 2nd element of a vector. Simplest
 * solution is probably to just compare size of prefix and current element and
 * cut prefix if is longer.
 *
 * 6 --> As we can see string may be empty, so it fails on the first if
 * statement mentioned before.
 *
 * 7 --> We fail on second loop, we cut prefix to 'ba'. Than again we
 *       fail on 3rd loop, we fail and cut prefix to 'b'. Finally the first
 * character is invalid, so we return an empty string. We can again see a
 * situation mentioned in first example. A lot of redundant check, because
 * eventually prefix was cutted.
 *
 * Let's try to create this version and think about how to improve it later.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs[0] == "") {
        return "";
    }

    string prefix{strs[0]};

    for (int i{}; i < strs.size(); i++) {
        if (strs[i] == "") {
            cout << '\n';
            return "";
        }
        for (int j{}; j < strs[i].size(); j++) {
            // lazy comparison, we first check if it is first character
            // so we can possibly boost a performance a little bit.
            if ((j == 0) && strs[i][j] != prefix[j]) {
                cout << '\n';
                return "";
            }

            // 3,5 case
            if (strs[i].size() < prefix.size()) {
                prefix = prefix.substr(0, strs[i].size());
            }

            if (strs[i][j] != prefix[j]) {
                prefix = prefix.substr(0, j);
            }
        }
    }

    cout << prefix << '\n';

    return prefix;
};

int main() {
    vector<string> case1{"flower", "flow", "flight"};
    vector<string> case2{"dog", "racecar", "car"};
    vector<string> case3{"ab", "a"};
    vector<string> case4{"flower", "flower", "flower", "flower"};
    vector<string> case5{"aaa", "aa", "aaa"};
    vector<string> case6{"abab", "aba", ""};
    vector<string> case7{"baab", "bacb", "b", "cbc"};

    longestCommonPrefix(case1);
    longestCommonPrefix(case2);
    longestCommonPrefix(case3);
    longestCommonPrefix(case4);
    longestCommonPrefix(case5);
    longestCommonPrefix(case6);
    longestCommonPrefix(case7);

    return 0;
}
