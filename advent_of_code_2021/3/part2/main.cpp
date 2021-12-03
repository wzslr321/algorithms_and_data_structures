#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

void scan(const std::vector<std::string> &data, std::string &filter) {
  for (int i{0}; i <= filter.size(); ++i) {
    int ones = 0;
    int zeros = 0;
    std::vector<std::string> matches;
    for (int j{0}; j < data.size(); ++j) {
      bool invalid = false;
      for (int y = 0; y < filter.size(); ++y) {
        if (data[j][y] != filter[y]) {
          invalid = true;
          break;
        }
      }
      if (invalid) continue;
      matches.push_back(data[j]);
      if (data[j][i] == '1')
        ++ones;
      else
        ++zeros;
    }
    if (matches.size() == 1) return;
    if (ones >= zeros)
      filter.push_back('1');
    else
      filter.push_back('0');
  }
}
auto main() -> int {
  std::vector<std::string> data;
  while (std::cin) {
    std::string s;
    std::cin >> s;
    if (s == "1") break;
    data.push_back(s);
  }

  std::string filter = "";

  scan(data, filter);

  std::cout << filter << '\n';

  return 0;
}
