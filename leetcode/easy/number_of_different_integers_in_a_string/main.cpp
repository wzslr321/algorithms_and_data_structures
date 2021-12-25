#include <iostream>
#include <unordered_map>

using namespace std;

// yes I am fully aware that it is awful.

int numDifferentIntegers(string word) {
  int count{0};
  unordered_map<string, bool> m{};
  for (auto i{0}; i < word.size(); i++) {
    if (isdigit(word[i])) {
      string current_num{word[i]};
      while (isdigit(word[i + 1])) {
        current_num += word[i + 1];
        ++i;
      }
      for (auto j{0}; j < current_num.size(); j++) {
        if (current_num[j] == '0') {
          current_num.erase(0, 1);
          --j;
        } else {
          break;
        }
      }
      if (m[current_num]) {
        continue;
      }
      m[current_num] = true;
      ++count;
    }
  }
  return count;
}

int main() {
  cout << numDifferentIntegers("a1b01c001");

  return 0;
}
