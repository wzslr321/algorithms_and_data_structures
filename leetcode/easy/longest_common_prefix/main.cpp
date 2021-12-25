#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
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
      if ((j == 0) && strs[i][j] != prefix[j]) {
        cout << '\n';
        return "";
      }

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
