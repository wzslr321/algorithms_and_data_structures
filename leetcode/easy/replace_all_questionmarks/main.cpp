#include <iostream>

using namespace std;

string modifyString(string s) {
  for (auto i{0}; i < s.size(); i++) {
    if (s[i] == '?') {
      if (i < 1) {
        while (s[i] == '?' || s[i] == s[i + 1]) {
          s[i] = rand() % 25 + 97;
        }
      } else if (i > s.size() - 2) {
        while (s[i] == '?' || s[i] == s[i - 1]) {
          s[i] = rand() % 25 + 97;
        }
      } else {
        while (s[i] == '?' || s[i] == s[i - 1] || s[i] == s[i + 1]) {
          s[i] = rand() % 25 + 97;
        }
      }
    }
  }
  return s;
}

int main() {
  cout << modifyString("a?t");
  return 0;
}
